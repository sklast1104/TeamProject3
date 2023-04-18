#include "stdafx.h"
#include "BottomNavUpdate.h"

#include "DivUI.h"
#include "TextModule.h"
#include "GameMgr.h"

BottomNavUpdate::BottomNavUpdate(DivUI* _myUI)
	: myUI{_myUI}
{
}

void BottomNavUpdate::Execute()
{
	// �ϴ� �׽�Ʈ������ ���� ������Ʈ
	DivUI* moneyText = (DivUI*)(myUI->GetChildUI()[1]);
	moneyText->GetTModule()->SetText(to_wstring(GameMgr::GetInst()->GetMoney()));
}
