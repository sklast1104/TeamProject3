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
	// 클릭이면 무조건 팔아야 하는 로직
	// 내 이미지 키를 검사해서 상점의 이미지 키와 같으면
	// 상점 아이템 카운트를 늘림 만약 카운트 0이면 CanTarget이랑 렌더러까지 켜줘야 할 수도 있음

	// 인벤토리 동기화

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

	// 인벤토리 렌더링
	if (itemCount == 0) {

		myItem->SetCanRend(false);
		myItem->CanTarget(true);
	}

	// 게임매니저 & bottom_nav 업데이트

	mgr->SetMoney(mgr->GetMoney() + itemCost);
	DivUI* pseudoUI = scene->GetPseudoUI();

	DivUI* bottomNav = (DivUI*)FindUIByName(pseudoUI, L"bottom_nav");
	bottomNav->updateValue();

	// 상점 동기화
	const vector<CInvItem*>& shopItems = scene->GetShopItems();

	CInvItem* shopItem = nullptr;

	for (int i = 0; i < shopItems.size(); i++) {
		if (shopItems[i]->GetName() == myItem->GetIModule()->GetResourceKey()) {
			shopItem = shopItems[i];
		}
	}

	shopItem->SetCurCount(shopItem->GetCurCount() + 1);
	
	// 상점 렌더링
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
