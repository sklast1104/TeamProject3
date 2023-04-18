#include "stdafx.h"
#include "SlotDown.h"

#include "DivUI.h"
#include "ImageModule.h"
#include "GameMgr.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "ResMgr.h"
#include "Sound.h"

SlotDown::SlotDown(DivUI* _heroPortrait, DivUI* _dragRenderer, int _slotIndex)
	: heroPortrait{_heroPortrait}, dragRenderer{_dragRenderer}, slotIndex{_slotIndex}
{
}

SlotDown::~SlotDown()
{
}

void SlotDown::Execute()
{
	ResMgr::GetInst()->LoadSound(L"slowDownSound", L"resource\\sound\\UI\\ui_shared\\ui_shr_button_click {aafbb3c0-f660-4aa1-b756-be47a979bafd}.wav");
	Sound* downSound = ResMgr::GetInst()->FindSound(L"slowDownSound");

	downSound->SetVolume(10.f);
	downSound->Play(false);

	DivUI* pseudoUI = SceneMgr::GetInst()->GetCurScene()->GetPseudoUI();
	DivUI* sideNavUI = (DivUI*)FindUIByName((UI*)pseudoUI, L"heroSideNav");

	const array<CHero*, 4> squad = GameMgr::GetInst()->GetSquad();

	// 슬롯을 상점씬이랑 던전 선택씬만 쓸텐데 두개다 이 로직을 사용할 확률이 높음
	// 실제로 슬롯에 히어로가 있을때만 동작해야함

	if (nullptr != squad[slotIndex]) {

		if (nullptr != heroPortrait->GetIModule()) {

			wstring key = heroPortrait->GetIModule()->GetResourceKey();
			wstring path = heroPortrait->GetIModule()->GetRelativePath();

			// 씬에서 렌더링해줄떄 히어로 포트레잇에도 이름 붙여줘야함
			dragRenderer->InitImageModule(key, path);
			dragRenderer->SetName(heroPortrait->GetName());
			dragRenderer->SetId(slotIndex);
			dragRenderer->SetCanRend(true);
			heroPortrait->SetCanRendImg(false);

			//heroPortrait->SetName(L"");
			GameMgr::GetInst()->MakeEmpySlot(slotIndex);
			sideNavUI->updateValue();

		}
	}
	
}
