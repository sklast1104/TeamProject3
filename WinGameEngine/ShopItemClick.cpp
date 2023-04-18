#include "stdafx.h"
#include "ShopItemClick.h"
#include "DivUI.h"
#include "GameMgr.h"
#include "ImageModule.h"
#include "CItem.h"
#include "CInvItem.h"
#include "TextModule.h"
#include "SceneMgr.h"
#include "Scene_Shop.h"
#include "ResMgr.h"
#include "Sound.h"

ShopItemClick::ShopItemClick(DivUI* _myItem, DivUI* _invPanel, int _itemCost)
	: invPanel{_invPanel}, myItem{_myItem}
	, mgr{GameMgr::GetInst()}, itemCost{_itemCost}
	, scene{ (Scene_Shop*)SceneMgr::GetInst()->GetCurScene() }
{
}

ShopItemClick::~ShopItemClick()
{
}

void ShopItemClick::sellShopItem()
{
	const vector<CInvItem*>& shopItems = scene->GetShopItems();

	CInvItem* shopItem = nullptr;

	for (int i = 0; i < shopItems.size(); i++) {
		if (shopItems[i]->GetName() == myItem->GetIModule()->GetResourceKey()) {
			shopItem = shopItems[i];
		}
	}

	if (shopItem->GetCurCount() > 0) {
		shopItem->SetCurCount(shopItem->GetCurCount() - 1);
		
		if (shopItem->GetCurCount() == 0) {
			DivUI* itContainer = (DivUI*)(myItem->GetParent());
			itContainer->SetCanRend(false);
			myItem->CanTarget(false);
		}
		else {
			// ���⼭ ����������
			DivUI* foodCount = (DivUI*)(myItem->GetChildUI()[0]);
			foodCount->GetTModule()->SetText(to_wstring(shopItem->GetCurCount()));
		}

	}
}

void ShopItemClick::Execute()
{
	ResMgr::GetInst()->LoadSound(L"buySound", L"resource\\sound\\UI\\ui_town\\ui_town_buy {e76da876-f6d8-4128-865f-933de737d4cd}.wav");
	Sound* downSound = ResMgr::GetInst()->FindSound(L"buySound");

	downSound->SetVolume(30.f);
	downSound->Play(false);

	// Ŭ���� �������� �������� ������ ��
	if (mgr->GetMoney() >= itemCost) {

		// �θ� �����̳ʷκ��� Text Container ã��

		sellShopItem();


		// ���ӸŴ��� & bottom_nav ������Ʈ

		mgr->SetMoney(mgr->GetMoney() - itemCost);
		DivUI* pseudoUI = scene->GetPseudoUI();

		DivUI* bottomNav = (DivUI*)FindUIByName(pseudoUI, L"bottom_nav");
		bottomNav->updateValue();
		
		//

		// Ŭ���� ���� �������� ���ҽ� Ű
		wstring key = myItem->GetIModule()->GetResourceKey();
		wstring path = myItem->GetIModule()->GetRelativePath();

		array<CItem*, 16>& inventory = mgr->GetInventory();

		for (int i = 0; i < 16; i++) {

			CItem* item = inventory[i];

			// �󽽷Ժ��� ���� üũ
			if (nullptr == item) {

				mgr->CreateItem(key, i);
				break;
			}
			// �������� �ִ� �����̶�� ���� ���� ���������� ���ؾ���
			else {

				// �������� �ִµ� �������� Ŭ���� �������̶� ���� ���
				if (inventory[i]->GetName() == key) {

					// ���� ������ �������� �ִ� �������� ���ٸ�
					if (inventory[i]->GetCurCount() < inventory[i]->GetMaxCount()) {
						// ī��Ʈ�� �ϳ� �÷��ش�
						inventory[i]->SetCurCount(inventory[i]->GetCurCount() + 1);
						break;
					}
				}
			}
		}

		// �������Ǵ� ������ ����
		vector<UI*> itemSlots = invPanel->GetChildUI();

		// �κ��丮 ������ ����ȭ
		for (int i = 0; i < 16; i++) {

			if (nullptr != inventory[i]) {
				// ������ ���� �ڽ����� invCount�� ����
				DivUI* itemSlot = (DivUI*)itemSlots[i];
				itemSlot->InitImageModule(inventory[i]->GetName(), inventory[i]->GetPath());
				itemSlot->CanTarget(true);
				itemSlot->SetCanRend(true);
				

				// �������� 2�� �̻� �ִٸ�
				if (inventory[i]->GetCurCount() >= 2) {
					DivUI* invCount = (DivUI*)(itemSlot->GetChildUI()[0]);
					invCount->GetTModule()->SetText(to_wstring(inventory[i]->GetCurCount()));
					invCount->SetCanRend(true);
				}
				else {
					DivUI* invCount = (DivUI*)(itemSlot->GetChildUI()[0]);
					invCount->SetCanRend(false);
				}
			}
		}
	}

}
