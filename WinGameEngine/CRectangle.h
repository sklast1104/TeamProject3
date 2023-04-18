#pragma once

#include "Object.h"

class CRectangle :
	public Object
{

private :

	bool isPlayer;

public :

	CRectangle();
	~CRectangle();

	virtual void update() override;
	virtual void render(HDC _dc) override;

	void SetIsPlayer(bool _isPlayer) { isPlayer = _isPlayer; }

	CLONE(CRectangle);
};

