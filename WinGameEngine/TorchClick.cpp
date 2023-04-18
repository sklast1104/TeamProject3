#include "stdafx.h"
#include "TorchClick.h"
#include "CItem.h"
#include "GameMgr.h"

#include "GameMgr.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "DivUI.h"
#include "TextModule.h"
#include "TorchGazeUI.h"
#include "TorchAnimUI.h"

#include "ResMgr.h"
#include "Sound.h"

TorchClick::TorchClick(DivUI* _invItem, int _invIdx)
	: invItem{_invItem}, invIdx{_invIdx}
{
}

void TorchClick::Execute()
{
	ResMgr::GetInst()->LoadSound(L"torchFire", L"resource\\sound\\Circus\\sfx\\ui_dun_pit_torch_start.wav");
	Sound* clickSound = ResMgr::GetInst()->FindSound(L"torchFire");

	clickSound->SetVolume(20.f);
	clickSound->Play(false);

	GameMgr* mgr = GameMgr::GetInst();

	array<CItem*, 16>& inventory = mgr->GetInventory();

	CItem* curClicked = inventory[invIdx];

	if (nullptr == curClicked) return;

	if (L"torch" != curClicked->GetName()) return;

	curClicked->SetCurCount(curClicked->GetCurCount() - 1);
	int itemCount = curClicked->GetCurCount();
	wstring itemName = curClicked->GetName();

	DivUI* invCount = (DivUI*)(invItem->GetChildUI()[0]);
	invCount->GetTModule()->SetText(to_wstring(curClicked->GetCurCount()));

	if (itemCount == 0) {
		mgr->RemoveItem(invIdx);
	}

	// 인벤토리 렌더링
	if (itemCount == 0) {

		invItem->SetCanRend(false);
		invItem->CanTarget(true);
	}

	mgr->SetBright(mgr->GetBright() + 25);

	DivUI* pseudoUI = SceneMgr::GetInst()->GetCurScene()->GetPseudoUI();

	TorchAnimUI* torchAnimUI = (TorchAnimUI*)FindUIByName(pseudoUI, L"TorchAnimUI");

	torchAnimUI->PlayByLight();

	DivUI* vignBg = (DivUI*)FindUIByName(pseudoUI, L"vignBg");

	float pctg = mgr->GetBright() / 100.f;

	int vignVal = 255 - (255 * pctg);

	if (vignVal > 255) vignVal = 255;

	vignBg->SetSrcAlpha(vignVal);

	TorchGazeUI* gazeUI = (TorchGazeUI*)FindUIByName(pseudoUI, L"gazeUI");

	float gazeX = (float)GameMgr::GetInst()->GetBright() / 100.f * 860.f;

	gazeUI->SetScale(Vec2(gazeX, 10.f));
}
