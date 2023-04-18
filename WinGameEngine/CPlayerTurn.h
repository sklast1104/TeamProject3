#pragma once
#include "CState.h"

class CSquadDiv;
class CMonSquad;

class CPlayerTurn :
	public CState
{
private :

	// 영웅 스쿼드
	CSquadDiv* heroSquad;

	// 몬스터 스쿼드
	CMonSquad* monSquad;

	// Wait에서 계산된 현재 포커싱된 영웅 인덱스
	int curHeroIndex;

	virtual void Enter() override;
	virtual void Update() override;
	virtual void Exit() override;

public :

	CPlayerTurn();
	~CPlayerTurn();
};

