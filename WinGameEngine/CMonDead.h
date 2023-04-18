#pragma once
#include "CState.h"

class CSquadDiv;
class CMonSquad;
class CHeroDiv;
class CMonDiv;

class CMonDead :
	public CState
{
private :

	CSquadDiv* heroSquad;
	CMonSquad* monSquad;

	vector<CMonDiv*> moveDiv;
	vector<Vec2> startPos;
	vector<Vec2> toPos;
	float lerpTime;

	bool canCg;

public :

	CMonDead();
	~CMonDead();

	float elapsedTime;

	virtual void Enter() override;
	virtual void Update() override;
	virtual void Exit() override;

};

