#include "stdafx.h"
#include "CBStartState.h"
#include "TimeMgr.h"
#include "ResMgr.h"
#include "Sound.h"
#include "GameMgr.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "CSquadDiv.h"
#include "CMonSquad.h"
#include "ResMgr.h"
#include "Sound.h"
#include "Animator.h"

CBStartState::CBStartState()
	: CState(L"CBStartState")
	, elapsedTime{0.f}
{
}

CBStartState::~CBStartState()
{
}

void CBStartState::Enter()
{
	DivUI* pseudoUI = SceneMgr::GetInst()->GetCurScene()->GetPseudoUI();

	CSquadDiv* heroSquad = (CSquadDiv*)FindUIByName(pseudoUI, L"CSquadDiv");
	CMonSquad* monSquad = (CMonSquad*)FindUIByName(pseudoUI, L"CMonSquad");
	int curHeroIndex = GameMgr::GetInst()->GetFocusIndex();

	heroSquad->DisableAllOverlay();
	heroSquad->PlayHeroCombatAnim();

	GameMgr::GetInst()->MakeSquadAlive();
	GameMgr::GetInst()->MakeTurnAlive();
	
	bStartDiv = (DivUI*)FindUIByName(pseudoUI, L"bStartAnim");
	bStartDiv->SetCanRend(true);
	bStartDiv->LoadAnimation(L"combat_start_Animation", L"resource\\animations\\combatAnim\\combat.sprite-start.atlas", false);

	ResMgr::GetInst()->LoadSound(L"BattleBgm", L"resource\\sound\\Music\\Mournweald_LEVEL1_LOOP1_V11 {0d6aa3c6-221d-442e-9ab0-99501ca8f77f}.wav");
	Sound* battleBgm = ResMgr::GetInst()->FindSound(L"BattleBgm");

	battleBgm->SetVolume(20.f);
	battleBgm->PlayToBGM(true);

	ResMgr::GetInst()->LoadSound(L"combatStartSound", L"resource\\sound\\General\\gen_combat_start {31daf92c-48a5-49f5-acc4-6e423f18f697}.wav");
	Sound* combatStartSound = ResMgr::GetInst()->FindSound(L"combatStartSound");

	combatStartSound->SetVolume(20.f);
	combatStartSound->Play(false);

	ResMgr::GetInst()->LoadSound(L"skelAggro1", L"resource\\sound\\Monsters\\Ruins\\char_en_vo_skel_aggro_03 {b20ada07-a207-4e2b-9069-49c40caad787}.wav");
	Sound* skelAggro1 = ResMgr::GetInst()->FindSound(L"skelAggro1");

	skelAggro1->SetVolume(20.f);
	skelAggro1->Play(false);

	monSquad->SetCanRend(true);
	monSquad->makeTargetMons(true);
	monSquad->makeVisibleMons(true);
	monSquad->restorePos();
	monSquad->updateHpBar();
}

void CBStartState::Update()
{
	elapsedTime += fDT;

	if (elapsedTime >= 2.f) {

		elapsedTime = 0.f;

		ChangeState(GetStateMachine(), L"CWaitState");
	}
}

void CBStartState::Exit()
{
	bStartDiv->SetCanRend(false);

	elapsedTime = 0.f;
}


