#include "stdafx.h"
#include "SideNavUpdateVal.h"
#include "DivUI.h"
#include "GameMgr.h"
#include "CHero.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "DivUI.h"

SideNavUpdateVal::SideNavUpdateVal(DivUI* _myUI)
	: myUI{_myUI}
{
}

void SideNavUpdateVal::Execute()
{
	// 여기서는 히어로 패널의 순서와 로스터 순서가 동일하다는 가정 하에 로직을 짜고 있음
	vector<UI*> heroPanels = myUI->GetChildUI();

	const vector<CHero*>& curLoster = GameMgr::GetInst()->GetCurLoster();
	//

	const array<CHero*, 4> squad = GameMgr::GetInst()->GetSquad();

	// 효율이 좋지는 않은데 2중 포문 돌려야될듯

	for (int i = 0; i < heroPanels.size(); i++) {

		DivUI* heroPanel = (DivUI*)heroPanels[i];
		DivUI* heroPortrait = (DivUI*)(heroPanel->GetChildUI()[0]);
		heroPanel->CanTarget(true);
		heroPortrait->InitImageModule(curLoster[i]->GetKey(), curLoster[i]->GetPath());
	}

	for (int i = 0; i < heroPanels.size(); i++) {

		DivUI* heroPanel = (DivUI*)heroPanels[i];

		for (int j = 0; j < 4; j++) {

			// 이름이 중복될 수 없다고 가정함 실제 게임에서는 로스터에 들어오면 인덱스를 부여하는거같음
			if (nullptr != squad[j] && squad[j]->GetPKey() == heroPanel->GetId()) {
				// 여기서 초상화 그레이 스케일 및 히어로 패널 비활성화
				heroPanel->CanTarget(false);
				
				// 일단 비활성화만 해보자
				DivUI* heroPortrait = (DivUI*)(heroPanel->GetChildUI()[0]);
				heroPortrait->InitImageModule(squad[j]->GetGrayKey(), squad[j]->GetGrayPath());
			}
		}

	}
}
