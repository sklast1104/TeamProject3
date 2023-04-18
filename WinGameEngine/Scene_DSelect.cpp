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
	ruin = new CDungeon(L"����");
	ruin->InitRuin();

	court = new CDungeon(L"�ȶ�");
	court->InitCourt();

	bay = new CDungeon(L"�ؾ� ��");
	bay->InitBay();
}

void Scene_DSelect::Enter()
{
	// �巡�� �Ǵ� ������Ʈ
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
	mapText->InitTextModule(L"���� ����", 42);
	mapText->SetBold(FW_BOLD);
	mapText->SetTextColor(200, 180, 110);

	questPanel->AddChild(mapText);

	questTitle = new DivUI;
	questTitle->SetScale(Vec2(400.f, 50.f));
	questTitle->SetPos(Vec2(0.f, 134.f));
	questTitle->InitTextModule(L"����", 26);
	questTitle->SetBold(FW_THIN);
	questTitle->SetTextColor(200, 180, 110);

	questPanel->AddChild(questTitle);

	questText = new DivUI;
	questText->SetScale(Vec2(350.f, 170.f));
	questText->SetPos(Vec2(35.f, 194.f));
	questText->InitTextModule(L"������ ������ ���� � ������\nŽ���սô�. �������� ������ ������\n�������� ���� �ʹ� �ָ� ����\n���ñ�.", 23);
	questText->SetBold(FW_NORMAL);
	questText->SetFont(L"�̼��� ����ü M");
	questText->SetFormat(DT_LEFT);
	questText->SetTextColor(172, 170, 160);

	questPanel->AddChild(questText);

	campingText = new DivUI;
	campingText->SetScale(Vec2(50.f, 40.f));
	campingText->SetPos(Vec2(45.f, 385.f));
	campingText->InitTextModule(L"x0", 20);
	campingText->SetBold(FW_HEAVY);
	campingText->SetFont(L"�̼��� ����ü M");
	campingText->SetTextColor(200, 180, 110);

	questPanel->AddChild(campingText);

	pathLengText = new DivUI;
	pathLengText->SetScale(Vec2(90.f, 40.f));
	pathLengText->SetPos(Vec2(105.f, 385.f));
	pathLengText->InitTextModule(L"ª�� | ", 22);
	pathLengText->SetBold(FW_NORMAL);
	pathLengText->SetFormat(DT_RIGHT | DT_SINGLELINE | DT_VCENTER);
	pathLengText->SetFont(L"�̼��� ����ü M");
	pathLengText->SetTextColor(172, 170, 160);

	questPanel->AddChild(pathLengText);

	pathLevText = new DivUI;
	pathLevText->SetScale(Vec2(200.f, 40.f));
	pathLevText->SetPos(Vec2(195.f, 385.f));
	pathLevText->InitTextModule(L"�߽� (1����) ", 22);
	pathLevText->SetBold(FW_NORMAL);
	pathLevText->SetFormat(DT_LEFT | DT_SINGLELINE | DT_VCENTER);
	pathLevText->SetFont(L"�̼��� ����ü M");
	pathLevText->SetTextColor(146, 187, 88);

	questPanel->AddChild(pathLevText);

	DivUI* goalTitle = new DivUI;
	goalTitle->SetScale(Vec2(350.f, 40.f));
	goalTitle->SetPos(Vec2(35.f, 434.f));
	goalTitle->InitTextModule(L"��ǥ:", 23);
	goalTitle->SetBold(FW_NORMAL);
	goalTitle->SetFont(L"�̼��� ����ü M");
	goalTitle->SetFormat(DT_LEFT);
	goalTitle->SetTextColor(172, 170, 160);

	questPanel->AddChild(goalTitle);

	goalDisc = new DivUI;
	goalDisc->SetScale(Vec2(350.f, 40.f));
	goalDisc->SetPos(Vec2(55.f, 462.f));
	goalDisc->InitTextModule(L"�� ������ 100%�� ����ġ��", 23);
	goalDisc->SetBold(FW_NORMAL);
	goalDisc->SetFont(L"�̼��� ����ü M");
	goalDisc->SetFormat(DT_LEFT);
	goalDisc->SetTextColor(172, 170, 160);

	questPanel->AddChild(goalDisc);

	DivUI* compenTitle = new DivUI;
	compenTitle->SetScale(Vec2(400.f, 50.f));
	compenTitle->SetPos(Vec2(0.f, 522.f));
	compenTitle->InitTextModule(L"����", 26);
	compenTitle->SetBold(FW_THIN);
	compenTitle->SetTextColor(200, 180, 110);

	questPanel->AddChild(compenTitle);

#pragma endregion

	// Ÿ��Ʋ
	DivUI* estateTitle = UIFactory::CreateTitle();

#pragma region dungeon_btn


	DivUI* ruinProgBar = UIFactory::DungeonPgPanel(Vec2(950.f, 220.f), ruin, this);

	pseudoUI->AddChild(ruinProgBar);

	UI* defaultUI = FindUIByName(ruinProgBar, L"����0bg");
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

	// ���� ó�� �������� �ƹ� Ŭ���� �ȵȻ��¸� ��� ��Ŀ���� �ȵǹǷ� ������ ��Ŀ���� ������ ��
	UIMgr::GetInst()->SetFocusedUI(pseudoUI);

	// ȿ��
	Camera::GetInst()->FadeIn(0.5f);
}

void Scene_DSelect::Exit()
{
	radioBtns.clear();

	Scene::Exit();

	Safe_Delete(ruin);
	Safe_Delete(court);
	Safe_Delete(bay);

	// ���� ������ Ŭ���� ���� ���� ������ ��� ���������� ����
	//GameMgr::GetInst()->CleanSqaud();
}

void Scene_DSelect::update()
{
	// ���� ���� ��ȯ ���
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
