#include "stdafx.h"
#include "CMonSquad.h"
#include "GameMgr.h"
#include "DarkestMachine.h"
#include "CMonDiv.h"

CMonSquad::CMonSquad()
{
}

CMonSquad::~CMonSquad()
{
	for (int i = 0; i < deadDivs.size(); i++) {
		delete deadDivs[i];
		deadDivs[i] = nullptr;
	}

	deadDivs.clear();
}

void CMonSquad::update()
{
	GameMgr::GetInst()->GetMachine()->update();

	DivUI::update();
}

void CMonSquad::PlayIdleCombatAnim()
{
	for (int i = 0; i < monDivs.size(); i++) {
		//monDivs[i]->
	}
}

void CMonSquad::MoveToFrontMonDiv(int _idx)
{
	vector<UI*>& vec = GetChildUI();

	UI* curItem = vec[_idx];

	vec.erase(vec.begin() + _idx);

	vec.insert(vec.begin(), curItem);
}

void CMonSquad::MoveToBackRender(int _idx)
{
	// 렌더를 한 다음에는 다시 id 순서대로 정렬을 시켜줘야함..

	vector<UI*>& vec = GetChildUI();

	std::sort(vec.begin(), vec.end(), [](UI* a, UI* b) {
		DivUI* new_a = (DivUI*)a;
		DivUI* new_b = (DivUI*)b;

		return new_a->GetId() < new_b->GetId();
		});

	int realIdx = _idx ;

	UI* curItem = vec[realIdx];

	vec.erase(vec.begin() + realIdx);

	vec.push_back(curItem);
}

void CMonSquad::EnableAllDivChildUI(bool _isEnable)
{
	for (int i = 0; i < monDivs.size(); i++) {
		monDivs[i]->EnableAllChildUI(_isEnable);
	}
}

void CMonSquad::EnableOverlay(int _realIndex)
{
	for (int i = 0; i < monDivs.size(); i++) {
		if (monDivs[i]->GetId() == _realIndex) {
			monDivs[i]->EnableOverlay(true);
		}
		else {
			monDivs[i]->EnableOverlay(false);
		}
	}
}

void CMonSquad::DisableAllOverlay()
{
	for (int i = 0; i < monDivs.size(); i++) {
		monDivs[i]->EnableOverlay(false);
	}
}

void CMonSquad::SortChildUI()
{
	vector<UI*>& vec = GetChildUI();

	std::sort(vec.begin(), vec.end(), [](UI* a, UI* b) {
		DivUI* new_a = (DivUI*)a;
		DivUI* new_b = (DivUI*)b;

		return new_a->GetId() < new_b->GetId();
		});
}

void CMonSquad::EraseDiv(int _idx)
{
	vector<UI*>& vec = GetChildUI();

	deadDivs.push_back((CMonDiv*)vec[_idx]);

	vec.erase(vec.begin() + _idx);
}

void CMonSquad::makeTargetMons(bool _enable)
{
	for (int i = 0; i < monDivs.size(); i++) {
		monDivs[i]->CanTarget(_enable);
	}
}

void CMonSquad::makeVisibleMons(bool _enable)
{
	for (int i = 0; i < monDivs.size(); i++) {
		monDivs[i]->SetCanRend(_enable);
	}
}

void CMonSquad::restorePos()
{
	SortChildUI();

	for (int i = 0; i < monDivs.size(); i++) {
		monDivs[i]->SetPos(Vec2(150.f * i, 0.f));
	}
}

void CMonSquad::updateHpBar()
{
	for (int i = 0; i < monDivs.size(); i++) {
		monDivs[i]->UpdateHpBar();
	}
}
