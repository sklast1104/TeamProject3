#pragma once
#include "CCommand.h"

class DivUI;

class BtnOverCom :
	public CCommand
{
private :

	DivUI* overImg;

public :

	BtnOverCom(DivUI* _overImg);
	~BtnOverCom() {};

	virtual void Execute() override;
};

