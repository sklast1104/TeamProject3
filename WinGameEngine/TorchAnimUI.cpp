#include "stdafx.h"
#include "TorchAnimUI.h"
#include "Animator.h"
#include "Animation.h"
#include "GameMgr.h"

// new AnimatorDK가 로딩되었다는 가정
void TorchAnimUI::Init()
{
	wstring radiantPath = L"resource\\animations\\torch\\torch_flame.sprite-radiant_loop.atlas";
	radiantName = L"radiant_torch";

	m_pAnimator->LoadAnimation(radiantPath, radiantName);
	GetAnimator()->FindAnimation(radiantName)->SetAllFrameDuration(0.04f);

	wstring dimPath = L"resource\\animations\\torch\\torch_flame.sprite-dim_loop.atlas";
	dimName = L"dim_torch";

	m_pAnimator->LoadAnimation(dimPath, dimName);
	GetAnimator()->FindAnimation(dimName)->SetAllFrameDuration(0.03f);
	GetAnimator()->FindAnimation(dimName)->SetAllFrameOffset(Vec2(11.f, -0.f));

	wstring darkPath = L"resource\\animations\\torch\\torch_flame.sprite-dark_loop.atlas";
	darkName = L"dark_torch";

	m_pAnimator->LoadAnimation(darkPath, darkName);
	GetAnimator()->FindAnimation(darkName)->SetAllFrameDuration(0.03f);
	GetAnimator()->FindAnimation(darkName)->SetAllFrameOffset(Vec2(23.f, 5.f));

	wstring outPath = L"resource\\animations\\torch\\torch_flame.sprite-out_loop.atlas";
	outName = L"out_torch";
	
	m_pAnimator->LoadAnimation(outPath, outName);
	GetAnimator()->FindAnimation(outName)->SetAllFrameDuration(0.03f);
	GetAnimator()->FindAnimation(outName)->SetAllFrameOffset(Vec2(30.f, 10.f));
}

void TorchAnimUI::PlayByLight()
{
	int bright = GameMgr::GetInst()->GetBright();

	if (bright > 50) {

		GetAnimator()->Play(radiantName, true);

	}
	else if (bright > 25) {

		GetAnimator()->Play(dimName, true);

	}
	else if (bright > 0) {

		GetAnimator()->Play(darkName, true);

	}
	else {

		GetAnimator()->Play(outName, true);

	}

}
