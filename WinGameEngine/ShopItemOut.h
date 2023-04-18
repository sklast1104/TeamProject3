#pragma once
#include "CCommand.h"

class DivUI;

class ShopItemOut :
	public CCommand
{

private :

	DivUI* tooltip;

public :

	ShopItemOut(DivUI* _tooltip);
	~ShopItemOut() {}

	virtual void Execute() override;

};

