#pragma once
#include "CCommand.h"

class DivUI;
class Scene;
class GameMgr;

class InvItemUp :
	public CCommand
{
private :

	DivUI* myItem;
	Scene* scene;
	GameMgr* mgr;
	int index;

public :

	InvItemUp(DivUI* _myItem, int _index);
	~InvItemUp() {}

	virtual void Execute() override;
};

