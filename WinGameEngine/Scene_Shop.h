#pragma once
#include "Scene.h"

class DivUI;
class CInvItem;

class Scene_Shop :
	public Scene
{
private :

	DivUI* dragRenderer;
	DivUI* itemDragger;

	vector<CInvItem*> shopItems;

	void InitShopItems();

public :

	Scene_Shop();
	~Scene_Shop();

	virtual void Enter() override;
	virtual void update() override;
	virtual void Exit() override;

	const vector<CInvItem*>& GetShopItems() { return shopItems; }
};

