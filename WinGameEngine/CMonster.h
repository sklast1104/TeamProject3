#pragma once

#include "Object.h"

class CPlayer;

class CMonster :
	public Object
{

private :

	CPlayer* target;

public :

	void SetTarget(CPlayer* _target) { target = _target; }

	virtual void update() override;
	virtual void render(HDC _dc) override;

	CLONE(CMonster);
};

