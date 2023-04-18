#include "stdafx.h"
#include "ShopItemOut.h"
#include "DivUI.h"

ShopItemOut::ShopItemOut(DivUI* _tooltip)
	: tooltip{ _tooltip }
{
}

void ShopItemOut::Execute()
{
	tooltip->SetCanRend(false);
}
