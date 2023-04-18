#pragma once
#include "CCommand.h"

class DivUI;

class BtnOutCom :
	public CCommand
{

private :

	DivUI* overImg;

public :

	BtnOutCom(DivUI* _overImg);
	~BtnOutCom() {};

	virtual void Execute() override;
};

