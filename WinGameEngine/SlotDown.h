#pragma once
#include "CCommand.h"

class DivUI;

class SlotDown :
	public CCommand
{
private :

	DivUI* heroPortrait;
	DivUI* dragRenderer;
	int slotIndex;

public :

	SlotDown(DivUI* _heroPortrait, DivUI* _dragRenderer, int _slotIndex);
	~SlotDown();

	virtual void Execute() override;

};

// 클릭한 순간 슬롯 포트레잇을 이미지 출력 안하도록 바꾸고
// 드래그렌더러를 포트레잇이 출력하고 있던 이미지로 바꿔줌
// LBTN UP일떄 렌더러 끄는건 씬에서 계속 하고있음