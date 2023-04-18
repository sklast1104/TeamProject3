#pragma once
#include "CState.h"

class CSquadDiv;
class CMonSquad;
class DivUI;

class CBossTurn :
	public CState
{

private :

	// 영웅 스쿼드
	CSquadDiv* heroSquad;

	// 몬스터 스쿼드
	CMonSquad* monSquad;

	// 스킬 타이틀
	DivUI* skilTitleUI;

	// 현재 포커싱중인 몬스터 인덱스
	int curMIdx;
	int curHIdx;

	virtual void Enter() override;
	virtual void Update() override;
	virtual void Exit() override;

	float elapsedTime;
	bool canCg;

	int skIndex;
	bool predictStart;
	int prevSelected;
public :

	CBossTurn();
	~CBossTurn() {}

};

