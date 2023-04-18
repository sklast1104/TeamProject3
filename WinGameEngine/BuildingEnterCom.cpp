#include "stdafx.h"
#include "BuildingEnterCom.h"
#include "ResMgr.h"
#include "Sound.h"


void BuildingEnterCom::Execute()
{
	ResMgr::GetInst()->LoadSound(L"slowDownSound", L"resource\\sound\\UI\\ui_shared\\ui_shr_button_click {aafbb3c0-f660-4aa1-b756-be47a979bafd}.wav");
	Sound* downSound = ResMgr::GetInst()->FindSound(L"slowDownSound");

	downSound->SetVolume(5.f);
	downSound->Play(false);
}
