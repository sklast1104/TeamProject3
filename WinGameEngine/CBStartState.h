#pragma once
#include "CState.h"

class DivUI;

class CBStartState :
	public CState
{
private :

	DivUI* bStartDiv;

	virtual void Enter() override;
	virtual void Update() override;
	virtual void Exit() override;

	float elapsedTime;

public :

	CBStartState();
	~CBStartState();

};

