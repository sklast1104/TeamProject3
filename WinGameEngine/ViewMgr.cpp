#include "stdafx.h"
#include "ViewMgr.h"

#include "Camera.h"
#include "TimeMgr.h"

ViewMgr::ViewMgr()
	: zoomRatio{1.f}
	, currentTime{0.f}
	, lerpTime{0.000001f}
	, startZoomRatio{0.f}
	, endZoomRatio{0.f}
	, startLookAt{ Camera::GetInst()->GetLookAt() }
	, endLookAt{ Camera::GetInst()->GetLookAt() }
{

}

ViewMgr::~ViewMgr() {

}

void ViewMgr::init()
{
	startZoomRatio = zoomRatio;
	endZoomRatio = zoomRatio;
}

void ViewMgr::update()
{
	currentTime += fDT;

	if (currentTime >= lerpTime) {
		currentTime = lerpTime;
	}

	float t = currentTime / lerpTime;

	zoomRatio = Mathf::Lerp(startZoomRatio, endZoomRatio, t);
	//Camera::GetInst()->update();

}

void ViewMgr::SetZoomRatio(float _zoomRatio)
{
	zoomRatio = _zoomRatio;
	startZoomRatio = zoomRatio;
	endZoomRatio = zoomRatio;
}

void ViewMgr::animateZoom(float _endzoomRatio, float _lerpTime)
{
	currentTime = 0.f;
	lerpTime = _lerpTime;
	startZoomRatio = zoomRatio;
	endZoomRatio = _endzoomRatio;
}

void ViewMgr::animateZoomView(float _endzoomRatio, Vec2 _toLookAt, float _timer)
{
	currentTime = 0.f;
	lerpTime = _timer;
	startZoomRatio = zoomRatio;
	endZoomRatio = _endzoomRatio;

	startLookAt = Camera::GetInst()->GetLookAt();
	endLookAt = _toLookAt;
}
