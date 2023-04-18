#include "stdafx.h"
#include "CWaitState.h"

#include "TimeMgr.h"
#include "DivUI.h"
#include "SceneMgr.h"
#include "Scene.h"

#include "CSquadDiv.h"
#include "CMonSquad.h"
#include "CHeroDiv.h"

#include "GameMgr.h"
#include "CDarkMonster.h"
#include "CHero.h"
#include "CMap.h"
#include "CNode.h"

CWaitState::CWaitState()
	: CState(L"CWaitState")
	, elapsedTime{ 0.f }
	, isOnEye{false}
	, onEyeIdx{0}
{
}

CWaitState::~CWaitState()
{
}

bool compareSpeed(const Character& c1, const Character& c2) {
	return c1.speed > c2.speed;
}

void CWaitState::Enter()
{
	DivUI* pseudoUI = SceneMgr::GetInst()->GetCurScene()->GetPseudoUI();
	heroSquadDivs = (CSquadDiv*)FindUIByName(pseudoUI, L"CSquadDiv");
	monSquad = (CMonSquad*)FindUIByName(pseudoUI, L"CMonSquad");

	const array<CHero*, 4> heroSquad = GameMgr::GetInst()->GetSquad();
	const array<CDarkMonster*, 4> monSquad =GameMgr::GetInst()->GetMonSquad();

	std::random_device rd;
	std::mt19937 gen(rd());

	// 기본적으로 모든 onYouOvl 끄는 작업 필요

	heroSquadDivs->EnableAllOnYou(false);

	if (isOnEye) {
		int idx = onEyeIdx - 1;
		heroSquadDivs->GetHeroDivByIdx(idx)->EnableOnYouOvl(true);
	}

	// 1부터 6까지 랜덤한 숫자 생성
	std::uniform_int_distribution<int> dist(1, 6);
	int num = dist(gen);

	for (int i = 0; i < 4; i++) {
		if (nullptr != monSquad[i] && monSquad[i]->GetMonType() == L"나무") {
			monSquad[i]->SetCanTurn(false);
		}
	}

	for (int i = 0; i < 4; i++) {

		if (nullptr != heroSquad[i] && heroSquad[i]->GetCanTurn() && !heroSquad[i]->IsDead()) {
			characterList.push_back(Character(heroSquad[i]->GetSpeed() + dist(gen), L"hero", i));
		}

		if (nullptr != monSquad[i] && monSquad[i]->GetCanTurn() && !monSquad[i]->IsDead()) {
			characterList.push_back(Character(monSquad[i]->GetSpeed() + dist(gen), L"monster", i));
		}

	}

	std::sort(characterList.begin(), characterList.end(), compareSpeed);

	 
	// 모두 죽으면 그냥 Idle로 고
	

	if (GameMgr::GetInst()->checkMonDead()) {
		ChangeState(GetStateMachine(), L"CIdleState");
		characterList.clear();
	} /*else if (characterList.size() == 0) {
		ChangeState(GetStateMachine(), L"CIdleState");
	}*/
	else {
		curTurnPlayer = characterList[0];
	}

	characterList.clear();
}

void CWaitState::Update()
{
	elapsedTime += fDT;

	if (elapsedTime >= 2.f) {

		elapsedTime = 0.f;

		if (curTurnPlayer.type == L"hero") {
			const array<CHero*, 4> heroSquad = GameMgr::GetInst()->GetSquad();
			heroSquad[curTurnPlayer.index]->SetCanTurn(false);

			GameMgr::GetInst()->SetFocusIndex(curTurnPlayer.index);

			ChangeState(GetStateMachine(), L"CPlayerTurn");
		}
		else if (curTurnPlayer.type == L"monster") {
			const array<CDarkMonster*, 4> monSquad = GameMgr::GetInst()->GetMonSquad();
			monSquad[curTurnPlayer.index]->SetCanTurn(false);

			GameMgr::GetInst()->SetMonFocusIdx(curTurnPlayer.index);
			GameMgr* mgr = GameMgr::GetInst();
			CDarkMonster* dMon = mgr->GetFocusedMonster();

			if (dMon->GetName() == L"예언자") {
				ChangeState(GetStateMachine(), L"CBossTurn");
			}
			else {
				ChangeState(GetStateMachine(), L"CEnemyTurn");
			}
		}
	}
}

void CWaitState::Exit()
{
	elapsedTime = 0.f;

	GameMgr::GetInst()->CheckCanTurn();

	// 여기서 모든 히어로 스쿼드랑 몬스터 스쿼드 canTurn이 false면 다시 true로 만들어주자
	
}


