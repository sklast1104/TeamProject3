#pragma once
#include "CCommand.h"

class DivUI;
class Scene;
class GameMgr;

class InvItemDown :
	public CCommand
{
private :

	DivUI* myItem;
	Scene* scene;
	GameMgr* mgr;
	int index;

public :

	InvItemDown(DivUI* _myItem, int _index);
	~InvItemDown() {}

	virtual void Execute() override;

};

