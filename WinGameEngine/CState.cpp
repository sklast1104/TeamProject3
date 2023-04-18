#include "stdafx.h"
#include "CState.h"

CState::CState(wstring _stateKey)
	: stateKey{ _stateKey }
	, stateMachine{ nullptr }
{
}

CState::~CState()
{
}
