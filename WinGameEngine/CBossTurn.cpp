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

	// 현재 턴인 몬스터는 오버레이 켜주고 
	monSquad->EnableOverlay(curMIdx);

	// 공격 대상인 캐릭터는 피격 오버레이 켜줘야됨
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

	// 영웅 인덱스는 2~3번중에 하나 골라라...
	// 그냥 첫번째 스킬 써라...
	curSkil = mSkils[skIndex];
	sIdx = skIndex;


	skIndex += 1;
	if (skIndex > 3) skIndex = 0;
	


	

	

	skilTitleUI = (DivUI*)FindUIByName(pseudoUI, L"skilTitle");
	wstring skilName = curSkil->GetSkillName();
	skilTitleUI->InitTextModule(skilName, 40);
	skilTitleUI->SetCanRend(true);

	// 사운드 재생
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
		// 스킬 인덱스도 세팅
		mgr->SetSIndex(sIdx);
		heroSquad->EnableAttackedOverlay(heroIdx);
	}

	// 사용 가능한 스킬과 피격대상인 영웅을 찾았으므로 게임매니저에서 해당 영웅을 포커싱해주고
	// 이떄 인덱스는 게임매니저인덱스(실제인덱스임)
	

	// 현재 위치에서 사용 가능한 스킬 바탕으로 스킬 인덱스를 지정해줌

	// 시간을 기다린다음에 알아서 넘겨야됨
	canCg = true;

}

void CBossTurn::Update()
{
	elapsedTime += fDT;

	if (elapsedTime >= 3.f && canCg) {

		canCg = false;

		// 컷씬으로 상태이동 시킬떄 항상 입력값을 초기화 하자
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
