#pragma once

#include "DivUI.h"

class CCommand;

class BtnBuilding :
	public DivUI
{
private :

	CCommand* onMouseOut;

public :

	BtnBuilding(CCommand* _onMouseOut);
	~BtnBuilding();

	virtual void MouseOn() override;

};

