#include "stdafx.h"
#include "Scene_Title.h"

#include "Core.h"
#include "DivUI.h"
#include "BtnMOver.h"
#include "AnimatorDK.h"
#include "ResMgr.h"
#include "Sound.h"
#include "UIMgr.h"
#include "TitleBtnClickCom.h"
#include "Camera.h"

Scene_Title::Scene_Title()
{
}

Scene_Title::~Scene_Title()
{
}

void Scene_Title::Enter()
{
	Vec2 vResolution = Core::GetInst()->GetResolution();

#pragma region BackGround

	DivUI* pseudoUI = new DivUI;
	pseudoUI->SetScale(vResolution);
	pseudoUI->SetPos(Vec2(0.f, 0.f));
	pseudoUI->CanTarget(false);
	
	DivUI* bg = new DivUI;
	bg->SetScale(vResolution);
	bg->SetPos(Vec2(0.f, -160.f));
	bg->CanTarget(false);
	bg->InitImageModule(L"Darkest_Title_Bg", L"resource\\fe_flow\\title_bg.png");
	bg->SetSrcAlpha(220);

	DivUI* title = new DivUI;
	title->CreateAnimator(new AnimatorDK);
	title->LoadAnimation(L"Title_Animation", L"resource\\animations\\title_anim\\titles.sprite-torch_loop.atlas");
	title->SetScale(Vec2(500.f, 500.f));
	title->SetPos(Vec2(960.f - 500.f, 360 - 250.f));
	title->CanTarget(false);
	bg->AddChild(title);
	
	DivUI* cloud1 = new DivUI;
	cloud1->SetScale(Vec2(1920.f, 179.f));
	cloud1->SetPos(Vec2(700.f, 620.f));
	cloud1->InitImageModule(L"Title_Sky_01", L"resource\\fe_flow\\sky01.png");
	cloud1->CanTarget(false);
	bg->AddChild(cloud1);

	DivUI* cloud2 = new DivUI;
	cloud2->SetScale(Vec2(1920.f, 179.f));
	cloud2->SetPos(Vec2(-600.f, 560.f));
	cloud2->InitImageModule(L"Title_Sky_01", L"resource\\fe_flow\\sky01.png");
	cloud2->CanTarget(false);
	bg->AddChild(cloud2);

	DivUI* cloud3 = new DivUI;
	cloud3->SetScale(Vec2(1229.f, 106.f));
	cloud3->SetPos(Vec2(0.f, 700.f));
	cloud3->InitImageModule(L"Title_Sky_02", L"resource\\fe_flow\\sky02.png");
	cloud3->CanTarget(false);
	bg->AddChild(cloud3);

	DivUI* house = new DivUI;
	house->SetScale(Vec2(1920.f, 674.f));
	house->SetPos(Vec2(0.f, 570.f));
	house->InitImageModule(L"Title_House", L"resource\\fe_flow\\title_house.png");
	house->CanTarget(false);
	bg->AddChild(house);

	BtnMOver* titleBtn = new BtnMOver;
	titleBtn->InitImageModule(L"Darkest_Title_btn", L"resource\\fe_flow\\start_button.png");
	titleBtn->SetScale(Vec2(372.f, 92.f));
	titleBtn->SetPos(Vec2(960.f - 186, 1060.f));
	titleBtn->SetSrcAlpha(200);
	titleBtn->InitTextModule(L"캠페인", 40);
	titleBtn->SetTextColor(161, 145, 89);
	titleBtn->InitOnMouseClick(new TitleBtnClickCom);
	bg->AddChild(titleBtn);

	pseudoUI->AddChild(bg);

	AddObject(pseudoUI, GROUP_TYPE::UI);

	// 씬에 처음 들어왔을때 아무 클릭도 안된상태면 계속 포커싱이 안되므로 임의의 포커싱을 강제로 줌
	UIMgr::GetInst()->SetFocusedUI(pseudoUI);

#pragma endregion

#pragma region Sound

	// 사운드
	ResMgr::GetInst()->LoadSound(L"TitleBgm", L"resource\\sound\\Music\\mus_theme_outro_loop.wav");
	Sound* pTitleSound = ResMgr::GetInst()->FindSound(L"TitleBgm");

	pTitleSound->SetVolume(20.f);
	pTitleSound->PlayToBGM(true);

#pragma endregion

	// 효과
	Camera::GetInst()->FadeIn(0.5f);
}

void Scene_Title::Exit()
{
	DeleteAll();
}
