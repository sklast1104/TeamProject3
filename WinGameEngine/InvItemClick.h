#pragma once
#include "CCommand.h"

class DivUI;
class Scene_Shop;
class GameMgr;

class InvItemClick :
	public CCommand
{
private :

	DivUI* myItem;
	Scene_Shop* scene;
	GameMgr* mgr;
	int index;

public :

	InvItemClick(DivUI* _myItem, int _index);
	~InvItemClick() {}

	virtual void Execute() override;
};

