#pragma once
#include "CCommand.h"

class TorchAnimUI;

class TorchCom :
	public CCommand
{

private :

	TorchAnimUI* torchAnimUI;

public :

	TorchCom(TorchAnimUI* _torchAnimUI);
	~TorchCom() {}

	virtual void Execute() override;

};

