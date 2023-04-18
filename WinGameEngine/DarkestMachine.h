#pragma once
#include "CStMachine.h"

class CSquadDiv;

class DarkestMachine :
	public CStMachine
{

private :

	// �̰� ���� �ٲ𶧸��� UI�� �ٽ� ������ ����
   // ���� �ٲ� �÷��̾ �ٽ� �ٲ��� �ʿ䰡 ����
	CSquadDiv* player;

	void Init();

public :

	DarkestMachine();
	~DarkestMachine();

	void ClearPlayer() { player = nullptr; }
	void SetPlayer(CSquadDiv* _player) { player = _player; }
	CSquadDiv* GetPlayer() { return player; }

};

