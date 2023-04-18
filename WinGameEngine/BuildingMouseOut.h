#pragma once
#include "CCommand.h"

class DivUI;

class BuildingMouseOut :
	public CCommand
{
private :

	DivUI* outImg;
	DivUI* txtPanel;

public :

	BuildingMouseOut(DivUI* _outImg, DivUI* _txtPanel);
	~BuildingMouseOut();

	virtual void Execute() override;
};

