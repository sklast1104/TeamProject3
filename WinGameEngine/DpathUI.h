#pragma once
#include "DivUI.h"

class DivUI;

class DpathUI :
	public DivUI
{

private :

	DivUI* indicator;

public :

	void SetIndicator(DivUI* _indicator) { indicator = _indicator; }
	void EnableIndicator(bool _enable);
};

