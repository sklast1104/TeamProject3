#pragma once
#include "CCommand.h"

class DivUI;

class ShopInvUpdateVal :
	public CCommand
{
private :

	DivUI* myUI;

public :

	ShopInvUpdateVal(DivUI* _myUI);
	~ShopInvUpdateVal() {}

	virtual void Execute() override;

};

