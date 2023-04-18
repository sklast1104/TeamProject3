#pragma once
#include "CCommand.h"

class DivUI;

class BottomNavUpdate :
	public CCommand
{
private :

	DivUI* myUI;

public :

	BottomNavUpdate(DivUI* _myUI);
	~BottomNavUpdate() {}

	virtual void Execute() override;
};

