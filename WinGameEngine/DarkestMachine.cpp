#include "stdafx.h"
#include "DarkestMachine.h"
#include "CIdleState.h"
#include "CWaitState.h"
#include "CPlayerTurn.h"
#include "CEnemyTurn.h"
#include "CBStartState.h"
#include "CCutScene.h"
#include "CRestoreState.h"
#include "CMonDead.h"
#include "CBossTurn.h"

DarkestMachine::DarkestMachine()
	: player{ nullptr }
{
	Init();
}

DarkestMachine::~DarkestMachine()
{

}

// 한번만 호출해야됨 (State 초기화 하는 역할)
void DarkestMachine::Init()
{
	this->AddState(new CIdleState);
	this->AddState(new CWaitState);
	this->AddState(new CBStartState);
	this->AddState(new CPlayerTurn);
	this->AddState(new CEnemyTurn);
	this->AddState(new CCutScene);
	this->AddState(new CRestoreState);
	this->AddState(new CMonDead);
	this->AddState(new CBossTurn);

	this->SetCurState(L"CIdleState");
}
