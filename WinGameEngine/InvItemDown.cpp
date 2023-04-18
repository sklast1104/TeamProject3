#include "stdafx.h"
#include "InvItemDown.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "GameMgr.h"
#include "Scene_Shop.h"
#include "DivUI.h"
#include "ImageModule.h"
#include "ResMgr.h"
#include "Sound.h"

InvItemDown::InvItemDown(DivUI* _myItem, int _index)
	: scene{ SceneMgr::GetInst()->GetCurScene() }
	, myItem{ _myItem }, mgr{ GameMgr::GetInst() }, index{ _index }
{
}

void InvItemDown::Execute()
{
	// 사운드
	ResMgr::GetInst()->LoadSound(L"slowDownSound", L"resource\\sound\\UI\\ui_shared\\ui_shr_button_click {aafbb3c0-f660-4aa1-b756-be47a979bafd}.wav");
	Sound* downSound = ResMgr::GetInst()->FindSound(L"slowDownSound");

	downSound->SetVolume(20.f);
	downSound->Play(false);

	DivUI* itemDragger = (DivUI*)FindUIByName((UI*)(scene->GetPseudoUI()), L"itemDragger");

	// 인벤토리를 조사해서 인벤토리 기반으로 가져오자

	array<CItem*, 16>& inventory = mgr->GetInventory();

	CItem* curClicked = inventory[index];

	if (nullptr == curClicked) return;

	// 빈 슬롯이 아닐때만 
	if (nullptr != myItem->GetIModule()) {
		itemDragger->InitImageModule(myItem->GetIModule()->GetResourceKey(), myItem->GetIModule()->GetRelativePath());
		itemDragger->SetCanRend(true);
		itemDragger->SetId(index);
	}

}
