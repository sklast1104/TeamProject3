#include "stdafx.h"
#include "CSelectedOverlay.h"

#include "Camera.h"
#include "ViewMgr.h"
#include "ResMgr.h"
#include "Texture.h"
#include "TimeMgr.h"

CSelectedOverlay::CSelectedOverlay() 
	: UI(true), overlayTex{ ResMgr::GetInst()->LoadTexture(L"Selected_Overlay", L"resource\\overay\\selected_1_crop.png") }
	, isGrowing{true}, canRend{true}
{
}

void CSelectedOverlay::update()
{
	float upSpeed = 40.f;
	float downSpeed = 60.f;
	float targetX = 210.f;
	float originX = 175.f;

	if (isGrowing) {

		Vec2 scale = GetScale();
		scale.x += upSpeed * fDT;

		SetScale(scale);

		if (scale.x >= targetX) {
			isGrowing = false;
		}

	}
	else {

		Vec2 scale = GetScale();
		scale.x -= downSpeed * fDT;

		SetScale(scale);

		if (scale.x <= originX) {
			isGrowing = true;
		}
	}

	UI::update();
}

void CSelectedOverlay::render(HDC _dc)
{
	if (!canRend) return;

	Vec2 vPos = GetFinalPos();
	Vec2 vScale = GetScale();

	if (IsCamEffected()) {
		// View 변환 실행
		// 카메라 영향을 받지 않는다면 항상 같은위치에 렌더링된다(일반적으로 생각하는 UI이다)
		vPos = Camera::GetInst()->GetRenderPos(vPos);
	}

	if (isViewEffected()) {
		vPos = ViewMgr::GetInst()->GetViewPortPos(vPos);
		vScale = ViewMgr::GetInst()->GetViewPortScale(vScale);
	}

	BLENDFUNCTION bf = {};

	bf.BlendOp = AC_SRC_OVER;
	bf.BlendFlags = 0;
	bf.AlphaFormat = AC_SRC_ALPHA;
	bf.SourceConstantAlpha = 255;

	AlphaBlend(_dc
		, (int)(vPos.x - (vScale.x / 2.f))
		, (int)(vPos.y - (vScale.y / 2.f))
		, (int)(vScale.x)
		, (int)(vScale.y)
		, overlayTex->GetDC()
		, (int)(0)
		, (int)(0)
		, (int)(overlayTex->Width())
		, (int)(overlayTex->Height())
		, bf);

	UI::render(_dc);
}
