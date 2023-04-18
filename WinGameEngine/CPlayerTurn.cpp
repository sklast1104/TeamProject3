#include "stdafx.h"
#include "CPlayerTurn.h"
#include "GameMgr.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "CSquadDiv.h"
#include "CMonSquad.h"
#include "ResMgr.h"
#include "Sound.h"

CPlayerTurn::CPlayerTurn()
	: CState(L"CPlayerTurn")
{
}

CPlayerTurn::~CPlayerTurn()
{
}

void CPlayerTurn::Enter()
{
	DivUI* pseudoUI = SceneMgr::GetInst()->GetCurScene()->GetPseudoUI();

	heroSquad = (CSquadDiv*)FindUIByName(pseudoUI, L"CSquadDiv");
	monSquad = (CMonSquad*)FindUIByName(pseudoUI, L"CMonSquad");
	curHeroIndex = GameMgr::GetInst()->GetFocusIndex();

	// 현재 턴인 캐릭터만 포커싱

	heroSquad->EnableFocus(curHeroIndex);

	// 현재위치에서 사용 가능한 스킬 활성화 및 비활성화
	heroSquad->EnableSkill(curHeroIndex);

	// 스킬 포커스 UI도 비활성화 해두자
	vector<UI*> vec = FindUIsByName(pseudoUI, L"skillSelected");
	for (int i = 0; i < vec.size(); i++) {
		((DivUI*)(vec[i]))->SetCanRend(false);
	}

	monSquad->SortChildUI();
	// 플레이어 턴일떄 항상 몬스터 스쿼드 렌더도 다시 정렬시켜줘야함
}

void CPlayerTurn::Update()
{
}

void CPlayerTurn::Exit()
{
}


