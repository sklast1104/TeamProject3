#include "stdafx.h"
#include "BtnMOver.h"
#include "KeyMgr.h"


BtnMOver::BtnMOver()
{
	ZeroMemory(&lf, sizeof(lf));
	lf.lfHeight = 40;
	wcscpy_s(lf.lfFaceName, L"�̼��� Bold");
	text = L"ķ����";
}

BtnMOver::~BtnMOver()
{
}

void BtnMOver::update()
{
	UI::update();

	// ������ǥ�ε� ī�޶� ������ or ī�޶� ������ ���� �ʴ� UI�� �������
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

// MouseOn�� �����ϴµ� MouseOut�� ���ξ���
// Update���� ������ ������ຸ��
void BtnMOver::MouseOn()
{
	SetSrcAlpha(255);
}
