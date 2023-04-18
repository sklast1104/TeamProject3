#pragma once
#include "Scene.h"

class Scene_Town :
	public Scene
{
private :

public :

	Scene_Town();
	~Scene_Town();

	virtual void Enter() override;
	virtual void Exit() override;
	virtual void update() override;

};

