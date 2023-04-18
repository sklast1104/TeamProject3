#pragma once

#include "Object.h"

class CBattleTrigger :
	public Object
{

private :

	bool flag;

public :

	CBattleTrigger();
	~CBattleTrigger();

	virtual void update() override;
	virtual void render(HDC dc) override;

	virtual void OnCollision(Collider* _pOther);
	virtual void OnCollisionEnter(Collider* _pOther);
	virtual void OnCollisionExit(Collider* _pOther);

	CLONE(CBattleTrigger);
};

