#pragma once
#include "CCommand.h"

class DivUI;
class GameMgr;
class Scene_Shop;

class ShopItemClick :
	public CCommand
{
private :

	DivUI* myItem;
	int itemCost;

	DivUI* invPanel;
	GameMgr* mgr;

	Scene_Shop* scene;

	void sellShopItem();

public :

	ShopItemClick(DivUI* _myItem, DivUI* _invPanel, int _itemCost);
	~ShopItemClick();

	virtual void Execute() override;

};

