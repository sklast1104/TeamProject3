#pragma once

class CState;

class CStMachine
{
protected :

	unordered_map<wstring, CState*> stateMap;

	CState* curState;

public :

	CStMachine();
	virtual ~CStMachine();

	void update();

	void AddState(CState* state);
	CState* GetState(wstring stateKey);
	const wstring& GetCurStateName();

	void SetCurState(wstring stateKey);
	void ChangeState(wstring stateKey);

};

