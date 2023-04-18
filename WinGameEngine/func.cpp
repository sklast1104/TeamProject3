#include "stdafx.h"
#include "func.h"

#include "EventMgr.h"
#include "UI.h"

void CreateObject(Object* _pObj, GROUP_TYPE _eGroup)
{
	tEvent evn = {};
	evn.eEven = EVENT_TYPE::CREATE_OBJECT;
	evn.IParam = (DWORD_PTR)_pObj;
	evn.wParam = (DWORD_PTR)_eGroup;

	EventMgr::GetInst()->AddEvent(evn);
}

void DeleteObject(Object* _pObj)
{
	tEvent evn = {};
	evn.eEven = EVENT_TYPE::DELETE_OBJECT;
	evn.IParam = (DWORD_PTR)_pObj;

	EventMgr::GetInst()->AddEvent(evn);
}

void ChangeScene(SCENE_TYPE _eNext)
{
	tEvent evn = {};
	evn.eEven = EVENT_TYPE::SCENE_CHANGE;
	evn.IParam = (DWORD_PTR)_eNext;

	EventMgr::GetInst()->AddEvent(evn);
}

void ChangeState(CStMachine* _stMachine, wstring _stateKey)
{
	tEvent evn = {};
	evn.eEven = EVENT_TYPE::STATE_CHANGE;
	evn.IParam = (DWORD_PTR)_stMachine;
	evn.wstrParam = _stateKey;

	EventMgr::GetInst()->AddEvent(evn);
}

UI* FindUIByName(UI* _parentUI, wstring _name)
{
	if (_parentUI->GetName() == _name) {
		return _parentUI;
	}

	for (int i = 0; i < _parentUI->GetChildUI().size(); i++) {

		UI* result = FindUIByName(_parentUI->GetChildUI()[i], _name);

		if (nullptr != result) return result;

	}

	return nullptr;
}

vector<UI*> FindUIsByName(UI* parentUI, const std::wstring& name)
{
	std::vector<UI*> result;

	if (parentUI->GetName() == name) {
		result.push_back(parentUI);
	}

	for (const auto& childUI : parentUI->GetChildUI()) {
		std::vector<UI*> childResult = FindUIsByName(childUI, name);
		result.insert(result.end(), childResult.begin(), childResult.end());
	}

	return result;
}

void FScanf(char* _pOutBuff, FILE* _pFile)
{
	int i = 0;
	while (true) {
		char c = (char)getc(_pFile);
		if (c == '\n') {

			_pOutBuff[i++] = '\0';
			break;
		}


		_pOutBuff[i++] = c;
	}
}
