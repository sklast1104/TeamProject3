#include "stdafx.h"
#include "MEffectDiv.h"
#include "CSkill.h"
#include "Animator.h"
#include "Animation.h"
#include "CDarkMonster.h"

MEffectDiv::MEffectDiv(CDarkMonster* _dMon)
	: dMon{_dMon}
{
}

void MEffectDiv::PlaySkillAnim(CSkill* skill)
{
	wstring realAnimName = skill->GetRealAnimName();
	wstring realAnimPath = skill->GetRealAnimPath();

	//LoadAnimation(realAnimPath, realAnimName, false);
	if (L"" != realAnimName) {
		m_pAnimator->Play(realAnimName, false);
		m_pAnimator->GetCurAnimation()->SetFrame(0);
	}
}

// 플레이어 스킬을 받아서 스킬에 해당하는 피격 이펙트가 있으면 같이 재생시켜준다
void MEffectDiv::PlayDamagedAnim(int damage)
{
	m_pAnimator->Play(L"bloodSplatter_monster", false);
	m_pAnimator->GetCurAnimation()->SetFrame(0);
}

void MEffectDiv::Init()
{
	m_pAnimator->LoadAnimation(L"resource\\animations\\fx\\blood_splat_anim\\blood_splatter.sprite-blood_splatter.atlas", false, L"bloodSplatter_monster");
	Animation* bloodSplatAnim = m_pAnimator->FindAnimation(L"bloodSplatter_monster");
	bloodSplatAnim->SetAllFrameOffset(Vec2(0.f, 150.f));

	if (dMon->GetName() == L"해골 병사") {

		CSkill* skill1 = dMon->GetCurSkills()[0];
		wstring realAnimName = skill1->GetRealAnimName();
		wstring realAnimPath = skill1->GetRealAnimPath();

		if (L"" != realAnimName) {

			m_pAnimator->LoadAnimation(realAnimPath, true, realAnimName);
			Animation* skillAnim = m_pAnimator->FindAnimation(realAnimName);
			skillAnim->SetMulScale(1.2f);
			skillAnim->SetAllFrameOffset(Vec2(-200.f, 200.f));
		}

	}
	else if (dMon->GetName() == L"해골 방어병") {
		CSkill* skill1 = dMon->GetCurSkills()[0];
		wstring realAnimName = skill1->GetRealAnimName();
		wstring realAnimPath = skill1->GetRealAnimPath();

		if (L"" != realAnimName) {

			m_pAnimator->LoadAnimation(realAnimPath, true, realAnimName);
			Animation* skillAnim = m_pAnimator->FindAnimation(realAnimName);
			skillAnim->SetMulScale(1.2f);
			skillAnim->SetAllFrameOffset(Vec2(-200.f, 300.f));
		}
	}
	else if (dMon->GetName() == L"해골 궁수") {
		CSkill* skill1 = dMon->GetCurSkills()[0];
		wstring realAnimName = skill1->GetRealAnimName();
		wstring realAnimPath = skill1->GetRealAnimPath();

		if (L"" != realAnimName) {

			m_pAnimator->LoadAnimation(realAnimPath, true, realAnimName);
			Animation* skillAnim = m_pAnimator->FindAnimation(realAnimName);
			skillAnim->SetMulScale(1.2f);
			skillAnim->SetAllFrameOffset(Vec2(-200.f, 200.f));
		}
	}
	else if (dMon->GetName() == L"해골 보좌관") {
		CSkill* skill1 = dMon->GetCurSkills()[0];
		wstring realAnimName = skill1->GetRealAnimName();
		wstring realAnimPath = skill1->GetRealAnimPath();

		if (L"" != realAnimName) {

			m_pAnimator->LoadAnimation(realAnimPath, true, realAnimName);
			Animation* skillAnim = m_pAnimator->FindAnimation(realAnimName);
			skillAnim->SetMulScale(1.2f);
			skillAnim->SetAllFrameOffset(Vec2(-300.f, 140.f));
		}
	}
	else if (dMon->GetName() == L"예언자") {

		CSkill* prophecy = dMon->GetCurSkills()[0];
		wstring realAnimName = prophecy->GetRealAnimName();
		wstring realAnimPath = prophecy->GetRealAnimPath();

		if (L"" != realAnimName) {

			m_pAnimator->LoadAnimation(realAnimPath, true, realAnimName);
			Animation* skillAnim = m_pAnimator->FindAnimation(realAnimName);
			skillAnim->SetMulScale(1.2f);
			skillAnim->SetAllFrameOffset(Vec2(-420.f, -50.f));
		}

		CSkill* onEye = dMon->GetCurSkills()[2];
		realAnimName = onEye->GetRealAnimName();
		realAnimPath = onEye->GetRealAnimPath();

		if (L"" != realAnimName) {

			m_pAnimator->LoadAnimation(realAnimPath, true, realAnimName);
			Animation* skillAnim = m_pAnimator->FindAnimation(realAnimName);
			skillAnim->SetMulScale(1.2f);
			skillAnim->SetAllFrameOffset(Vec2(-370.f, -50.f));
		}

		CSkill* prophet = dMon->GetCurSkills()[3];
		realAnimName = prophet->GetRealAnimName();
		realAnimPath = prophet->GetRealAnimPath();

		if (L"" != realAnimName) {

			m_pAnimator->LoadAnimation(realAnimPath, true, realAnimName);
			Animation* skillAnim = m_pAnimator->FindAnimation(realAnimName);
			skillAnim->SetMulScale(1.2f);
			skillAnim->SetAllFrameOffset(Vec2(-190.f, 80.f));
		}

		//for (int i = 0; i < 4; i++) {

		//	CSkill* skill1 = dMon->GetCurSkills()[i];

		//	if (nullptr != skill1) {
		//		wstring realAnimName = skill1->GetRealAnimName();
		//		wstring realAnimPath = skill1->GetRealAnimPath();

		//		if (L"" != realAnimName) {

		//			m_pAnimator->LoadAnimation(realAnimPath, true, realAnimName);
		//			Animation* skillAnim = m_pAnimator->FindAnimation(realAnimName);
		//			skillAnim->SetMulScale(1.2f);
		//			skillAnim->SetAllFrameOffset(Vec2(-420.f, -50.f));
		//		}
		//	}

		//}

	}
}