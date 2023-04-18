#pragma once
#include "CCommand.h"

class DivUI;

class ShopItemOver :
	public CCommand
{

private :

	DivUI* tooltip;

public :

	ShopItemOver(DivUI* _tooltip);
	~ShopItemOver() {}

	virtual void Execute() override;

};

