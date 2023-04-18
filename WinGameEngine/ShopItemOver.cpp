#include "stdafx.h"
#include "ShopItemOver.h"
#include "DivUI.h"

ShopItemOver::ShopItemOver(DivUI* _tooltip)
	: tooltip{_tooltip}
{
}

void ShopItemOver::Execute()
{
	tooltip->SetCanRend(true);
}
