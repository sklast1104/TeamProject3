#pragma once

class CStMachine;

class CState
{
private :
	// state머신은 state머신에서 상태 초기화할떄 주입
	CStMachine* stateMachine;

	wstring stateKey;

public :

	void SetStateMachine(CStMachine* _stateMachine) { stateMachine = _stateMachine; }
	CStMachine* GetStateMachine() const { return stateMachine; }
	const wstring& GetStateKey() const { return stateKey; }

	virtual void Update() = 0;
	virtual void Enter() = 0;
	virtual void Exit() = 0;

	CState(wstring _stateKey);
	virtual ~CState();
};

