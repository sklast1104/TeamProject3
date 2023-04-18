#pragma once
#include "CState.h"

class CSquadDiv;
class CMonSquad;

class CPlayerTurn :
	public CState
{
private :

	// ���� ������
	CSquadDiv* heroSquad;

	// ���� ������
	CMonSquad* monSquad;

	// Wait���� ���� ���� ��Ŀ�̵� ���� �ε���
	int curHeroIndex;

	virtual void Enter() override;
	virtual void Update() override;
	virtual void Exit() override;

public :

	CPlayerTurn();
	~CPlayerTurn();
};

