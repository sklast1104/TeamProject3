#include "stdafx.h"
#include "CStMachine.h"
#include "CState.h"

CStMachine::CStMachine()
    : curState{ nullptr }
{
}

CStMachine::~CStMachine()
{
    for (auto it = stateMap.begin(); it != stateMap.end(); ++it) {
        delete it->second;
    }
}

void CStMachine::update()
{
    curState->Update();
}

void CStMachine::AddState(CState* _state)
{
    CState* state = GetState(_state->GetStateKey());
    assert(!state);

    stateMap.insert(make_pair(_state->GetStateKey(), _state));
    _state->SetStateMachine(this);
}

CState* CStMachine::GetState(wstring stateKey)
{
    auto iter = stateMap.find(stateKey);
    if (iter == stateMap.end())
        return nullptr;

    return iter->second;
}

const wstring& CStMachine::GetCurStateName()
{
    return curState->GetStateKey();
}

void CStMachine::SetCurState(wstring stateKey)
{
    curState = GetState(stateKey);
}

void CStMachine::ChangeState(wstring stateKey)
{
    CState* nextState = GetState(stateKey);

    // 현재 상태가 다음 상태와 같으면 에러
    assert(curState != nextState);

    curState->Exit();

    curState = nextState;

    curState->Enter();
}
