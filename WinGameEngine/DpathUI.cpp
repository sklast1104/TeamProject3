#include "stdafx.h"
#include "DpathUI.h"

#include "DivUI.h"

void DpathUI::EnableIndicator(bool _enable)
{
	indicator->SetCanRend(_enable);
}
