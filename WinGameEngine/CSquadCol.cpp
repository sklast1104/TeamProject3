#include "stdafx.h"
#include "CSquadCol.h"
#include "CSquadDiv.h"
#include "Camera.h"
#include "ViewMgr.h"
#include "SelectGDI.h"

void CSquadCol::update()
{
	Vec2 vPos = squad->GetFinalPos();
	Vec2 vScale = squad->GetScale();

	SetPos(vPos + (vScale / 2.f));

}

void CSquadCol::render(HDC _dc)
{
	SelectGDI brush(_dc, BRUSH_TYPE::HOLLOW);
	SelectGDI pen(_dc, PEN_TYPE::HOLLOW);

	Vec2 vRenderPos = Camera::GetInst()->GetRenderPos(GetPos());

	Vec2 vViewPos = ViewMgr::GetInst()->GetViewPortPos(vRenderPos);
	Vec2 vViewScale = ViewMgr::GetInst()->GetViewPortScale(GetScale());

	/*Rectangle(_dc, (int)(vRenderPos.x - vViewScale.x / 2.f), (int)(vRenderPos.y - vViewScale.y / 2.f),
		(int)(vRenderPos.x + vViewScale.x / 2.f), (int)(vRenderPos.y + vViewScale.y / 2.f));*/

	//ComponentRender(_dc);
}
