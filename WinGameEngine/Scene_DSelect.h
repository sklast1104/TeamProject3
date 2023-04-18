#pragma once
#include "Scene.h"

class DivUI;
class CDungeon;

enum class DSCENE_STATE {

	Idle,
	HeroDrag,
};

class Scene_DSelect :
	public Scene
{

private :

	DSCENE_STATE scState;

	DivUI* dragRenderer;

	vector<DivUI*> radioBtns;

	CDungeon* ruin; // ����
	CDungeon* court; // ����
	CDungeon* bay; // �ؾ� ��

	void InitDungeon();

	// sidebar ui
	// ex ����
	DivUI* questTitle;
	// ex ������ ������ ����...
	DivUI* questText;
	// ex x0
	DivUI* campingText;
	// ex ª�� |
	DivUI* pathLengText;
	// ex �߽� (1����)
	DivUI* pathLevText;
	// ex �� ������ 100% ~
	DivUI* goalDisc;

public :

	Scene_DSelect();
	~Scene_DSelect();

	virtual void Enter() override;
	virtual void Exit() override;
	virtual void update() override;

	void turnOffRadioBtn();

	DivUI* GetRenderer() { return dragRenderer; }

	friend class UIFactory;
	friend class RadioBtnClickCom;
};

