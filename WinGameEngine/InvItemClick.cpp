#include "stdafx.h"
#include "InvItemClick.h"
#include "SceneMgr.h"
#include "Scene_Shop.h"
#include "CInvItem.h"
#include "DivUI.h"
#include "ImageModule.h"
#include "TextModule.h"
#include "GameMgr.h"

InvItemClick::InvItemClick(DivUI* _myItem, int _index)
	: scene{ (Scene_Shop*)SceneMgr::GetInst()->GetCurScene() }
	, myItem{ _myItem }, mgr{GameMgr::GetInst()}, index{_index}
{
}

void InvItemClick::Execute()
{
	// Ŭ���̸� ������ �Ⱦƾ� �ϴ� ����
	// �� �̹��� Ű�� �˻��ؼ� ������ �̹��� Ű�� ������
	// ���� ������ ī��Ʈ�� �ø� ���� ī��Ʈ 0�̸� CanTarget�̶� ���������� ����� �� ���� ����

	// �κ��丮 ����ȭ

	array<CItem*, 16>& inventory = mgr->GetInventory();

	CItem* curClicked = inventory[index];

	if (nullptr == curClicked) return;

	curClicked->SetCurCount(curClicked->GetCurCount() - 1);

	int itemCount = curClicked->GetCurCount();
	wstring itemName = curClicked->GetName();
	int itemCost = ((CInvItem*)curClicked)->GetCost();

	DivUI* invCount = (DivUI*)(myItem->GetChildUI()[0]);
	invCount->GetTModule()->SetText(to_wstring(curClicked->GetCurCount()));
	
	if (itemCount == 0) {
		mgr->RemoveItem(index);
	}

	// �κ��丮 ������
	if (itemCount == 0) {

		myItem->SetCanRend(false);
		myItem->CanTarget(true);
	}

	// ���ӸŴ��� & bottom_nav ������Ʈ

	mgr->SetMoney(mgr->GetMoney() + itemCost);
	DivUI* pseudoUI = scene->GetPseudoUI();

	DivUI* bottomNav = (DivUI*)FindUIByName(pseudoUI, L"bottom_nav");
	bottomNav->updateValue();

	// ���� ����ȭ
	const vector<CInvItem*>& shopItems = scene->GetShopItems();

	CInvItem* shopItem = nullptr;

	for (int i = 0; i < shopItems.size(); i++) {
		if (shopItems[i]->GetName() == myItem->GetIModule()->GetResourceKey()) {
			shopItem = shopItems[i];
		}
	}

	shopItem->SetCurCount(shopItem->GetCurCount() + 1);
	
	// ���� ������
	DivUI* shopContainer = (DivUI*)FindUIByName(scene->GetPseudoUI(), L"ShopItem_Container");
	
	for (int i = 0; i < 9; i++) {
		DivUI* rendShopItem = (DivUI*)(shopContainer->GetChildUI()[i]);
		DivUI* foodIt = (DivUI*)(rendShopItem->GetChildUI()[0]);
		DivUI* foodCount = (DivUI*)(foodIt->GetChildUI()[0]);

		wstring key = foodIt->GetIModule()->GetResourceKey();

		if (key == itemName) {
			rendShopItem->CanTarget(true);
			rendShopItem->SetCanRend(true);

			foodCount->GetTModule()->SetText(to_wstring(shopItem->GetCurCount()));
		}
	}

	int a = 3;

	
}
