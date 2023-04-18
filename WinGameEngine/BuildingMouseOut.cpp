#include "stdafx.h"
#include "BuildingMouseOut.h"
#include "DivUI.h"

BuildingMouseOut::BuildingMouseOut(DivUI* _outImg, DivUI* _txtPanel)
	: outImg{_outImg}
	, txtPanel{_txtPanel}
{
}

BuildingMouseOut::~BuildingMouseOut()
{
}

void BuildingMouseOut::Execute()
{
	outImg->SetCanRendImg(false);
	txtPanel->SetCanRend(false);
}
