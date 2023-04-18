#include "stdafx.h"
#include "SlotUp.h"
#include "DivUI.h"
#include "ImageModule.h"
#include "GameMgr.h"
#include "CHero.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "ResMgr.h"
#include "Sound.h"

SlotUp::SlotUp(DivUI* _mySlot ,DivUI* _dragUI, int _slotIndex, DivUI* _slotContainer)
	: dragUI{_dragUI}, mySlot{_mySlot}, slotIndex{_slotIndex}, slotContainer{_slotContainer}
{
}

void SlotUp::Execute()
{
	// 사운드
	ResMgr::GetInst()->LoadSound(L"slowUpSound", L"resource\\sound\\UI\\ui_shared\\ui_shr_button_click_enemy {ee5e5f86-bb29-469b-bc14-674765c230b8}.wav");
	Sound* downSound = ResMgr::GetInst()->FindSound(L"slowUpSound");

	downSound->SetVolume(10.f);
	downSound->Play(false);

	DivUI* pseudoUI = SceneMgr::GetInst()->GetCurScene()->GetPseudoUI();
	DivUI* sideNavUI = (DivUI*)FindUIByName((UI*)pseudoUI, L"heroSideNav");

	wstring key = L"";
	wstring path = L"";
	wstring hName = L"";
	GameMgr* mgr = GameMgr::GetInst();
	const array<CHero*, 4> squad = mgr->GetSquad();

	if (nullptr != dragUI->GetIModule()) {
		key = dragUI->GetIModule()->GetResourceKey();
		path = dragUI->GetIModule()->GetRelativePath();
		hName = dragUI->GetName();
	}

	if (key != L"" && path != L"" && hName != L"") {

		if (mgr->isSlotEmpty(slotIndex)) {

			// 여기서 스쿼드에서 중복을 비교해서 처리해주는 수밖에 없겠다...
			// 다음부터는 드래그할때 상태를 지정해서 상태기반으로 하자...

			// 이름 기반으로 영웅을 찾아서 해당 영웅이 이미 스쿼드에 있다면 슬롯추가 하지 않음
			CHero* hero = mgr->FindHeroByName(hName);

			for (int i = 0; i < 4; i++) {

				if (nullptr == squad[i]) continue;

				if (squad[i]->GetPKey() == hero->GetPKey()) return;
			}

			mgr->AddSquad(slotIndex, hName);
			mySlot->InitImageModule(key, path);
			mySlot->SetName(hName);
			mySlot->SetCanRendImg(true);
			
			// 여기가 끝났으면 스쿼드에 등록 및 슬롯에 추가했다는 뜻이기 때문에
			// SideNav를 업데이트 해줘서 비활성화 작업 해주면 된다
			// 활성화 작업은 슬롯 다운에서 처리해줘야함
			sideNavUI->updateValue();

		}
		else {
			
			int prevIndex = dragUI->GetId();
			//CHero* draggingHero = mgr->FindHeroByName(hName);
			mgr->AddSquad(prevIndex, hName);

			if (prevIndex == slotIndex) return;

			mgr->SwapSquad(prevIndex, slotIndex);

			// 슬롯 컨테이너를 순회해서 자신의 컨테이너 이름으로 hero를 찾아서 해당 히어로로 
			// 이름 및 이미지 초기화 그리고 이미지 렌더를 켜주자

			// 여기까지 왔다면 게임매니저에서 관리하는 논리적인 슬롯 인덱스는 스왑이 끝난 상태
			for (int i = 0; i < slotContainer->GetChildUI().size(); i++) {

				DivUI* slotPortrait = (DivUI*)(slotContainer->GetChildUI()[i]->GetChildUI()[0]);
				
				if (prevIndex == i) {
					
					CHero* prevHero = mgr->GetHeroBySquad(prevIndex);
					slotPortrait->InitImageModule(prevHero->GetKey(), prevHero->GetPath());
					slotPortrait->SetName(prevHero->GetName());
					slotPortrait->SetCanRend(true);
					slotPortrait->SetCanRendImg(true);
				}
				else if (slotIndex == i) {
					CHero* curHero = mgr->GetHeroBySquad(slotIndex);
					slotPortrait->InitImageModule(curHero->GetKey(), curHero->GetPath());
					slotPortrait->SetName(curHero->GetName());
					slotPortrait->SetCanRend(true);
					slotPortrait->SetCanRendImg(true);
				}
			}
		}
	}

}
