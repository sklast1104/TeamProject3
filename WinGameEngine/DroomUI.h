#pragma once
#include "DivUI.h"

class DivUI;

class DroomUI :
	public DivUI
{

private :

	DivUI* indicator;

public :

	void SetIndicator(DivUI* _indicator) { indicator = _indicator; }
	void EnableIndicator(bool _enable);
};

