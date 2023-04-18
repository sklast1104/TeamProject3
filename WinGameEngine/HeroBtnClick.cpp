#include "stdafx.h"
#include "HeroBtnClick.h"

#include "SceneMgr.h"
#include "Scene.h"
#include "Scene_DSelect.h"
#include "DivUI.h"
#include "CHero.h"
#include "ResMgr.h"
#include "Sound.h"

HeroBtnClick::HeroBtnClick(CHero* _hero)
	: hero{_hero}
{
}

void HeroBtnClick::Execute()
{
	ResMgr::GetInst()->LoadSound(L"slowDownSound", L"resource\\sound\\UI\\ui_shared\\ui_shr_button_click {aafbb3c0-f660-4aa1-b756-be47a979bafd}.wav");
	Sound* downSound = ResMgr::GetInst()->FindSound(L"slowDownSound");

	downSound->SetVolume(10.f);
	downSound->Play(false);

	Scene* curScene = SceneMgr::GetInst()->GetCurScene();

	if (curScene->GetName() == L"Scene_DSelect") {
		
		DivUI* renderer = ((Scene_DSelect*)curScene)->GetRenderer();
		
		renderer->SetCanRend(true);
		renderer->InitImageModule(hero->GetKey(), hero->GetPath());
		renderer->SetName(hero->GetName());
	}
}

