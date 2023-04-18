#include "stdafx.h"
#include "HeroAtEffect.h"
#include "GameMgr.h"
#include "CDarkMonster.h"
#include "CSkill.h"
#include "Animator.h"
#include "Animation.h"

void HeroAtEffect::InitAttackedAnim()
{
	GameMgr* mgr = GameMgr::GetInst();
	const vector<CDarkMonster*>& monTypes = mgr->GetMonTypes();

	for (int i = 0; i < monTypes.size(); i++) {

		const array<CSkill*, 4> skills = monTypes[i]->GetCurSkills();

		for (int i = 0; i < 4; i++) {

			if (nullptr != skills[i]) {

				wstring attackedAnimName = skills[i]->GetAttackedName();
				wstring attackedAnimPath = skills[i]->GetAttackedPath();

				if (L"" != attackedAnimName) {
					m_pAnimator->LoadAnimation(attackedAnimPath, attackedAnimName);
				}
			}

		}

	}


}

void HeroAtEffect::PlayMskAttacked(CDarkMonster* _monster, CSkill* _skil)
{
	if (L"ÇØ°ñ ±Ã¼ö" == _monster->GetName()) {
		wstring attackedAnimName = _skil->GetAttackedName();
		wstring attackedAnimPath = _skil->GetAttackedPath();

		if (_skil->GetSkillName() == L"¼è³ú ¹ß»ç") {
			m_pAnimator->FindAnimation(attackedAnimName)->SetAllFrameOffset(Vec2(80.f, 310.f));
		}

		if (L"" != attackedAnimName) {
			m_pAnimator->Play(attackedAnimName, false);
			m_pAnimator->GetCurAnimation()->SetFrame(0);
		}
	}
	else if (L"¿¹¾ðÀÚ" == _monster->GetName()) {

		wstring attackedAnimName = _skil->GetAttackedName();
		wstring attackedAnimPath = _skil->GetAttackedPath();

		if (_skil->GetSkillName() == L"ÆóÇãÀÇ µ¹¹«´õ±â") {
			m_pAnimator->FindAnimation(attackedAnimName)->SetAllFrameOffset(Vec2(-150.f, -500.f));
		}

		if (_skil->GetSkillName() == L"¼³±³") {
			m_pAnimator->FindAnimation(attackedAnimName)->SetAllFrameOffset(Vec2(60.f, 270.f));
		}

		if (L"" != attackedAnimName) {
			m_pAnimator->Play(attackedAnimName, false);
			m_pAnimator->GetCurAnimation()->SetFrame(0);
		}

	}
}
