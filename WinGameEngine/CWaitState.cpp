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

	// �⺻������ ��� onYouOvl ���� �۾� �ʿ�

	heroSquadDivs->EnableAllOnYou(false);

	if (isOnEye) {
		int idx = onEyeIdx - 1;
		heroSquadDivs->GetHeroDivByIdx(idx)->EnableOnYouOvl(true);
	}

	// 1���� 6���� ������ ���� ����
	std::uniform_int_distribution<int> dist(1, 6);
	int num = dist(gen);

	for (int i = 0; i < 4; i++) {
		if (nullptr != monSquad[i] && monSquad[i]->GetMonType() == L"����") {
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

	 
	// ��� ������ �׳� Idle�� ��
	

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

			if (dMon->GetName() == L"������") {
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

	// ���⼭ ��� ����� ������� ���� ������ canTurn�� false�� �ٽ� true�� ���������
	
}


