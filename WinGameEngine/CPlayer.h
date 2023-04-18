#pragma once

#include "Object.h"

class CPlayer :
	public Object
{
private :

public :

	virtual void update() override;
	virtual void render(HDC _dc) override;

	CLONE(CPlayer);

};

