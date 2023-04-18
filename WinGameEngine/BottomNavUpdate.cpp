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
	// 일단 테스트용으로 돈만 업데이트
	DivUI* moneyText = (DivUI*)(myUI->GetChildUI()[1]);
	moneyText->GetTModule()->SetText(to_wstring(GameMgr::GetInst()->GetMoney()));
}
