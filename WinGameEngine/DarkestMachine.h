#pragma once
#include "CStMachine.h"

class CSquadDiv;

class DarkestMachine :
	public CStMachine
{

private :

	// 이게 씬이 바뀔때마다 UI를 다시 생성할 거임
   // 씬이 바뀔때 플레이어를 다시 바꿔줄 필요가 있음
	CSquadDiv* player;

	void Init();

public :

	DarkestMachine();
	~DarkestMachine();

	void ClearPlayer() { player = nullptr; }
	void SetPlayer(CSquadDiv* _player) { player = _player; }
	CSquadDiv* GetPlayer() { return player; }

};

