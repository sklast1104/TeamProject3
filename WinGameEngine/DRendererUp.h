#pragma once
#include "CCommand.h"

class DivUI;

class DRendererUp :
	public CCommand
{
private :

	DivUI* myUI;
	DivUI* slotConatiner;

public :

	DRendererUp(DivUI* _myUI, DivUI* _slotConatiner);
	~DRendererUp() {}

	virtual void Execute() override;
};

