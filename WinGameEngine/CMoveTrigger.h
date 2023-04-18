#pragma once

#include "Object.h"

class CMoveTrigger :
	public Object
{
private :

	int id;

public :

	CMoveTrigger();
	~CMoveTrigger();

	virtual void update() override;
	virtual void render(HDC dc) override;

	virtual void OnCollision(Collider* _pOther);
	virtual void OnCollisionEnter(Collider* _pOther);
	virtual void OnCollisionExit(Collider* _pOther);

	void SetId(int _id) { id = _id; }

	CLONE(CMoveTrigger);
};

