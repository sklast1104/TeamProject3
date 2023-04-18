#pragma once
#include "CCommand.h"

class DivUI;

class SlotUp :
	public CCommand
{
private :

	DivUI* mySlot;
	DivUI* dragUI;
	DivUI* slotContainer;
	int slotIndex;

public :

	SlotUp(DivUI* _mySlot ,DivUI* _dragUI, int _slotIndex, DivUI* _slotContainer);
	~SlotUp() {}
	virtual void Execute() override;
};

