#include "stdafx.h"
#include "RadioBtnClickCom.h"

#include "Scene_DSelect.h"
#include "DivUI.h"
#include "CQuest.h"

#include "ResMgr.h"
#include "Sound.h"

RadioBtnClickCom::RadioBtnClickCom(DivUI* _myBg, CQuest* _quest, Scene_DSelect* _dScene)
	: myBg{_myBg}, quest{_quest}
	, dSelectScene{_dScene}
{
}

void RadioBtnClickCom::Execute()
{
	ResMgr::GetInst()->LoadSound(L"radioBtnSound", L"resource\\sound\\UI\\ui_shared\\ui_shr_button_mouse_over_alt {b7ef6ca0-cb7f-42a4-a5e0-498302d6c205}.wav");
	Sound* downSound = ResMgr::GetInst()->FindSound(L"radioBtnSound");

	downSound->SetVolume(30.f);
	downSound->Play(false);

	dSelectScene->turnOffRadioBtn();
	myBg->SetCanRend(true);

	dSelectScene->questTitle->SetText(quest->GetQTypeTitle());
	dSelectScene->questText->SetText(quest->GetQDisc());
	dSelectScene->pathLengText->SetText(quest->GetDPath() + L" | ");
	dSelectScene->pathLevText->SetText(quest->GetQLevel());
	dSelectScene->goalDisc->SetText(quest->GetQGoal());
}
