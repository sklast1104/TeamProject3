#pragma once
#include "CCommand.h"

class DivUI;

class BuildingOverCom :
	public CCommand
{
private :

	DivUI* overImg;
	DivUI* txtPanel;

public :

	BuildingOverCom(DivUI* _overImg, DivUI* _txtPanel);
	~BuildingOverCom() {};

	virtual void Execute() override;
};

