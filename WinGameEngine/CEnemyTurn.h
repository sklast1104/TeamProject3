#pragma once
#include "CState.h"

class CSquadDiv;
class CMonSquad;
class DivUI;

class CEnemyTurn :
	public CState
{
private :

	// ���� ������
	CSquadDiv* heroSquad;

	// ���� ������
	CMonSquad* monSquad;

	// ��ų Ÿ��Ʋ
	DivUI* skilTitleUI;

	// ���� ��Ŀ������ ���� �ε���
	int curMIdx;
	int curHIdx;

	virtual void Enter() override;
	virtual void Update() override;
	virtual void Exit() override;

	float elapsedTime;
	bool canCg;

public :

	CEnemyTurn();
	~CEnemyTurn();

};

