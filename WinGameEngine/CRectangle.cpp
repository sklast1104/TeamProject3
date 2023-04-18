#include "stdafx.h"
#include "CRectangle.h"

#include "KeyMgr.h"
#include "TimeMgr.h"

#include "Camera.h"
#include "ViewMgr.h"

#include "SelectGDI.h"

CRectangle::CRectangle()
	: isPlayer{true}
{
}

CRectangle::~CRectangle()
{
}

void CRectangle::update()
{
	D3DXVECTOR3 mPos = GetPos();

	float speed = 300.f;

	if (isPlayer) {
		if (KEY_HOLD(KEY::W)) {

			SetPos(D3DXVECTOR3(mPos.x, mPos.y + -speed * fDT, 0.f));
		}

		if (KEY_HOLD(KEY::S)) {
			SetPos(D3DXVECTOR3(mPos.x, mPos.y + speed * fDT, 0.f));
		}

		if (KEY_HOLD(KEY::A)) {
			SetPos(D3DXVECTOR3(mPos.x - speed * fDT, mPos.y, 0.f));
		}

		if (KEY_HOLD(KEY::D)) {
			SetPos(D3DXVECTOR3(mPos.x + speed * fDT, mPos.y, 0.f));
		}
	}

}

void CRectangle::render(HDC _dc)
{
	D3DXVECTOR3 vScale = GetScale();

	D3DXVECTOR3 vRenderPos = Camera::GetInst()->GetRenderPos(GetPos());

	Rectangle(_dc, (int)(vRenderPos.x - vScale.x / 2.f), (int)(vRenderPos.y - vScale.y / 2.f),
		(int)(vRenderPos.x + vScale.x / 2.f), (int)(vRenderPos.y + vScale.y / 2.f));

	ComponentRender(_dc);

}
