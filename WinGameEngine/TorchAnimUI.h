#pragma once
#include "DivUI.h"

class TorchAnimUI :
	public DivUI
{
private :

	wstring radiantName;
	wstring dimName;
	wstring darkName;
	wstring outName;

public :

	void Init();
	void PlayByLight();
};

