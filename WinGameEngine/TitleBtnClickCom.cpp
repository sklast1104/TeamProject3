#include "stdafx.h"
#include "TitleBtnClickCom.h"
#include "ResMgr.h"
#include "Sound.h"

void TitleBtnClickCom::Execute()
{
	ResMgr::GetInst()->LoadSound(L"BtnClick", L"resource\\sound\\UI\\ui_shared\\ui_town_button_click.wav");
	Sound* pTitleSound = ResMgr::GetInst()->FindSound(L"BtnClick");

	pTitleSound->SetVolume(60.f);
	pTitleSound->Play(false);

	ChangeScene(SCENE_TYPE::TOWN);
}
