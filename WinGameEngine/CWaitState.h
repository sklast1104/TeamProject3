#pragma once
#include "CState.h"

class CSquadDiv;
class CMonSquad;
class CTurnPlayer;

struct Character {
	int speed;
	wstring type;
	int index;

	Character() {}

	Character(int _speed, std::wstring _type, int _index)
		: speed(_speed), type(_type), index(_index) {}
};

class CWaitState :
	public CState
{
private :

	vector<Character> characterList;

	// ���� ������
	CSquadDiv* heroSquadDivs;

	// ���� ������
	CMonSquad* monSquad;

	Character curTurnPlayer;

	// �ֽ� ��������
	bool isOnEye;
	// �ֽ� ���� �ε����� ���� (onEye ���¸� �ε��� �������̸� ���ְ� �ƴϸ� ���ش�)
	int onEyeIdx;
	// 

	virtual void Enter() override;
	virtual void Update() override;
	virtual void Exit() override;

	float elapsedTime;

public :

	CWaitState();
	~CWaitState();

	void SetOnEye(bool _isOnEye, int _eyeIdx) { isOnEye = _isOnEye; onEyeIdx = _eyeIdx; }
};

