#include "stdafx.h"
#include "Scene_Town.h"

#include "Core.h"
#include "DivUI.h"
#include "BtnBuilding.h"
#include "BuildingOverCom.h"
#include "BuildingMouseOut.h"
#include "BtnOverCom.h"
#include "BtnOutCom.h"
#include "UIMgr.h"
#include "UIFactory.h"
#include "Sound.h"
#include "ResMgr.h"
#include "Camera.h"
#include "KeyMgr.h"
#include "BuildingEnterCom.h"

Scene_Town::Scene_Town()
{
}

Scene_Town::~Scene_Town()
{
}

void Scene_Town::update()
{
	Scene::update();

	if (KEY_TAP(KEY::ESC)) {
		ChangeScene(SCENE_TYPE::TITLE);
	}
}

void Scene_Town::Enter()
{
	Vec2 vResolution = Core::GetInst()->GetResolution();
	
#pragma region BackGround

	DivUI* pseudoUI = new DivUI;
	pseudoUI->SetScale(vResolution);
	pseudoUI->SetPos(Vec2(0.f, 0.f));
	pseudoUI->CanTarget(false);

	DivUI* bg = new DivUI;
	bg->SetScale(vResolution);
	bg->SetPos(Vec2(0.f, 0.f));
	bg->CanTarget(false);
	bg->InitImageModule(L"Darkest_Town_Weather_bg", L"resource\\Background\\town_bg_activity_stress_heal_buff.png");
	bg->SetSrcAlpha(255);

	pseudoUI->AddChild(bg);

	DivUI* ruinBg = new DivUI;
	ruinBg->SetScale(Vec2(1418.f, 438.f));
	ruinBg->SetPos(Vec2(0.f, 100.f));
	ruinBg->CanTarget(false);
	ruinBg->InitImageModule(L"Darkest_Town_Ruin_bg", L"resource\\Background\\ruins.png");
	ruinBg->SetSrcAlpha(235);

	pseudoUI->AddChild(ruinBg);

	DivUI* towerbg = new DivUI;
	towerbg->SetScale(Vec2(1920.f, 835.f) * 1.05f);
	towerbg->SetPos(Vec2(0.f, 220.f));
	towerbg->CanTarget(false);
	towerbg->InitImageModule(L"Darkest_Town_Bg", L"resource\\Background\\town_ground.sprite.png");
	towerbg->SetSrcAlpha(255);

	pseudoUI->AddChild(towerbg);

	// 타이틀
	DivUI* estateTitle = UIFactory::CreateTitle();

	pseudoUI->AddChild(estateTitle);


#pragma endregion

#pragma region Estate

	// 추상 팩토리 패턴으로 관리해야 할 필요성 있을수도 있음
	
	// 수도원
	DivUI* abbey_active = new DivUI;
	abbey_active->SetScale(Vec2(779.f, 901.f));
	abbey_active->SetScale(abbey_active->GetScale() * 0.5f);
	abbey_active->SetPos(Vec2(904.f, 144.f));
	abbey_active->CanTarget(false);
	abbey_active->InitImageModule(L"Darkest_Estate_abbey_active", L"resource\\estate\\abbey\\active.png");
	abbey_active->SetSrcAlpha(235);
	abbey_active->SetCanRendImg(false);

	pseudoUI->AddChild(abbey_active);

	// 설명 패널
	DivUI* abbey_disc = UIFactory::CreateTownDiscUI(Vec2(884.f, 124.f), L"수도원", L"스트레스 해소");
	abbey_disc->SetCanRend(false);

	DivUI* abbey = new DivUI;
	abbey->SetScale(Vec2(800.f, 987.f));
	abbey->SetScale(abbey->GetScale() * 0.5f);
	abbey->SetPos(Vec2(900.f, 150.f));
	abbey->CanTarget(true);
	abbey->InitImageModule(L"Darkest_Estate_abbey", L"resource\\estate\\abbey\\idle.png");
	abbey->SetSrcAlpha(235);
	abbey->InitOnMouseOver(new BuildingOverCom(abbey_active, abbey_disc));
	abbey->InitOnMouseExit(new BuildingMouseOut(abbey_active, abbey_disc));
	abbey->InitOnMouseEnter(new BuildingEnterCom);

	pseudoUI->AddChild(abbey);
	pseudoUI->AddChild(abbey_disc);

	// 묘지
	DivUI* graveyard = new DivUI;
	graveyard->SetScale(Vec2(573.f, 289.f));
	graveyard->SetScale(graveyard->GetScale() * 0.5f);
	graveyard->SetPos(Vec2(860.f, 490.f));
	graveyard->CanTarget(false);
	graveyard->InitImageModule(L"Darkest_Estate_graveyard", L"resource\\estate\\graveyard\\idle.png");
	graveyard->SetSrcAlpha(235);

	pseudoUI->AddChild(graveyard);

	// 요양원
	DivUI* sanitarium_active = new DivUI;
	sanitarium_active->SetScale(Vec2(666.f, 883.f));
	sanitarium_active->SetScale(sanitarium_active->GetScale() * 0.5f);
	sanitarium_active->SetPos(Vec2(602.f, 262.f));
	sanitarium_active->CanTarget(false);
	sanitarium_active->InitImageModule(L"Darkest_Estate_Sanitarium_active", L"resource\\estate\\sanitarium\\active.png");
	sanitarium_active->SetSrcAlpha(235);
	sanitarium_active->SetCanRendImg(false);

	pseudoUI->AddChild(sanitarium_active);

	DivUI* sanitarium_disc = UIFactory::CreateTownDiscUI(Vec2(558.f, 184.f), L"요양원", L"기벽과 질병 치료");
	sanitarium_disc->SetCanRend(false);

	DivUI* sanitarium = new DivUI;
	sanitarium->SetScale(Vec2(764.f, 965.f));
	sanitarium->SetScale(sanitarium->GetScale() * 0.5f);
	sanitarium->SetPos(Vec2(600.f, 270.f));
	sanitarium->CanTarget(true);
	sanitarium->InitImageModule(L"Darkest_Estate_Sanitarium", L"resource\\estate\\sanitarium\\idle.png");
	sanitarium->SetSrcAlpha(235);
	sanitarium->InitOnMouseOver(new BuildingOverCom(sanitarium_active, sanitarium_disc));
	sanitarium->InitOnMouseEnter(new BuildingEnterCom);
	sanitarium->InitOnMouseExit(new BuildingMouseOut(sanitarium_active, sanitarium_disc));

	pseudoUI->AddChild(sanitarium);
	pseudoUI->AddChild(sanitarium_disc);

	// 여관
	DivUI* tavern_active = new DivUI;
	tavern_active->SetScale(Vec2(768.f, 753.f));
	tavern_active->SetScale(tavern_active->GetScale() * 0.5f);
	tavern_active->SetPos(Vec2(355.f, 413.f));
	tavern_active->CanTarget(false);
	tavern_active->InitImageModule(L"Darkest_Estate_tavern_active", L"resource\\estate\\tavern\\active.png");
	tavern_active->SetSrcAlpha(235);
	tavern_active->SetCanRendImg(false);

	pseudoUI->AddChild(tavern_active);

	DivUI* tavern_disc = UIFactory::CreateTownDiscUI(Vec2(328.f, 304.f), L"여관", L"스트레스 해소");
	tavern_disc->SetCanRend(false);

	DivUI* tavern = new DivUI;
	tavern->SetScale(Vec2(770.f, 806.f));
	tavern->SetScale(tavern->GetScale() * 0.5f);
	tavern->SetPos(Vec2(350.f, 420.f));
	tavern->CanTarget(true);
	tavern->InitImageModule(L"Darkest_Estate_tavern", L"resource\\estate\\tavern\\idle.png");
	tavern->SetSrcAlpha(235);
	tavern->InitOnMouseOver(new BuildingOverCom(tavern_active, tavern_disc));
	tavern->InitOnMouseExit(new BuildingMouseOut(tavern_active, tavern_disc));
	tavern->InitOnMouseEnter(new BuildingEnterCom);


	pseudoUI->AddChild(tavern);
	pseudoUI->AddChild(tavern_disc);

	// 길드
	DivUI* guild_active = new DivUI;
	guild_active->SetScale(Vec2(648.f, 656.f));
	guild_active->SetScale(guild_active->GetScale() * 0.5f);
	guild_active->SetPos(Vec2(1147.f, 412.f));
	guild_active->CanTarget(false);
	guild_active->InitImageModule(L"Darkest_Estate_guild_active", L"resource\\estate\\guild\\active.png");
	guild_active->SetSrcAlpha(235);
	guild_active->SetCanRendImg(false);

	pseudoUI->AddChild(guild_active);

	DivUI* guild_disc = UIFactory::CreateTownDiscUI(Vec2(1130.f, 254.f), L"길드", L"전투기술 강화");
	guild_disc->SetCanRend(false);

	DivUI* guild = new DivUI;
	guild->SetScale(Vec2(683.f, 693.f));
	guild->SetScale(guild->GetScale() * 0.5f);
	guild->SetPos(Vec2(1150.f, 420.f));
	guild->CanTarget(true);
	guild->InitImageModule(L"Darkest_Estate_guild", L"resource\\estate\\guild\\idle.png");
	guild->SetSrcAlpha(235);
	guild->InitOnMouseOver(new BuildingOverCom(guild_active, guild_disc));
	guild->InitOnMouseExit(new BuildingMouseOut(guild_active, guild_disc));
	guild->InitOnMouseEnter(new BuildingEnterCom);

	pseudoUI->AddChild(guild);
	pseudoUI->AddChild(guild_disc);

	// 대장간
	DivUI* black_smith_active = new DivUI;
	black_smith_active->SetScale(Vec2(719.f, 788.f));
	black_smith_active->SetScale(black_smith_active->GetScale() * 0.5f);
	black_smith_active->SetPos(Vec2(1306.f, 470.f));
	black_smith_active->CanTarget(false);
	black_smith_active->InitImageModule(L"Darkest_Estate_black_smith_active", L"resource\\estate\\black_smith\\active.png");
	black_smith_active->SetSrcAlpha(235);
	black_smith_active->SetCanRendImg(false);

	pseudoUI->AddChild(black_smith_active);

	DivUI* black_smith_disc = UIFactory::CreateTownDiscUI(Vec2(1260.f, 420.f), L"대장간", L"무기와 갑옷 강화");
	black_smith_disc->SetCanRend(false);

	DivUI* black_smith = new DivUI;
	black_smith->SetScale(Vec2(703.f, 790.f));
	black_smith->SetScale(black_smith->GetScale() * 0.5f);
	black_smith->SetPos(Vec2(1310.f, 480.f));
	black_smith->CanTarget(true);
	black_smith->InitImageModule(L"Darkest_Estate_black_smith", L"resource\\estate\\black_smith\\idle.png");
	black_smith->SetSrcAlpha(235);
	black_smith->InitOnMouseOver(new BuildingOverCom(black_smith_active, black_smith_disc));
	black_smith->InitOnMouseExit(new BuildingMouseOut(black_smith_active, black_smith_disc));
	black_smith->InitOnMouseEnter(new BuildingEnterCom);

	pseudoUI->AddChild(black_smith);
	pseudoUI->AddChild(black_smith_disc);

	// 유목민 마차
	DivUI* nomad_wagon_active = new DivUI;
	nomad_wagon_active->SetScale(Vec2(498.f, 392.f));
	nomad_wagon_active->SetScale(nomad_wagon_active->GetScale() * 0.5f);
	nomad_wagon_active->SetPos(Vec2(1002.f, 670.f));
	nomad_wagon_active->CanTarget(false);
	nomad_wagon_active->InitImageModule(L"Darkest_Estate_nomad_wagon_active", L"resource\\estate\\nomad_wagon\\active.png");
	nomad_wagon_active->SetSrcAlpha(235);
	nomad_wagon_active->SetCanRendImg(false);

	pseudoUI->AddChild(nomad_wagon_active);

	DivUI* nomad_wagon_disc = UIFactory::CreateTownDiscUI(Vec2(950.f, 520.f), L"유목민 마차", L"희귀 장신구 구입");
	nomad_wagon_disc->SetCanRend(false);

	DivUI* nomad_wagon = new DivUI;
	nomad_wagon->SetScale(Vec2(489.f, 383.f));
	nomad_wagon->SetScale(nomad_wagon->GetScale() * 0.5f);
	nomad_wagon->SetPos(Vec2(1010.f, 680.f));
	nomad_wagon->CanTarget(true);
	nomad_wagon->InitImageModule(L"Darkest_Estate_nomad_wagon", L"resource\\estate\\nomad_wagon\\idle.png");
	nomad_wagon->SetSrcAlpha(235);
	nomad_wagon->InitOnMouseOver(new BuildingOverCom(nomad_wagon_active, nomad_wagon_disc));
	nomad_wagon->InitOnMouseExit(new BuildingMouseOut(nomad_wagon_active, nomad_wagon_disc));
	nomad_wagon->InitOnMouseEnter(new BuildingEnterCom);

	pseudoUI->AddChild(nomad_wagon);
	pseudoUI->AddChild(nomad_wagon_disc);

	// 역마차
	DivUI* stage_coach_active = new DivUI;
	stage_coach_active->SetScale(Vec2(510.f, 358.f));
	stage_coach_active->SetScale(stage_coach_active->GetScale() * 0.5f);
	stage_coach_active->SetPos(Vec2(207.f, 650.f));
	stage_coach_active->CanTarget(false);
	stage_coach_active->InitImageModule(L"Darkest_Estate_stage_coach_active", L"resource\\estate\\stage_coach\\active.png");
	stage_coach_active->SetSrcAlpha(235);
	stage_coach_active->SetCanRendImg(false);

	pseudoUI->AddChild(stage_coach_active);

	DivUI* stage_coach_disc = UIFactory::CreateTownDiscUI(Vec2(167.f, 490.f), L"역마차", L"새 영웅 고용");
	stage_coach_disc->SetCanRend(false);

	DivUI* stage_coach = new DivUI;
	stage_coach->SetScale(Vec2(502.f, 357.f));
	stage_coach->SetScale(stage_coach->GetScale() * 0.5f);
	stage_coach->SetPos(Vec2(210.f, 660.f));
	stage_coach->CanTarget(true);
	stage_coach->InitImageModule(L"Darkest_Estate_stage_coach", L"resource\\estate\\stage_coach\\idle.png");
	stage_coach->SetSrcAlpha(235);
	stage_coach->InitOnMouseOver(new BuildingOverCom(stage_coach_active, stage_coach_disc));
	stage_coach->InitOnMouseExit(new BuildingMouseOut(stage_coach_active, stage_coach_disc));
	stage_coach->InitOnMouseEnter(new BuildingEnterCom);

	pseudoUI->AddChild(stage_coach);
	pseudoUI->AddChild(stage_coach_disc);

#pragma endregion

#pragma region bottom_nav

	DivUI* bottomNavUI = UIFactory::CreateBottomNavUI();

	pseudoUI->AddChild(bottomNavUI);

#pragma endregion

#pragma region side_nav

	DivUI* heroSideNav = UIFactory::CreateSideNavUI();

	pseudoUI->AddChild(heroSideNav);

#pragma endregion

	AddObject(pseudoUI, GROUP_TYPE::UI);

	// 씬에 처음 들어왔을때 아무 클릭도 안된상태면 계속 포커싱이 안되므로 임의의 포커싱을 강제로 줌
	UIMgr::GetInst()->SetFocusedUI(pseudoUI);

#pragma region Sound

	// 사운드
	ResMgr::GetInst()->LoadSound(L"TownBgm", L"resource\\sound\\Music\\Town_Stereo_Mix_LOOP_2.wav");
	Sound* pTitleSound = ResMgr::GetInst()->FindSound(L"TownBgm");

	pTitleSound->SetVolume(20.f);
	pTitleSound->PlayToBGM(true);

#pragma endregion

	// 효과
	Camera::GetInst()->FadeIn(0.5f);
}

void Scene_Town::Exit()
{
	DeleteAll();
}
