#include "stdafx.h"
#include "CMonster.h"
#include "Camera.h"
#include "CPlayer.h"
#include "TimeMgr.h"

void CMonster::update()
{
	D3DXVECTOR3 pPos = target->GetPos();
	D3DXVECTOR3 mPos = GetPos();

	double angle = atan2(pPos.y - mPos.y, pPos.x - mPos.x);

	angle = angle * 180 / 3.14159265f;

	double cosA = cos(angle);
	double sinA = sin(angle);

	double newX = mPos.x * cosA - mPos.y * sinA;
	double newY = mPos.x * sinA + mPos.y * cosA;

	D3DXVECTOR3 dir = D3DXVECTOR3(newX, newY, 0.f);
	D3DXVec3Normalize(&dir, &dir);
	SetPos(GetPos() +  dir * 50.f * fDT);
}

void CMonster::render(HDC _dc)
{
	D3DXVECTOR3 vScale = GetScale();

	D3DXVECTOR3 vRenderPos = Camera::GetInst()->GetRenderPos(GetPos());

	Rectangle(_dc, (int)(vRenderPos.x - vScale.x / 2.f), (int)(vRenderPos.y - vScale.y / 2.f),
		(int)(vRenderPos.x + vScale.x / 2.f), (int)(vRenderPos.y + vScale.y / 2.f));

	ComponentRender(_dc);
}
