#pragma once
#include "CCommand.h"

class RoomUIClick :
	public CCommand
{
private :

	int id;

public :

	RoomUIClick(int _id);
	~RoomUIClick() {}

	virtual void Execute() override;

};

