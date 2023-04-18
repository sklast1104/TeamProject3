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

// Ŭ���� ���� ���� ��Ʈ������ �̹��� ��� ���ϵ��� �ٲٰ�
// �巡�׷������� ��Ʈ������ ����ϰ� �ִ� �̹����� �ٲ���
// LBTN UP�ϋ� ������ ���°� ������ ��� �ϰ�����