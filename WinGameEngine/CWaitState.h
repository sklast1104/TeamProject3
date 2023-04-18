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

	// 영웅 스쿼드
	CSquadDiv* heroSquadDivs;

	// 몬스터 스쿼드
	CMonSquad* monSquad;

	Character curTurnPlayer;

	// 주시 상태인지
	bool isOnEye;
	// 주시 영웅 인덱스는 뭔지 (onEye 상태면 인덱스 오버레이를 켜주고 아니면 꺼준다)
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

