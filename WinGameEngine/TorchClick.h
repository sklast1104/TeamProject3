#pragma once
#include "CCommand.h"

class DivUI;

class TorchClick :
	public CCommand
{
private :

	DivUI* invItem;
	int invIdx;

public :

	TorchClick(DivUI* _invItem, int _invIdx);
	~TorchClick() {}

	virtual void Execute() override;

};

