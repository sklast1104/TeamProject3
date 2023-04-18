#pragma once

enum class KEY_STATE {
	TAP, // 막 누른 시점
	HOLD, // 누르고 있는
	AWAY, // 막 뗀 시점
	NONE, // 눌리지 않음
};

enum class KEY {
	LEFT,
	RIGHT,
	UP,
	DOWN,
	Q, W, E, R, T, Y, U, I, O, P,
	A, S, D, F, G, Z, X, C, V, B,
	ALT, CTRL, LSHIFT, SPACE, ENTER, ESC,

	LBTN,
	RBTN,

	LAST
};

struct tKeyInfo {
	KEY_STATE eState;
	bool bPrevPush;
};

class KeyMgr
{
private :
	vector<tKeyInfo> m_vecKey;
	D3DXVECTOR3 m_vCurMousePos;
public :
	void init();
	void update();
	KEY_STATE GetKeyState(KEY _eKey) {
		return m_vecKey[(int)_eKey].eState;
	}
	D3DXVECTOR3 GetMousePos() { return m_vCurMousePos; }
public :
	SINGLE(KeyMgr);

};

