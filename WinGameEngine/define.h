#pragma once

#define SINGLE(type) public : \
						static type* GetInst() { static type mgr; return &mgr; } \
							private : \
								type();\
								~type();

#define fDT TimeMgr::GetInst()->GetfDT()
#define DT TimeMgr::GetInst()->GetDT()

#define CLONE(type) type* Clone() {return new type(*this);}

#define KEY_CHECK(key, state) KeyMgr::GetInst()->GetKeyState(key) == state
#define KEY_HOLD(key) KEY_CHECK(key, KEY_STATE::HOLD)
#define KEY_TAP(key) KEY_CHECK(key, KEY_STATE::TAP)
#define KEY_AWAY(key) KEY_CHECK(key, KEY_STATE::AWAY)
#define KEY_NONE(key) KEY_CHECK(key, KEY_STATE::NONE)
#define MOUSE_POS KeyMgr::GetInst()->GetMousePos()

#define PI 3.1415926535f

enum class GROUP_TYPE {

	DEFAULT,
	TILE,
	PLAYER,
	MONSTER,
	OBSTACLE,
	PROJ_PLAYER,
	PROJ_MONSTER,
	UI = 29,
	UI_OVER = 30,
	FINAL = 31,
	END = 32,
};

enum class SCENE_TYPE {

	TITLE,
	TOWN,
	DSELECT,
	SHOP,
	DROOM,
	PATH,
	TEST,
	END,
};

enum class BRUSH_TYPE {
	HOLLOW,
	RED,
	BLACK,
	ORANGE,
	END
};

enum class PEN_TYPE {
	RED,
	GREEN,
	BLUE,
	HOLLOW,
	END
};

enum class EVENT_TYPE {
	CREATE_OBJECT,
	DELETE_OBJECT,
	SCENE_CHANGE,
	STATE_CHANGE,
	END,
};

enum CHANNEL {

	SOUND_EFFECT,
	SOUND_BGM,
	SOUND_PLAYER,
	SOUND_MONSTER,
	END
};