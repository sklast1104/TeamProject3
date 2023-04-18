#pragma once
#include "CCommand.h"

class DoorClick :
	public CCommand
{
private :

	int roomId;

public :

	DoorClick(int _roomId);
	~DoorClick() {}

	virtual void Execute() override;

};

