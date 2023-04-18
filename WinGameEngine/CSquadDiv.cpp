#include "stdafx.h"
#include "CSquadDiv.h"
#include "CHeroDiv.h"
#include "GameMgr.h"
#include "DarkestMachine.h"
#include "SceneMgr.h"
#include "Scene.h"


CSquadDiv::CSquadDiv()
	: speed{600.f}
{
}

CSquadDiv::~CSquadDiv()
{
}

void CSquadDiv::update()
{
	GameMgr::GetInst()->GetMachine()->update();

	DivUI::update();
}

void CSquadDiv::PlayHeroIdleAnim()
{
	for (int i = 0; i < heros.size(); i++) {
		heros[i]->PlayHeroIdleAnim();
	}
}

void CSquadDiv::PlayHeroWalkAnim()
{
	for (int i = 0; i < heros.size(); i++) {
		heros[i]->PlayHeroWalkAnim();
	}
}

void CSquadDiv::PlayHeroCombatAnim()
{
	for (int i = 0; i < heros.size(); i++) {
		heros[i]->PlayHeroCombatAnim();
	}
}

void CSquadDiv::EnableOverlay(int _realIndex)
{
	for (int i = 0; i < heros.size(); i++) {
		if (heros[i]->GetId() == _realIndex) {
			heros[i]->EnableOverlay(true);
		}
		else {
			heros[i]->EnableOverlay(false);
		}
	}
}

void CSquadDiv::DisableAllOverlay()
{
	for (int i = 0; i < heros.size(); i++) {
		heros[i]->EnableOverlay(false);
	}
}

void CSquadDiv::EnableFocus(int _realIndex)
{
	for (int i = 0; i < heros.size(); i++) {

		if (heros[i]->GetId() == _realIndex) {
			heros[i]->CanTarget(true);
			heros[i]->EnableOverlay(true);
			// 메인 레프트 패널도 갱신 해줘야함
			// 이 함수를 호출하는 순간 포커싱은 이미 계산되있다고 가정
			DivUI* pseudoUI = SceneMgr::GetInst()->GetCurScene()->GetPseudoUI();
			DivUI* mainLeftPanel = (DivUI*)FindUIByName(pseudoUI, L"mainLeftPanel");

			mainLeftPanel->updateValue();
		}
		else {
			heros[i]->CanTarget(false);
			heros[i]->EnableOverlay(false);
		}

	}
}

void CSquadDiv::EnableSkill(int _realIndex)
{
	GameMgr* mgr = GameMgr::GetInst();

	// 게임매니저 슬롯은 3
	// 벡터에서는1
	// 4 - 벡터 사이즈만큼 빼준다

	heros[_realIndex - (4 - heros.size())]->EnableSkill();
}

void CSquadDiv::MoveToFrontMonDiv(int _idx)
{
	vector<UI*>& vec = GetChildUI();

	int realIdx = _idx - (4 - heros.size());

	UI* curItem = vec[realIdx];

	vec.erase(vec.begin() + realIdx);

	vec.insert(vec.begin(), curItem);
}

void CSquadDiv::MoveToBackRender(int _idx)
{
	vector<UI*>& vec = GetChildUI();

	std::sort(vec.begin(), vec.end(), [](UI* a, UI* b) {
		DivUI* new_a = (DivUI*)a;
		DivUI* new_b = (DivUI*)b;

		return new_a->GetId() < new_b->GetId();
		});

	int realIdx = _idx - (4 - heros.size());

	UI* curItem = vec[realIdx];

	vec.erase(vec.begin() + realIdx);

	vec.push_back(curItem);
}

void CSquadDiv::EnableAllDivChildUI(bool _isEnable)
{
	for (int i = 0; i < heros.size(); i++) {

		heros[i]->EnableAllChildUI(_isEnable);
	}
}

void CSquadDiv::EnableAttackedOverlay(int _idx)
{
	heros[_idx - (4 - heros.size())]->EnableAttackedOverlay(true);
}

void CSquadDiv::EnableAllAttackedOverlay()
{
	for (int i = 0; i < heros.size(); i++) {
		heros[i]->EnableAttackedOverlay(true);
	}
}

void CSquadDiv::EnableAllCanTarget()
{
	for (int i = 0; i < heros.size(); i++) {
		heros[i]->CanTarget(true);
	}
}

void CSquadDiv::EnableAllOnYou(bool _isEnable)
{
	for (int i = 0; i < heros.size(); i++) {
		heros[i]->EnableOnYouOvl(_isEnable);
	}
}
