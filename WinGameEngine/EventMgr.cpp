#include "stdafx.h"
#include "EventMgr.h"

#include "Scene.h"
#include "SceneMgr.h"
#include "UIMgr.h"

#include "Object.h"
#include "CStMachine.h"

EventMgr::EventMgr() {

}

EventMgr::~EventMgr() {

}

void EventMgr::Execute(const tEvent& _eve)
{
	switch (_eve.eEven) {
		case EVENT_TYPE::CREATE_OBJECT:
		{
			// lParam : Object Address
			// wParam : Group Type

			Object* pNewObj = (Object*)_eve.IParam;
			GROUP_TYPE eType = (GROUP_TYPE)_eve.wParam;

			SceneMgr::GetInst()->GetCurScene()->AddObject(pNewObj, eType);

			break;
		}
		case EVENT_TYPE::DELETE_OBJECT: {

			Object* pDeadObj = (Object*)_eve.IParam;

			if (!pDeadObj->isDead()) {
				pDeadObj->SetDead();
				m_vecDead.push_back(pDeadObj);
			}

			break;
		}
									  
		case EVENT_TYPE::SCENE_CHANGE:
		{
			// lParam : Next Scene Type
			// 씬 변경
			SceneMgr::GetInst()->ChangeScene((SCENE_TYPE)_eve.IParam);
			// 포커스 해제
			UIMgr::GetInst()->SetFocusedUI(nullptr);
			break;
		}
		case EVENT_TYPE::STATE_CHANGE:
		{
			// IParam : CStMachine*
			// wstrParam : Next Type (wstring)

			CStMachine* stMachine = (CStMachine*)_eve.IParam;

			stMachine->ChangeState(_eve.wstrParam);

			break;
		}
	}
}

void EventMgr::update()
{
	for (size_t i = 0; i < m_vecDead.size(); ++i) {
		delete m_vecDead[i];
	}
	m_vecDead.clear();

	// Event 처리

	for (size_t i = 0; i < m_vecEvent.size(); ++i) {
		Execute(m_vecEvent[i]);
	}

	m_vecEvent.clear();
}
