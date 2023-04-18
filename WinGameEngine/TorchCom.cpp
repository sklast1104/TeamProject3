#include "stdafx.h"
#include "TorchCom.h"
#include "GameMgr.h"
#include "TorchAnimUI.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "TorchGazeUI.h"

#include "ResMgr.h"
#include "Sound.h"

TorchCom::TorchCom(TorchAnimUI* _torchAnimUI)
	: torchAnimUI(_torchAnimUI)
{

}

void TorchCom::Execute()
{
	ResMgr::GetInst()->LoadSound(L"torchExit", L"resource\\sound\\Circus\\sfx\\ui_dun_pit_torch_end.wav");
	Sound* clickSound = ResMgr::GetInst()->FindSound(L"torchExit");

	clickSound->SetVolume(10.f);
	clickSound->Play(false);

	GameMgr* mgr = GameMgr::GetInst();

	mgr->SetBright(mgr->GetBright() - 25);

	torchAnimUI->PlayByLight();

	DivUI* pseudoUI = SceneMgr::GetInst()->GetCurScene()->GetPseudoUI();
	DivUI* vignBg = (DivUI*)FindUIByName(pseudoUI, L"vignBg");

	float pctg = mgr->GetBright() / 100.f;

	int vignVal = 255 - (255 * pctg);

	vignBg->SetSrcAlpha(vignVal);

	TorchGazeUI* gazeUI = (TorchGazeUI*)FindUIByName(pseudoUI, L"gazeUI");

	float gazeX = (float)GameMgr::GetInst()->GetBright() / 100.f * 860.f;

	gazeUI->SetScale(Vec2(gazeX, 10.f));

	// 게이지도 내려주고
	// 비넷트 텍스쳐 블렌드도 내리고
}
