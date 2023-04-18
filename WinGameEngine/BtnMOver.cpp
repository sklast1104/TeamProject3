#include "stdafx.h"
#include "BtnMOver.h"
#include "KeyMgr.h"


BtnMOver::BtnMOver()
{
	ZeroMemory(&lf, sizeof(lf));
	lf.lfHeight = 40;
	wcscpy_s(lf.lfFaceName, L"이순신 Bold");
	text = L"캠페인";
}

BtnMOver::~BtnMOver()
{
}

void BtnMOver::update()
{
	UI::update();

	// 렌더좌표인데 카메라 정방향 or 카메라 영향을 받지 않는 UI면 상관없음
	Vec2 mousePos = MOUSE_POS;
	
	Vec2 myScale = GetScale();
	Vec2 finalPos = GetFinalPos();
	

	if (finalPos.x <= mousePos.x && mousePos.x <= finalPos.x + myScale.x
		&& finalPos.y <= mousePos.y && mousePos.y <= finalPos.y + myScale.y) {

	}
	else {

		SetSrcAlpha(180);
	}
}

// MouseOn은 존재하는데 MouseOut은 따로없음
// Update에서 강제로 만들어줘보자
void BtnMOver::MouseOn()
{
	SetSrcAlpha(255);
}
