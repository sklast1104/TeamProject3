#include "stdafx.h"
#include "ForwardBtnEnter.h"

#include "ResMgr.h"
#include "Sound.h"

void ForwardBtnEnter::Execute()
{
	ResMgr::GetInst()->LoadSound(L"forwardBtnSound", L"resource\\sound\\UI\\ui_shared\\ui_shr_button_mouse_over {7a47678d-ca04-4581-ac15-1029b7c0da90}.wav");
	Sound* downSound = ResMgr::GetInst()->FindSound(L"forwardBtnSound");

	downSound->SetVolume(20.f);
	downSound->Play(false);
}
