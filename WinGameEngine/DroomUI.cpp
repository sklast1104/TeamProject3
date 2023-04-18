#include "stdafx.h"
#include "DroomUI.h"
#include "DivUI.h"

void DroomUI::EnableIndicator(bool _enable)
{
	indicator->SetCanRend(_enable);
}
