#pragma once
#include "CCommand.h"

class DivUI;
class CQuest;
class Scene_DSelect;

class RadioBtnClickCom :
	public CCommand
{
private :

	DivUI* myBg;
	CQuest* quest;
	Scene_DSelect* dSelectScene;

public :

	RadioBtnClickCom(DivUI* _myBG , CQuest* _quest ,Scene_DSelect* _dScene);
	~RadioBtnClickCom() {}

	virtual void Execute() override;
};

