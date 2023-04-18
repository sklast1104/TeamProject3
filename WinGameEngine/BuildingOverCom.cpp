#include "stdafx.h"
#include "BuildingOverCom.h"
#include "DivUI.h"
#include "ResMgr.h"
#include "Sound.h"

BuildingOverCom::BuildingOverCom(DivUI* _overImg, DivUI* _txtPanel)
	: overImg{_overImg}
	, txtPanel{_txtPanel}
{
}

void BuildingOverCom::Execute()
{
	overImg->SetCanRendImg(true);
	txtPanel->SetCanRend(true);

	//ResMgr::GetInst()->LoadSound(L"MouseOver", L"resource\\sound\\UI\\ui_shared\\ui_town_button_mouseover_2.wav");
	//Sound* pTitleSound = ResMgr::GetInst()->FindSound(L"MouseOver");
	//pTitleSound->SetVolume(60.f);

	//if (!pTitleSound->IsPlaying()) {
	//	pTitleSound->Play(false);
	//}
	
}
