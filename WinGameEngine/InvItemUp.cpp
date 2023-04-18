#include "stdafx.h"
#include "InvItemUp.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "DivUI.h"
#include "Scene_Shop.h"
#include "GameMgr.h"
#include "CItem.h"
#include "ResMgr.h"
#include "Sound.h"

InvItemUp::InvItemUp(DivUI* _myItem, int _index)
	: scene{ SceneMgr::GetInst()->GetCurScene() }
	, myItem{ _myItem }, mgr{ GameMgr::GetInst() }, index{ _index }
{
}

void InvItemUp::Execute()
{
	// 사운드
	ResMgr::GetInst()->LoadSound(L"slowUpSound", L"resource\\sound\\UI\\ui_shared\\ui_shr_button_click_enemy {ee5e5f86-bb29-469b-bc14-674765c230b8}.wav");
	Sound* downSound = ResMgr::GetInst()->FindSound(L"slowUpSound");

	downSound->SetVolume(10.f);
	downSound->Play(false);

	// 클릭이랑 업일때 둘다 이벤트 들어옴
	DivUI* itemDragger = (DivUI*)FindUIByName((UI*)(scene->GetPseudoUI()), L"itemDragger");
	DivUI* shopInvPanel = (DivUI*)FindUIByName((UI*)(scene->GetPseudoUI()), L"shopInvPanel");

	array<CItem*, 16>& inventory = mgr->GetInventory();

	CItem* curUp = inventory[index];

	int prevIndex = itemDragger->GetId();

	// 클릭이랑 같은동작이면 업 이벤트는 할거 없음
	if (prevIndex == index) return;

	if (nullptr == curUp) {

		// 빈 슬롯이면 아이템을 옮겨주면됨

		// 먼저 게임 매니저 기반으로 옮겨주고 
		mgr->MoveInventory(prevIndex, index);

		// 인벤토리 패널 가져와서 업데이트 해준다
		shopInvPanel->updateValue();
	}
	else {

		// 그렇지 않다면 같은 아이템이라면 maxCount 비교
		CItem* prevItem = inventory[prevIndex];
			
		// 같은 아이템이라면
		if (prevItem->GetName() == curUp->GetName()) {

			int prevCount = prevItem->GetCurCount();
			int curCount = curUp->GetCurCount();

			// 현재 아이템의 개수가 맥스카운터보다 적은 상태라면
			if (curCount < curUp->GetMaxCount()) {

				int reserve = curUp->GetMaxCount() - curUp->GetCurCount();
				if (reserve > prevItem->GetCurCount()) reserve = prevItem->GetCurCount();
				// 맥스카운트 차분만큼 더해주고
				curUp->SetCurCount(curUp->GetCurCount() + reserve);
				// 이전 아이템은 차분만큼 빼주며 자리를 옮기진 않는다
				prevItem->SetCurCount(prevItem->GetCurCount() - reserve);
				// 근데 만약에 prevItemCount가 0이라면 nullptr로 바꿔줘야함
				if (prevItem->GetCurCount() == 0) {
					mgr->RemoveItem(prevIndex);
				}
			}
			// 맥스카운트라면 그냥 암것도 안함
			else {
				return;
			}

		}
		// 다른 아이템이라면 위치 바꾸기
		else {

			mgr->SwapInventory(prevIndex, index);

		}
		// 아니라면 스왑
	}

	// 인벤토리 패널 가져와서 업데이트 해준다
	shopInvPanel->updateValue();
	
}
