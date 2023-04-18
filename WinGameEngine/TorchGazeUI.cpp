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

	// HollowPen 밑 특정 컬러의 브러쉬로 채워줘야 할 필요 있음

	Rectangle(_dc
		, int(vPos.x - (vScale.x / 2.f))
		, int(vPos.y - (vScale.y / 2.f))
		, int(vPos.x + (vScale.x / 2.f))
		, int(vPos.y + (vScale.y / 2.f)));
}
