#pragma once
#include "Scene.h"

class CSquadDiv;
class CPathNode;
class CRoom;

class Scene_Path :
	public Scene
{
private :

	DivUI* itemDragger;

	vector<CPathNode*> paths;

	CRoom* prevRoom;
	CRoom* nextRoom;

	// µð¹ö±ë¿ë
	string camCoordText;
	Vec2 cameraCoord;

	CSquadDiv* squad;
	string playerCoordText;
	Vec2 playerCoord;

	string csStr;

public :

	Scene_Path();
	~Scene_Path();

	void SetPath(vector<CPathNode*> _path) { paths = _path; }

	virtual void render(HDC _dc) override;
	virtual void Enter() override;
	virtual void update() override;
	virtual void Exit() override;
};

