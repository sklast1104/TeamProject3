#include "stdafx.h"
#include "CBattleTrigger.h"
#include "GameMgr.h"
#include "DarkestMachine.h"
#include "Camera.h"
#include "ViewMgr.h"
#include "Collider.h"
#include "GameMgr.h"

CBattleTrigger::CBattleTrigger()
	: flag{true}
{
}

CBattleTrigger::~CBattleTrigger()
{
}

void CBattleTrigger::update()
{
}

void CBattleTrigger::render(HDC _dc)
{
	Vec2 vRenderPos = Camera::GetInst()->GetRenderPos(m_vPos);

	Vec2 vViewPos = ViewMgr::GetInst()->GetViewPortPos(vRenderPos);
	Vec2 vViewScale = ViewMgr::GetInst()->GetViewPortScale(GetScale());

	/*Rectangle(_dc, (int)(vRenderPos.x - vViewScale.x / 2.f), (int)(vRenderPos.y - vViewScale.y / 2.f),
		(int)(vRenderPos.x + vViewScale.x / 2.f), (int)(vRenderPos.y + vViewScale.y / 2.f));*/

	//ComponentRender(_dc);
}

void CBattleTrigger::OnCollision(Collider* _pOther)
{
}

void CBattleTrigger::OnCollisionEnter(Collider* _pOther)
{
	if (flag && _pOther->GetObj()->GetName() == L"heroCol") {
		flag = false;

		//GameMgr::GetInst()->SetRandomSquad();

		ChangeState(GameMgr::GetInst()->GetMachine(), L"CBStartState");

	}
}

void CBattleTrigger::OnCollisionExit(Collider* _pOther)
{
}
