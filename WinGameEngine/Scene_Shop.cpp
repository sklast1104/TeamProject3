#include "stdafx.h"
#include "Scene_Shop.h"
#include "Core.h"
#include "DivUI.h"
#include "UIMgr.h"
#include "Camera.h"
#include "UIFactory.h"
#include "CInvItem.h"
#include "KeyMgr.h"
#include "ShopItemClick.h"
#include "ShopInvUpdateVal.h"
#include "ShopItemOver.h"
#include "ShopItemOut.h"
#include "GameMgr.h"

Scene_Shop::Scene_Shop()
	: dragRenderer{nullptr}
{
}

Scene_Shop::~Scene_Shop()
{
	Safe_Delete_Vec(shopItems);
}

void Scene_Shop::InitShopItems()
{
	CInvItem* food = new CInvItem(L"food");
	food->SetCurCount(24);

	shopItems.push_back(food);

	CInvItem* shovel = new CInvItem(L"shovel");
	shovel->SetCurCount(6);

	shopItems.push_back(shovel);

	CInvItem* antidote = new CInvItem(L"antidote");
	antidote->SetCurCount(9);

	shopItems.push_back(antidote);

	CInvItem* band = new CInvItem(L"band");
	band->SetCurCount(9);

	shopItems.push_back(band);

	CInvItem* herb = new CInvItem(L"herb");
	herb->SetCurCount(9);

	shopItems.push_back(herb);

	CInvItem* key = new CInvItem(L"key");
	key->SetCurCount(9);

	shopItems.push_back(key);

	CInvItem* holyWater = new CInvItem(L"holyWater");
	holyWater->SetCurCount(9);

	shopItems.push_back(holyWater);

	CInvItem* anum = new CInvItem(L"anum");
	anum->SetCurCount(9);

	shopItems.push_back(anum);

	CInvItem* torch = new CInvItem(L"torch");
	torch->SetCurCount(24);

	shopItems.push_back(torch);
}

void Scene_Shop::Enter()
{
	InitShopItems();

	// 드래그 되는 인벤토리용 오브젝트
	itemDragger = new DivUI;
	itemDragger->SetScale(Vec2(72.f, 144.f));
	itemDragger->SetPos(Vec2(960.f, 540.f));
	itemDragger->SetName(L"itemDragger");
	itemDragger->CanTarget(false);
	itemDragger->SetCanRend(false);

	// 드래그 되는 오브젝트
	dragRenderer = new DivUI;
	dragRenderer->SetScale(Vec2(68.f, 68.f));
	dragRenderer->SetPos(Vec2(960.f, 540.f));
	dragRenderer->CanTarget(false);

	Vec2 vResolution = Core::GetInst()->GetResolution();

	pseudoUI = new DivUI;
	pseudoUI->SetScale(vResolution);
	pseudoUI->SetPos(Vec2(0.f, 0.f));
	pseudoUI->CanTarget(false);

	DivUI* bg = new DivUI;
	bg->SetScale(vResolution);
	bg->SetPos(Vec2(0.f, 0.f));
	bg->CanTarget(false);
	bg->InitImageModule(L"Darkest_Shop_bg", L"resource\\Background\\shop\\provision.background.png");

	pseudoUI->AddChild(bg);

	// 타이틀
	DivUI* estateTitle = UIFactory::CreateTitle();

	pseudoUI->AddChild(estateTitle);

#pragma region Shop_panel

	DivUI* shopPanel = new DivUI;
	shopPanel->SetScale(Vec2(1395.f, 776.f));
	shopPanel->SetPos(Vec2(150.f, 130.f));
	shopPanel->InitImageModule(L"Shop_Panel_bg", L"resource\\Background\\shop\\provision.character_background.png");
	shopPanel->CanTarget(false);

	pseudoUI->AddChild(shopPanel);

	DivUI* shopPortrait = new DivUI;
	shopPortrait->SetScale(Vec2(811.f, 757.f));
	shopPortrait->SetPos(Vec2(0.f, 100.f));
	shopPortrait->InitImageModule(L"Shop_panel_portrait", L"resource\\Background\\shop\\provision.character.png");
	shopPortrait->CanTarget(false);

	shopPanel->AddChild(shopPortrait);

	DivUI* shopIcon = new DivUI;
	shopIcon->SetScale(Vec2(113.f, 113.f));
	shopIcon->SetPos(Vec2(20.f, 20.f));
	shopIcon->InitImageModule(L"Shop_Icon", L"resource\\Background\\shop\\provision.icon.png");

	shopPanel->AddChild(shopIcon);

	DivUI* shopText = new DivUI;
	shopText->SetScale(Vec2(300.f, 113.f));
	shopText->SetPos(Vec2(140.f, 20.f));
	shopText->InitTextModule(L"원정 준비", 40);
	shopText->SetFormat(DT_LEFT | DT_VCENTER | DT_SINGLELINE);
	shopText->SetTextColor(200, 180, 110);

	shopPanel->AddChild(shopText);
	
	DivUI* siContainer = new DivUI;
	siContainer->SetScale(Vec2(576.f, 356.f));
	siContainer->SetPos(Vec2(790.f, 35.f));
	siContainer->CanTarget(false);
	siContainer->SetName(L"ShopItem_Container");

	shopPanel->AddChild(siContainer);

	DivUI* shopInvText = new DivUI;
	shopInvText->SetPos(Vec2(880.f, 400.f));
	shopInvText->SetScale(Vec2(300.f, 20.f));
	shopInvText->InitTextModule(L"소지품을 [클릭]하여 되팔기", 20);
	shopInvText->SetTextColor(93, 90, 80);

	shopPanel->AddChild(shopInvText);

#pragma region ShopInv

	// 원정 인벤토리 패널
	DivUI* shopInvPanel = new DivUI;
	shopInvPanel->SetScale(Vec2(720.f, 360.f));
	shopInvPanel->SetPos(Vec2(660.f, 420.f));
	shopInvPanel->InitImageModule(L"shop_inv_panel", L"resource\\Background\\shop\\inventory_grid_background_party.png");
	shopInvPanel->CanTarget(false);
	shopInvPanel->SetName(L"shopInvPanel");
	shopInvPanel->InitUpdateValue(new ShopInvUpdateVal(shopInvPanel));
	
	shopPanel->AddChild(shopInvPanel);

	Vec2 startPos = Vec2(64.f, 30.f);

	float xOffset = 80.f; 
	float yOffset = 160.f;

	for (int i = 0; i < 16; i++) {

		float coord_x = 64.f + ((i % 8)* 80.f);
		float coord_y = 30.f + (i / 8) * 160.f;

		DivUI* invItem = UIFactory::CreateInvItem(Vec2(coord_x, coord_y), L"item_food", L"resource\\items\\provision\\food.png", i);

		shopInvPanel->AddChild(invItem);
	}

#pragma endregion

#pragma region item

	// 상점 패널
	float itemOffsetX = 80.f;

	for (int i = 0; i < 9; i++) {

		float coord_x = (i % 7) * 80.f;
		float coord_y = (i / 7) * 180.f;

		Vec2 siContainerPos = Vec2(790.f, 35.f) + Vec2(150.f, 130.f);

		DivUI* toolTip = UIFactory::CreateToolTip(Vec2(80.f + siContainerPos.x + (coord_x), siContainerPos.y + coord_y), shopItems[i]);
			
		AddObject(toolTip, GROUP_TYPE::UI_OVER);

		DivUI* shopItem = UIFactory::CreateShopItem(Vec2(coord_x, coord_y), shopItems[i]->GetName(), shopItems[i]->GetPath(), shopItems[i]->GetCurCount(), shopItems[i]->GetCost(), shopInvPanel);
		shopItem->InitOnMouseOver(new ShopItemOver(toolTip));
		shopItem->InitOnMouseOut(new ShopItemOut(toolTip));

		siContainer->AddChild(shopItem);
	}

#pragma endregion

#pragma endregion

#pragma region squad_slot

	DivUI* slotRect = UIFactory::CreateSlotContainer(Vec2(960.f - 170.f, 890.f), dragRenderer);

	pseudoUI->AddChild(slotRect);

#pragma endregion

#pragma region bottom_nav

	DivUI* bottomNavUI = UIFactory::CreateBottomNavUI();

	pseudoUI->AddChild(bottomNavUI);

#pragma endregion

	pseudoUI->AddChild(dragRenderer);

	pseudoUI->AddChild(itemDragger);

	AddObject(pseudoUI, GROUP_TYPE::UI);

	// 씬에 처음 들어왔을때 아무 클릭도 안된상태면 계속 포커싱이 안되므로 임의의 포커싱을 강제로 줌
	UIMgr::GetInst()->SetFocusedUI(pseudoUI);

	// 효과
	Camera::GetInst()->FadeIn(0.5f);
}

void Scene_Shop::update()
{
	Scene::update();

	if (KEY_TAP(KEY::ESC)) {
		ChangeScene(SCENE_TYPE::DSELECT);
		//GameMgr::GetInst()->CleanSqaud();
		// 돈 복구를 해주던가 인벤토리 유지를 해주던가 해야함
		GameMgr::GetInst()->ClearInventory();
	}

	Vec2 mPos = MOUSE_POS;
	Vec2 iScale = itemDragger->GetScale();

	itemDragger->SetPos(mPos - iScale / 2.f);

	if (KEY_AWAY(KEY::LBTN)) {
		itemDragger->SetCanRend(false);
	}

}

void Scene_Shop::Exit()
{
	Scene::Exit();


	Safe_Delete_Vec(shopItems);
}
