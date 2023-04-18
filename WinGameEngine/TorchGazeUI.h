#pragma once
#include "DivUI.h"

class TorchGazeUI :
	public DivUI
{
private :

public :

	TorchGazeUI();
	~TorchGazeUI() {}

	virtual void render(HDC _dc) override;

	CLONE(TorchGazeUI);
};

