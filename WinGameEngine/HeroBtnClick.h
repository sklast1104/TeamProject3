#pragma once
#include "CCommand.h"

class CHero;

class HeroBtnClick :
	public CCommand
{
private :

	CHero* hero;

public :
	
	HeroBtnClick(CHero* _hero);
	~HeroBtnClick() {}

	virtual void Execute() override;

};

