#include "stdafx.h"
#include "KeyMgr.h"

#include "Core.h"

int g_arrVK[(int)KEY::LAST] =
{
	VK_LEFT,
	VK_RIGHT,
	VK_UP,
	VK_DOWN,
	'Q','W','E','R','T','Y','U','I','O','P',
	'A','S','D','F','G','Z','X','C','V','B',
	VK_MENU, VK_CONTROL, VK_LSHIFT, VK_SPACE, VK_RETURN, VK_ESCAPE,
	VK_LBUTTON, VK_RBUTTON,
};

KeyMgr::KeyMgr() {

}

KeyMgr::~KeyMgr() {

}

void KeyMgr::init()
{
	for (int i = 0; i < (int)KEY::LAST; ++i) {
		m_vecKey.push_back(tKeyInfo{ KEY_STATE::NONE, false });
	}
}

void KeyMgr::update()
{
	HWND hWnd = GetFocus();

	if (nullptr != hWnd) {
		for (int i = 0; i < (int)KEY::LAST; ++i) {
			if (GetAsyncKeyState(g_arrVK[i]) & 0x8000) {
				if (m_vecKey[i].bPrevPush) {
					m_vecKey[i].eState = KEY_STATE::HOLD;
				}
				else {
					m_vecKey[i].eState = KEY_STATE::TAP;
				}

				m_vecKey[i].bPrevPush = true;
			}
			else {
				if (m_vecKey[i].bPrevPush) {
					m_vecKey[i].eState = KEY_STATE::AWAY;
				}
				else {
					m_vecKey[i].eState = KEY_STATE::NONE;
				}

				m_vecKey[i].bPrevPush = false;
			}
		}

		// Mouse 위치 계산
		POINT ptPos = {};
		GetCursorPos(&ptPos);
		ScreenToClient(Core::GetInst()->GetMainHwnd(), &ptPos);

		m_vCurMousePos = D3DXVECTOR3((float)ptPos.x, (float)ptPos.y, 0.f);
	}
	else {
		for (int i = 0; i < (int)KEY::LAST; ++i) {
			m_vecKey[i].bPrevPush = false;

			if (KEY_STATE::TAP == m_vecKey[i].eState || KEY_STATE::HOLD == m_vecKey[i].eState) {
				m_vecKey[i].eState = KEY_STATE::AWAY;
			}
			else if (KEY_STATE::AWAY == m_vecKey[i].eState) {
				m_vecKey[i].eState = KEY_STATE::NONE;
			}
		}
	}
}
