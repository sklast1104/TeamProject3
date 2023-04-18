#pragma once
#include "CState.h"

class CSquadDiv;
class CMonSquad;

class CIdleState :
	public CState
{
private :

	CSquadDiv* hSquad;
	CMonSquad* mSquad;
	wstring sName;
	bool gameEnd;

	virtual void Enter() override;
	virtual void Update() override;
	virtual void Exit() override;

public :

	CIdleState();
	~CIdleState();
};

