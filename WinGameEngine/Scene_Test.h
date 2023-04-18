#pragma once
#include "Scene.h"

class Scene_Test :
	public Scene
{
private :

public :

	Scene_Test();
	~Scene_Test();

	virtual void Enter() override;
	virtual void Exit() override;
	virtual void update() override;
};

