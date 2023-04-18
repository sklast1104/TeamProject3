#include "stdafx.h"
#include "BtnBuilding.h"
#include "KeyMgr.h"
#include "CCommand.h"

BtnBuilding::BtnBuilding(CCommand* _onMouseOut)
	: onMouseOut{_onMouseOut}
{
}

BtnBuilding::~BtnBuilding()
{
	Safe_Delete<CCommand*>(onMouseOut);
}

//void BtnBuilding::update()
//{
//	UI::update();
//
//	// ������ǥ�ε� ī�޶� ������ or ī�޶� ������ ���� �ʴ� UI�� �������
//	Vec2 mousePos = MOUSE_POS;
//
//	Vec2 myScale = GetScale();
//	Vec2 finalPos = GetFinalPos();
//
//
//	if (finalPos.x <= mousePos.x && mousePos.x <= finalPos.x + myScale.x
//		&& finalPos.y <= mousePos.y && mousePos.y <= finalPos.y + myScale.y) {
//
//	}
//	else {
//
//		assert(onMouseOut);
//
//		onMouseOut->Execute();
//	}
//}

void BtnBuilding::MouseOn()
{
	assert(onMouseOver);

	onMouseOver->Execute();
}
