#include "stdafx.h"
#include "BtnOutCom.h"
#include "DivUI.h"

BtnOutCom::BtnOutCom(DivUI* _overImg)
	: overImg{_overImg}
{
}

void BtnOutCom::Execute()
{
	overImg->SetCanRend(false);
}
