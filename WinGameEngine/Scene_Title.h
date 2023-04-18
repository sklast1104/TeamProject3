#pragma once
#include "Scene.h"

class Scene_Title :
	public Scene
{
private :

public :

	Scene_Title();
	~Scene_Title();

	virtual void Enter() override;
	virtual void Exit() override;

};

