#pragma once
#include "DivUI.h"

class DamageDiv :
	public DivUI
{
private :

	Vec2 originPos;

	virtual void update() override;

	bool isMoving = false;
	float lerpTime = 1.5f;
	float elapsedTime = 0.f;

	float startYPos;
	float endYPos;

public :

	DamageDiv();
	~DamageDiv() {}

	void StartMove();
	void SetOriginPos(Vec2 _vPos) { originPos = _vPos; }
};

