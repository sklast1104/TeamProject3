#include "stdafx.h"
#include "Scene_DSelect.h"
#include "Core.h"
#include "DivUI.h"
#include "UIMgr.h"
#include "UIFactory.h"
#include "RadioBtnClickCom.h"
#include "CDungeon.h"
#include "CQuest.h"
#include "KeyMgr.h"
#include "Camera.h"

#include "DRendererUp.h"
#include "SlotUp.h"
#include "SlotDown.h"
#include "GameMgr.h"
#include "ImageModule.h"

Scene_DSelect::Scene_DSelect()
	: scState{DSCENE_STATE::Idle}
{
	
}

Scene_DSelect::~Scene_DSelect()
{
	Safe_Delete(ruin);
	Safe_Delete(court);
	Safe_Delete(bay);
}

void Scene_DSelect::InitDungeon()
{
	ruin = new CDungeon(L"폐허");
	ruin->InitRuin();

	court = new CDungeon(L"안뜰");
	court->InitCourt();

	bay = new CDungeon(L"해안 만");
	bay->InitBay();
}

void Scene_DSelect::Enter()
{
	// 드래그 되는 오브젝트
	dragRenderer = new DivUI;
	dragRenderer->SetScale(Vec2(68.f, 68.f));
	dragRenderer->SetPos(Vec2(960.f, 540.f));
	dragRenderer->CanTarget(false);

	InitDungeon();

	Vec2 vResolution = Core::GetInst()->GetResolution();

	pseudoUI = new DivUI;
	pseudoUI->SetScale(vResolution);
	pseudoUI->SetPos(Vec2(0.f, 0.f));
	pseudoUI->CanTarget(false);

	DivUI* bg = new DivUI;
	bg->SetScale(vResolution);
	bg->SetPos(Vec2(0.f, 0.f));
	bg->CanTarget(false);
	bg->InitImageModule(L"Darkest_Dselect_bg", L"resource\\Background\\quest_select.png");
	bg->SetSrcAlpha(255);

	pseudoUI->AddChild(bg);

#pragma region quest_disc_panel

	DivUI* questPanel = new DivUI;
	questPanel->SetScale(Vec2(400.f, 843.f));
	questPanel->SetPos(Vec2(140.f, 130.f));
	questPanel->InitImageModule(L"Quest_Select_Panel", L"resource\\quest_select\\q_select_bg_panel.png");

	pseudoUI->AddChild(questPanel);

	DivUI* questIcon = new DivUI;
	questIcon->SetScale(Vec2(113.f, 113.f));
	questIcon->SetPos(Vec2(30.f, 15.f));
	questIcon->InitImageModule(L"Quest_Select_Icon", L"resource\\quest_select\\quest_select.icon.png");

	questPanel->AddChild(questIcon);

	DivUI* mapText = new DivUI;
	mapText->SetScale(Vec2(170.f, 120.f));
	mapText->SetPos(Vec2(150.f, 15.f));
	mapText->InitTextModule(L"영지 지도", 42);
	mapText->SetBold(FW_BOLD);
	mapText->SetTextColor(200, 180, 110);

	questPanel->AddChild(mapText);

	questTitle = new DivUI;
	questTitle->SetScale(Vec2(400.f, 50.f));
	questTitle->SetPos(Vec2(0.f, 134.f));
	questTitle->InitTextModule(L"정찰", 26);
	questTitle->SetBold(FW_THIN);
	questTitle->SetTextColor(200, 180, 110);

	questPanel->AddChild(questTitle);

	questText = new DivUI;
	questText->SetScale(Vec2(350.f, 170.f));
	questText->SetPos(Vec2(35.f, 194.f));
	questText->InitTextModule(L"스러진 선조의 광기 어린 영지를\n탐헙합시다. 괴물들이 어디까지 영역을\n넓혔는지 보되 너무 멀리 들어서진\n마시길.", 23);
	questText->SetBold(FW_NORMAL);
	questText->SetFont(L"이순신 돋움체 M");
	questText->SetFormat(DT_LEFT);
	questText->SetTextColor(172, 170, 160);

	questPanel->AddChild(questText);

	campingText = new DivUI;
	campingText->SetScale(Vec2(50.f, 40.f));
	campingText->SetPos(Vec2(45.f, 385.f));
	campingText->InitTextModule(L"x0", 20);
	campingText->SetBold(FW_HEAVY);
	campingText->SetFont(L"이순신 돋움체 M");
	campingText->SetTextColor(200, 180, 110);

	questPanel->AddChild(campingText);

	pathLengText = new DivUI;
	pathLengText->SetScale(Vec2(90.f, 40.f));
	pathLengText->SetPos(Vec2(105.f, 385.f));
	pathLengText->InitTextModule(L"짧음 | ", 22);
	pathLengText->SetBold(FW_NORMAL);
	pathLengText->SetFormat(DT_RIGHT | DT_SINGLELINE | DT_VCENTER);
	pathLengText->SetFont(L"이순신 돋움체 M");
	pathLengText->SetTextColor(172, 170, 160);

	questPanel->AddChild(pathLengText);

	pathLevText = new DivUI;
	pathLevText->SetScale(Vec2(200.f, 40.f));
	pathLevText->SetPos(Vec2(195.f, 385.f));
	pathLevText->InitTextModule(L"견습 (1레벨) ", 22);
	pathLevText->SetBold(FW_NORMAL);
	pathLevText->SetFormat(DT_LEFT | DT_SINGLELINE | DT_VCENTER);
	pathLevText->SetFont(L"이순신 돋움체 M");
	pathLevText->SetTextColor(146, 187, 88);

	questPanel->AddChild(pathLevText);

	DivUI* goalTitle = new DivUI;
	goalTitle->SetScale(Vec2(350.f, 40.f));
	goalTitle->SetPos(Vec2(35.f, 434.f));
	goalTitle->InitTextModule(L"목표:", 23);
	goalTitle->SetBold(FW_NORMAL);
	goalTitle->SetFont(L"이순신 돋움체 M");
	goalTitle->SetFormat(DT_LEFT);
	goalTitle->SetTextColor(172, 170, 160);

	questPanel->AddChild(goalTitle);

	goalDisc = new DivUI;
	goalDisc->SetScale(Vec2(350.f, 40.f));
	goalDisc->SetPos(Vec2(55.f, 462.f));
	goalDisc->InitTextModule(L"방 전투의 100%를 끝마치기", 23);
	goalDisc->SetBold(FW_NORMAL);
	goalDisc->SetFont(L"이순신 돋움체 M");
	goalDisc->SetFormat(DT_LEFT);
	goalDisc->SetTextColor(172, 170, 160);

	questPanel->AddChild(goalDisc);

	DivUI* compenTitle = new DivUI;
	compenTitle->SetScale(Vec2(400.f, 50.f));
	compenTitle->SetPos(Vec2(0.f, 522.f));
	compenTitle->InitTextModule(L"보상", 26);
	compenTitle->SetBold(FW_THIN);
	compenTitle->SetTextColor(200, 180, 110);

	questPanel->AddChild(compenTitle);

#pragma endregion

	// 타이틀
	DivUI* estateTitle = UIFactory::CreateTitle();

#pragma region dungeon_btn


	DivUI* ruinProgBar = UIFactory::DungeonPgPanel(Vec2(950.f, 220.f), ruin, this);

	pseudoUI->AddChild(ruinProgBar);

	UI* defaultUI = FindUIByName(ruinProgBar, L"폐허0bg");
	((DivUI*)defaultUI)->SetCanRend(true);
	
	DivUI* bayProgBar = UIFactory::DungeonPgPanel(Vec2(1250.f, 420.f), bay, this);

	pseudoUI->AddChild(bayProgBar);

	DivUI* courtProgBar = UIFactory::DungeonPgPanel(Vec2(600.f, 320.f), court, this);

	pseudoUI->AddChild(courtProgBar);


#pragma endregion

#pragma region squad_slot

	DivUI* slotRect = UIFactory::CreateSlotContainer(Vec2(960.f - 170.f, 890.f), dragRenderer);
	
	pseudoUI->AddChild(slotRect);

#pragma endregion

#pragma region bottom_nav

	DivUI* bottomNavUI = UIFactory::CreateBottomNavUI();

	pseudoUI->AddChild(bottomNavUI);

#pragma endregion

#pragma region side_nav

	DivUI* heroSideNav = UIFactory::CreateSideNavUI();

	pseudoUI->AddChild(heroSideNav);

#pragma endregion

	pseudoUI->AddChild(estateTitle);

	pseudoUI->AddChild(dragRenderer);
	
	AddObject(pseudoUI, GROUP_TYPE::UI);

	// 씬에 처음 들어왔을때 아무 클릭도 안된상태면 계속 포커싱이 안되므로 임의의 포커싱을 강제로 줌
	UIMgr::GetInst()->SetFocusedUI(pseudoUI);

	// 효과
	Camera::GetInst()->FadeIn(0.5f);
}

void Scene_DSelect::Exit()
{
	radioBtns.clear();

	Scene::Exit();

	Safe_Delete(ruin);
	Safe_Delete(court);
	Safe_Delete(bay);

	// 이제 스쿼드 클리어 하지 말고 스쿼드 기반 렌더링으로 변경
	//GameMgr::GetInst()->CleanSqaud();
}

void Scene_DSelect::update()
{
	// 전역 상태 변환 취급
	Scene::update();

	if (KEY_TAP(KEY::ESC)) {
		ChangeScene(SCENE_TYPE::TOWN);
	}

	Vec2 mPos = MOUSE_POS;
	Vec2 dScale = dragRenderer->GetScale();

	dragRenderer->SetPos(mPos - dScale / 2.f);

	if (KEY_AWAY(KEY::LBTN)) {
		dragRenderer->SetCanRend(false);
	}

	if (scState == DSCENE_STATE::Idle) {

	}
	else if (scState == DSCENE_STATE::HeroDrag) {

	}
}

void Scene_DSelect::turnOffRadioBtn()
{
	for (int i = 0; i < radioBtns.size(); i++) {
		radioBtns[i]->SetCanRend(false);
	}
}
