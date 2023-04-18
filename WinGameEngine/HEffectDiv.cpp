#include "stdafx.h"
#include "HEffectDiv.h"
#include "CSkill.h"
#include "Animator.h"
#include "CHero.h"
#include "Animation.h"

HEffectDiv::HEffectDiv(CHero* _hero)
	: hero{_hero}
{
	
}

void HEffectDiv::PlaySkillAnim(CSkill* skill)
{
	wstring realAnimName = skill->GetRealAnimName();
	wstring realAnimPath = skill->GetRealAnimPath();

	//LoadAnimation(realAnimPath, realAnimName, false);
	if (L"" != realAnimName) {
		m_pAnimator->Play(realAnimName, false);
		m_pAnimator->GetCurAnimation()->SetFrame(0);
	}	
}

void HEffectDiv::PlayDamagedAnim(int damage)
{
	m_pAnimator->Play(L"bloodSplatter_player", false);
	m_pAnimator->GetCurAnimation()->SetFrame(0);
}

void HEffectDiv::Init()
{
	/*for (int i = 0; i < 4; i++) {
		CSkill* skill = hero->GetCurSkills()[i];
		wstring realAnimName = skill->GetRealAnimName();
		wstring realAnimPath = skill->GetRealAnimPath();

		if (L"" != realAnimName) {

			m_pAnimator->LoadAnimation(realAnimPath, realAnimName);
			Animation* skillAnim = m_pAnimator->FindAnimation(realAnimName);
			skillAnim->SetMulScale(1.2f);
			skillAnim->SetAllFrameOffset(Vec2(45.f, 0.f));
		}
	}*/

	if (hero->GetJobName() == L"성전사") {

		CSkill* skill1 = hero->GetCurSkills()[0];
		wstring realAnimName = skill1->GetRealAnimName();
		wstring realAnimPath = skill1->GetRealAnimPath();

		if (L"" != realAnimName) {

			m_pAnimator->LoadAnimation(realAnimPath, realAnimName);
			Animation* skillAnim = m_pAnimator->FindAnimation(realAnimName);
			skillAnim->SetMulScale(1.2f);
			skillAnim->SetAllFrameOffset(Vec2(40.f, 50.f));
		}

		CSkill* skill2 = hero->GetCurSkills()[1];
		realAnimName = skill2->GetRealAnimName();
		realAnimPath = skill2->GetRealAnimPath();

		if (L"" != realAnimName) {

			m_pAnimator->LoadAnimation(realAnimPath, realAnimName);
			Animation* skillAnim = m_pAnimator->FindAnimation(realAnimName);
			skillAnim->SetMulScale(1.2f);
			skillAnim->SetAllFrameOffset(Vec2(45.f, 0.f));
		}

		CSkill* skill3 = hero->GetCurSkills()[2];
		realAnimName = skill3->GetRealAnimName();
		realAnimPath = skill3->GetRealAnimPath();

		if (L"" != realAnimName) {

			m_pAnimator->LoadAnimation(realAnimPath, realAnimName);
			Animation* skillAnim = m_pAnimator->FindAnimation(realAnimName);
			skillAnim->SetMulScale(1.2f);
			skillAnim->SetAllFrameOffset(Vec2(45.f, 0.f));
		}

		CSkill* skill4 = hero->GetCurSkills()[3];
		realAnimName = skill4->GetRealAnimName();
		realAnimPath = skill4->GetRealAnimPath();

		if (L"" != realAnimName) {

			m_pAnimator->LoadAnimation(realAnimPath, realAnimName);
			Animation* skillAnim = m_pAnimator->FindAnimation(realAnimName);
			skillAnim->SetMulScale(1.2f);
			skillAnim->SetAllFrameOffset(Vec2(45.f, 230.f));
		}

	}
	else if (hero->GetJobName() == L"노상강도") {
		CSkill* skill1 = hero->GetCurSkills()[0];
		wstring realAnimName = skill1->GetRealAnimName();
		wstring realAnimPath = skill1->GetRealAnimPath();

		if (L"" != realAnimName) {

			m_pAnimator->LoadAnimation(realAnimPath, realAnimName);
			Animation* skillAnim = m_pAnimator->FindAnimation(realAnimName);
			skillAnim->SetMulScale(1.2f);
			skillAnim->SetAllFrameOffset(Vec2(45.f, 250.f));
		}

		CSkill* skill2 = hero->GetCurSkills()[1];
		realAnimName = skill2->GetRealAnimName();
		realAnimPath = skill2->GetRealAnimPath();

		if (L"" != realAnimName) {

			m_pAnimator->LoadAnimation(realAnimPath, realAnimName);
			Animation* skillAnim = m_pAnimator->FindAnimation(realAnimName);
			skillAnim->SetMulScale(1.2f);
			skillAnim->SetAllFrameOffset(Vec2(0.f, 170.f));
		}

		CSkill* skill3 = hero->GetCurSkills()[2];
		realAnimName = skill3->GetRealAnimName();
		realAnimPath = skill3->GetRealAnimPath();

		if (L"" != realAnimName) {

			m_pAnimator->LoadAnimation(realAnimPath, realAnimName);
			Animation* skillAnim = m_pAnimator->FindAnimation(realAnimName);
			skillAnim->SetMulScale(1.2f);
			skillAnim->SetAllFrameOffset(Vec2(0.f, 170.f));
		}

		CSkill* skill4 = hero->GetCurSkills()[3];
		realAnimName = skill4->GetRealAnimName();
		realAnimPath = skill4->GetRealAnimPath();

		if (L"" != realAnimName) {

			m_pAnimator->LoadAnimation(realAnimPath, realAnimName);
			Animation* skillAnim = m_pAnimator->FindAnimation(realAnimName);
			skillAnim->SetMulScale(1.2f);
			skillAnim->SetAllFrameOffset(Vec2(55.f, 250.f));
		}
	}
	else if (hero->GetJobName() == L"역병 의사") {
		CSkill* skill1 = hero->GetCurSkills()[0];
		wstring realAnimName = skill1->GetRealAnimName();
		wstring realAnimPath = skill1->GetRealAnimPath();

		if (L"" != realAnimName) {

			m_pAnimator->LoadAnimation(realAnimPath, realAnimName);
			Animation* skillAnim = m_pAnimator->FindAnimation(realAnimName);
			skillAnim->SetMulScale(1.2f);
			skillAnim->SetAllFrameOffset(Vec2(165.f, 160.f));
		}

		CSkill* skill2 = hero->GetCurSkills()[1];
		realAnimName = skill2->GetRealAnimName();
		realAnimPath = skill2->GetRealAnimPath();

		if (L"" != realAnimName) {

			m_pAnimator->LoadAnimation(realAnimPath, realAnimName);
			Animation* skillAnim = m_pAnimator->FindAnimation(realAnimName);
			skillAnim->SetMulScale(1.2f);
			skillAnim->SetAllFrameOffset(Vec2(0.f, 170.f));
		}

		CSkill* skill3 = hero->GetCurSkills()[2];
		realAnimName = skill3->GetRealAnimName();
		realAnimPath = skill3->GetRealAnimPath();

		if (L"" != realAnimName) {

			m_pAnimator->LoadAnimation(realAnimPath, realAnimName);
			Animation* skillAnim = m_pAnimator->FindAnimation(realAnimName);
			skillAnim->SetMulScale(1.2f);
			skillAnim->SetAllFrameOffset(Vec2(0.f, 170.f));
		}

		CSkill* skill4 = hero->GetCurSkills()[3];
		realAnimName = skill4->GetRealAnimName();
		realAnimPath = skill4->GetRealAnimPath();

		if (L"" != realAnimName) {

			m_pAnimator->LoadAnimation(realAnimPath, realAnimName);
			Animation* skillAnim = m_pAnimator->FindAnimation(realAnimName);
			skillAnim->SetMulScale(1.2f);
			skillAnim->SetAllFrameOffset(Vec2(55.f, 250.f));
		}
	}

	m_pAnimator->LoadAnimation(L"resource\\animations\\fx\\blood_splat_anim\\blood_splatter.sprite-blood_splatter.atlas", false, L"bloodSplatter_player");
	Animation* bloodSplatAnim = m_pAnimator->FindAnimation(L"bloodSplatter_player");
	bloodSplatAnim->SetAllFrameOffset(Vec2(0.f, 150.f));
}