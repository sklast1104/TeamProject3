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
			// 여기서 렌더링까지
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

	// 클릭한 순간부터 아이템이 사져도 됨
	if (mgr->GetMoney() >= itemCost) {

		// 부모 컨테이너로부터 Text Container 찾기

		sellShopItem();


		// 게임매니저 & bottom_nav 업데이트

		mgr->SetMoney(mgr->GetMoney() - itemCost);
		DivUI* pseudoUI = scene->GetPseudoUI();

		DivUI* bottomNav = (DivUI*)FindUIByName(pseudoUI, L"bottom_nav");
		bottomNav->updateValue();
		
		//

		// 클릭한 상점 아이템의 리소스 키
		wstring key = myItem->GetIModule()->GetResourceKey();
		wstring path = myItem->GetIModule()->GetRelativePath();

		array<CItem*, 16>& inventory = mgr->GetInventory();

		for (int i = 0; i < 16; i++) {

			CItem* item = inventory[i];

			// 빈슬롯부터 먼저 체크
			if (nullptr == item) {

				mgr->CreateItem(key, i);
				break;
			}
			// 아이템이 있는 슬롯이라면 나랑 같은 아이템인지 비교해야함
			else {

				// 아이템이 있는데 상점에서 클릭한 아이템이랑 같은 경우
				if (inventory[i]->GetName() == key) {

					// 현재 개수가 아이템의 최대 개수보다 적다면
					if (inventory[i]->GetCurCount() < inventory[i]->GetMaxCount()) {
						// 카운트만 하나 늘려준다
						inventory[i]->SetCurCount(inventory[i]->GetCurCount() + 1);
						break;
					}
				}
			}
		}

		// 렌더링되는 아이템 슬롯
		vector<UI*> itemSlots = invPanel->GetChildUI();

		// 인벤토리 렌더링 동기화
		for (int i = 0; i < 16; i++) {

			if (nullptr != inventory[i]) {
				// 아이템 슬롯 자식으로 invCount도 있음
				DivUI* itemSlot = (DivUI*)itemSlots[i];
				itemSlot->InitImageModule(inventory[i]->GetName(), inventory[i]->GetPath());
				itemSlot->CanTarget(true);
				itemSlot->SetCanRend(true);
				

				// 아이템이 2개 이상 있다면
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
