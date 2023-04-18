#pragma once

#include "Object.h"

class CSquadDiv;

class CSquadCol :
	public Object
{
private :

	CSquadDiv* squad;

public :

	void SetSquad(CSquadDiv* _squad) { squad = _squad; }

	virtual void update() override;
	virtual void render(HDC _dc);

	CLONE(CSquadCol);
};

