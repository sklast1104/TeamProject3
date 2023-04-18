#include "stdafx.h"
#include "CMoveTrigger.h"
#include "Camera.h"
#include "ViewMgr.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "DMapUI.h"
#include "Collider.h"

CMoveTrigger::CMoveTrigger()
{
}

CMoveTrigger::~CMoveTrigger()
{
}

void CMoveTrigger::update()
{
}

void CMoveTrigger::render(HDC _dc)
{
	Vec2 vRenderPos = Camera::GetInst()->GetRenderPos(m_vPos);

	Vec2 vViewPos = ViewMgr::GetInst()->GetViewPortPos(vRenderPos);
	Vec2 vViewScale = ViewMgr::GetInst()->GetViewPortScale(GetScale());

	/*Rectangle(_dc, (int)(vRenderPos.x - vViewScale.x / 2.f), (int)(vRenderPos.y - vViewScale.y / 2.f),
		(int)(vRenderPos.x + vViewScale.x / 2.f), (int)(vRenderPos.y + vViewScale.y / 2.f));

	ComponentRender(_dc);*/
}

void CMoveTrigger::OnCollision(Collider* _pOther)
{
}

void CMoveTrigger::OnCollisionEnter(Collider* _pOther)
{
	if (_pOther->GetObj()->GetName() == L"heroCol") {
		DivUI* pseudoUI = SceneMgr::GetInst()->GetCurScene()->GetPseudoUI();
		DMapUI* mapPanel = (DMapUI*)FindUIByName(pseudoUI, L"mapPanel");

		mapPanel->EnableAllIndicator(false);
		mapPanel->EnableIndibyIdx(id);
	}

	

	// ¸Ê ÆÐ³Î ·»´õ¸µ
	// ¸Ê ÆÐ³Î °¡Á®¿Í¾ßÇÔ
}

void CMoveTrigger::OnCollisionExit(Collider* _pOther)
{
}
