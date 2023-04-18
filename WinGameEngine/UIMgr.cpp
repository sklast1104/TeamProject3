#include "stdafx.h"
#include "UIMgr.h"

#include "KeyMgr.h"
#include "UI.h"

#include "Scene.h"
#include "SceneMgr.h"

UIMgr::UIMgr()
	: m_pFocusedUI{ nullptr }
{

}

UIMgr::~UIMgr() {

}

void UIMgr::update()
{
	m_pFocusedUI = GetFocusedUI();

	if (!m_pFocusedUI) {
		return;
	}

	bool bLbtnTap = KEY_TAP(KEY::LBTN);
	bool bLbtnAway = KEY_AWAY(KEY::LBTN);

	UI* pTargetUI = GetTargetedUI(m_pFocusedUI);

	if (nullptr != pTargetUI) {

		pTargetUI->MouseOn();

		if (bLbtnTap) {
			pTargetUI->MouseLbtnDown();
			pTargetUI->m_bLbtnDown = true;
		}
		else if (bLbtnAway) {
			pTargetUI->MouseLbtnUp();

			if (pTargetUI->m_bLbtnDown) {
				pTargetUI->MouseLbtnClicked();
			}

			// 왼쪽 버튼 떄면 눌렸던 체크를 다시 해제
			pTargetUI->m_bLbtnDown = false;
		}

	}
}

void UIMgr::SetFocusedUI(UI* _pUI)
{
	if (m_pFocusedUI == _pUI || nullptr == _pUI) {
		m_pFocusedUI = _pUI;
		return;
	}

	m_pFocusedUI = _pUI;

	Scene* pCurScene = SceneMgr::GetInst()->GetCurScene();
	vector<Object*>& vecUI = pCurScene->GetUIGroup();

	vector<Object*>::iterator iter = vecUI.begin();

	for (; iter != vecUI.end(); ++iter) {
		if (m_pFocusedUI == *iter) {
			break;
		}
	}

	vecUI.erase(iter);
	vecUI.push_back(m_pFocusedUI);
}

UI* UIMgr::GetFocusedUI()
{
	Scene* pCurScene = SceneMgr::GetInst()->GetCurScene();
	vector<Object*>& vecUI = pCurScene->GetUIGroup();

	bool bLbtnTap = KEY_TAP(KEY::LBTN);

	UI* pFocusedUI = m_pFocusedUI;

	if (!bLbtnTap) {
		return pFocusedUI;
	}

	vector<Object*>::iterator targetiter = vecUI.end();
	vector<Object*>::iterator iter = vecUI.begin();

	for (; iter != vecUI.end(); ++iter) {
		if (((UI*)*iter)->IsMouseOn()) {
			targetiter = iter;
		}
	}

	if (vecUI.end() == targetiter) {
		return nullptr;
	}

	pFocusedUI = (UI*)*targetiter;

	vecUI.erase(targetiter);

	vecUI.push_back(pFocusedUI);

	return pFocusedUI;
}

UI* UIMgr::GetTargetedUI(UI* _pParentUI)
{
	bool bLbtnAway = KEY_AWAY(KEY::LBTN);

	UI* pTargetUI = nullptr;

	// 1. 부모 UI 포함, 모든 자식들을 검사 한다.
	static list<UI*> queue;
	static vector<UI*> vecNoneTarget;

	queue.clear();
	vecNoneTarget.clear();

	queue.push_back(_pParentUI);

	while (!queue.empty()) {

		UI* pUI = queue.front();
		queue.pop_front();

		if (pUI->IsMouseOn() && pUI->isCanTarget()) {

			if (nullptr != pTargetUI) {
				vecNoneTarget.push_back(pTargetUI);
			}

			pTargetUI = pUI;
		}
		else {
			vecNoneTarget.push_back(pUI);
		}

		const vector<UI*>& vecChild = pUI->GetChildUI();
		for (size_t i = 0; i < vecChild.size(); ++i) {
			queue.push_back(vecChild[i]);
		}
	}

	if (bLbtnAway) {
		for (size_t i = 0; i < vecNoneTarget.size(); ++i) {
			vecNoneTarget[i]->m_bLbtnDown = false;
		}
	}

	return pTargetUI;
}


