#pragma once
#include "Scene.h"

class CMap;
class CSquadDiv;

class Scene_Droom :
	public Scene
{
private :

	DivUI* dragRenderer;
	DivUI* itemDragger;
	DivUI* questContainer;

	CMap* dMap;
	bool firstVisit;
	bool battleFlag;

	// 테스트용 임시 변수
	float elapseTime;
	bool debug;

	// 디버깅용
	string camCoordText;
	Vec2 cameraCoord;

	CSquadDiv* squad;
	string playerCoordText;
	Vec2 playerCoord;

	string csStr;

public :

	Scene_Droom();
	~Scene_Droom();

	virtual void render(HDC _dc) override;
	virtual void Enter() override;
	virtual void update() override;

	DivUI* GetQuestCon() { return questContainer; }
};

