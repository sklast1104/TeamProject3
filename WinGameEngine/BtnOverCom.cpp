#include "stdafx.h"
#include "BtnOverCom.h"
#include "DivUI.h"

BtnOverCom::BtnOverCom(DivUI* _overImg)
	: overImg{_overImg}
{
}

void BtnOverCom::Execute()
{
	overImg->SetCanRend(true);
}
