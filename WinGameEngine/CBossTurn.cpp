#include "stdafx.h"
#include "CBossTurn.h"
#include "GameMgr.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "DivUI.h"
#include "CMonSquad.h"
#include "CSkill.h"
#include "CDarkMonster.h"
#include "ResMgr.h"
#include "Sound.h"
#include "CSquadDiv.h"
#include "CCutScene.h"
#include "TimeMgr.h"
#include "DarkestMachine.h"
#include "CWaitState.h"

CBossTurn::CBossTurn()
	: CState(L"CBossTurn")
	, elapsedTime{0.f}, canCg{true}, skIndex{0}, predictStart{true}
{
}

void CBossTurn::Enter()
{
	GameMgr* mgr = GameMgr::GetInst();

	DivUI* pseudoUI = SceneMgr::GetInst()->GetCurScene()->GetPseudoUI();

	heroSquad = (CSquadDiv*)FindUIByName(pseudoUI, L"CSquadDiv");
	monSquad = (CMonSquad*)FindUIByName(pseudoUI, L"CMonSquad");
	curMIdx = GameMgr::GetInst()->GetMonFocusIdx();
	curHIdx = GameMgr::GetInst()->GetFocusIndex();

	// ���� ���� ���ʹ� �������� ���ְ� 
	monSquad->EnableOverlay(curMIdx);

	// ���� ����� ĳ���ʹ� �ǰ� �������� ����ߵ�
	CDarkMonster* dMon = mgr->GetFocusedMonster();
	const array<CSkill*, 4> mSkils = dMon->GetCurSkills();

	CSkill* curSkil = nullptr;
	int heroIdx;
	int sIdx;

	heroIdx = rand() % 3 + 1;

	if (skIndex == 0) {

		prevSelected = heroIdx;
		CWaitState* wait = (CWaitState*)GetStateMachine()->GetState(L"CWaitState");
		wait->SetOnEye(true, heroIdx);
	}
	else if (skIndex == 1) {

		heroIdx = prevSelected;
		CWaitState* wait = (CWaitState*)GetStateMachine()->GetState(L"CWaitState");
		wait->SetOnEye(false, heroIdx);
	}

	// ���� �ε����� 2~3���߿� �ϳ� ����...
	// �׳� ù��° ��ų ���...
	curSkil = mSkils[skIndex];
	sIdx = skIndex;


	skIndex += 1;
	if (skIndex > 3) skIndex = 0;
	


	

	

	skilTitleUI = (DivUI*)FindUIByName(pseudoUI, L"skilTitle");
	wstring skilName = curSkil->GetSkillName();
	skilTitleUI->InitTextModule(skilName, 40);
	skilTitleUI->SetCanRend(true);

	// ���� ���
	ResMgr::GetInst()->LoadSound(L"EnemyTurnStartBgm", L"resource\\sound\\General\\gen_char_enemyturn {18396ce1-185d-44b3-bf2b-5ff32f0b9209}.wav");
	Sound* pTitleSound = ResMgr::GetInst()->FindSound(L"EnemyTurnStartBgm");

	pTitleSound->SetVolume(20.f);
	pTitleSound->Play(false);

	if (curSkil->GetMulti()) {
		mgr->SetFocusIndex(heroIdx);
		mgr->SetSIndex(sIdx);
		
		heroSquad->EnableAllAttackedOverlay();
	}
	else {
		mgr->SetFocusIndex(heroIdx);
		// ��ų �ε����� ����
		mgr->SetSIndex(sIdx);
		heroSquad->EnableAttackedOverlay(heroIdx);
	}

	// ��� ������ ��ų�� �ǰݴ���� ������ ã�����Ƿ� ���ӸŴ������� �ش� ������ ��Ŀ�����ְ�
	// �̋� �ε����� ���ӸŴ����ε���(�����ε�����)
	

	// ���� ��ġ���� ��� ������ ��ų �������� ��ų �ε����� ��������

	// �ð��� ��ٸ������� �˾Ƽ� �Ѱܾߵ�
	canCg = true;

}

void CBossTurn::Update()
{
	elapsedTime += fDT;

	if (elapsedTime >= 3.f && canCg) {

		canCg = false;

		// �ƾ����� �����̵� ��ų�� �׻� �Է°��� �ʱ�ȭ ����
		GameMgr* mgr = GameMgr::GetInst();
		CCutScene* cutState = (CCutScene*)(mgr->GetMachine()->GetState(L"CCutScene"));
		cutState->IsPlayerAttack(false);

		ChangeState(GetStateMachine(), L"CCutScene");
	}
}

void CBossTurn::Exit()
{
	skilTitleUI->SetCanRend(false);

	elapsedTime = 0.f;
}
