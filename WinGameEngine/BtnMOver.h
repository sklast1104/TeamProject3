#pragma once

#include "DivUI.h"


class BtnMOver :
	public DivUI
{
private :

	wstring text;
	
	LOGFONT lf;
	UINT font_size;

public :

	BtnMOver();
	~BtnMOver();

	virtual void update() override;
	virtual void MouseOn() override;
};

