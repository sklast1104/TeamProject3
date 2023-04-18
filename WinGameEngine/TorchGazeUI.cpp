#include "stdafx.h"
#include "TorchGazeUI.h"
#include "SelectGDI.h"

TorchGazeUI::TorchGazeUI()
{
}

void TorchGazeUI::render(HDC _dc)
{
	Vec2 vPos = GetFinalPos();
	Vec2 vScale = GetScale();

	SelectGDI brush(_dc, BRUSH_TYPE::ORANGE);
	SelectGDI pen(_dc, PEN_TYPE::HOLLOW);

	// HollowPen �� Ư�� �÷��� �귯���� ä����� �� �ʿ� ����

	Rectangle(_dc
		, int(vPos.x - (vScale.x / 2.f))
		, int(vPos.y - (vScale.y / 2.f))
		, int(vPos.x + (vScale.x / 2.f))
		, int(vPos.y + (vScale.y / 2.f)));
}
