#pragma once
#include "CCommand.h"

class DivUI;

class SideNavUpdateVal :
	public CCommand
{
private :

	DivUI* myUI;

public :

	SideNavUpdateVal(DivUI* _myUI);
	~SideNavUpdateVal() {}

	virtual void Execute() override;

};

