#pragma once
class ViewMgr
{
private :

	float zoomRatio;
	float currentTime;
	float lerpTime;
	
	float startZoomRatio;
	float endZoomRatio;

	Vec2 startLookAt;
	Vec2 endLookAt;

public :

	void init();
	void update();

	void SetZoomRatio(float _zoomRatio);

	void animateZoom(float _zoomRatio, float _timer);

	void animateZoomView(float _zoomRatio, Vec2 _toLookAt, float _timer);

	Vec2 GetViewPortPos(Vec2 _vObjPos) { return _vObjPos * zoomRatio; }
	Vec2 GetViewPortScale(Vec2 _vObjScale) { return _vObjScale * zoomRatio; }

	// 역변환 (마우스 피킹)
	Vec2 GetRealViewPos(Vec2 _vObjPos) { return _vObjPos / zoomRatio; }

public :
	SINGLE(ViewMgr);

};

