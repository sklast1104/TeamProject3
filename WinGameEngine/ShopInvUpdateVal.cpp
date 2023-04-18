#include "stdafx.h"
#include "ShopInvUpdateVal.h"
#include "DivUI.h"
#include "GameMgr.h"
#include "CItem.h"

ShopInvUpdateVal::ShopInvUpdateVal(DivUI* _myUI)
	: myUI{_myUI}
{
}

void ShopInvUpdateVal::Execute()
{
	vector<UI*> invItems = myUI->GetChildUI();
	GameMgr* mgr = GameMgr::GetInst();

	array<CItem*, 16> inventory = mgr->GetInventory();

	for (int i = 0; i < 16; i++) {

		DivUI* invItem = (DivUI*)invItems[i];

		if (nullptr != inventory[i]) {

			invItem->InitImageModule(inventory[i]->GetName(), inventory[i]->GetPath());
			invItem->SetCanRend(true);


			DivUI* invCount = (DivUI*)invItem->GetChildUI()[0];
			invCount->InitTextModule(to_wstring(inventory[i]->GetCurCount()), 25);
			invCount->SetCanRend(true);
		}
		else {
			invItem->SetCanRend(false);
		}
	}
}
