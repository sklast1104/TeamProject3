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
	// ���⼭�� ����� �г��� ������ �ν��� ������ �����ϴٴ� ���� �Ͽ� ������ ¥�� ����
	vector<UI*> heroPanels = myUI->GetChildUI();

	const vector<CHero*>& curLoster = GameMgr::GetInst()->GetCurLoster();
	//

	const array<CHero*, 4> squad = GameMgr::GetInst()->GetSquad();

	// ȿ���� ������ ������ 2�� ���� �����ߵɵ�

	for (int i = 0; i < heroPanels.size(); i++) {

		DivUI* heroPanel = (DivUI*)heroPanels[i];
		DivUI* heroPortrait = (DivUI*)(heroPanel->GetChildUI()[0]);
		heroPanel->CanTarget(true);
		heroPortrait->InitImageModule(curLoster[i]->GetKey(), curLoster[i]->GetPath());
	}

	for (int i = 0; i < heroPanels.size(); i++) {

		DivUI* heroPanel = (DivUI*)heroPanels[i];

		for (int j = 0; j < 4; j++) {

			// �̸��� �ߺ��� �� ���ٰ� ������ ���� ���ӿ����� �ν��Ϳ� ������ �ε����� �ο��ϴ°Ű���
			if (nullptr != squad[j] && squad[j]->GetPKey() == heroPanel->GetId()) {
				// ���⼭ �ʻ�ȭ �׷��� ������ �� ����� �г� ��Ȱ��ȭ
				heroPanel->CanTarget(false);
				
				// �ϴ� ��Ȱ��ȭ�� �غ���
				DivUI* heroPortrait = (DivUI*)(heroPanel->GetChildUI()[0]);
				heroPortrait->InitImageModule(squad[j]->GetGrayKey(), squad[j]->GetGrayPath());
			}
		}

	}
}
