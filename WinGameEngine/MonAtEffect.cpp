#include "stdafx.h"
#include "MonAtEffect.h"
#include "CSkill.h"
#include "Animator.h"
#include "Animation.h"
#include "CHero.h"
#include "GameMgr.h"

void MonAtEffect::InitAttackedAnim()
{
	// ���� �׳� ��� ���� ����Ʈ �̸� �ε��� ���� �� ���� ����

	GameMgr* mgr = GameMgr::GetInst();
	const array<CHero*, 4>&  squad = mgr->GetSquad();

	for (int i = 0; i < 4; i++) {
		
		if (nullptr != squad[i]) {

			const array<CSkill*, 4> skills = squad[i]->GetCurSkills();

			for (int i = 0; i < 4; i++) {

				if (nullptr != skills[i]) {

					wstring attackedAnimName = skills[i]->GetAttackedName();
					wstring attackedAnimPath = skills[i]->GetAttackedPath();

					if (L"" != attackedAnimName) {
						m_pAnimator->LoadAnimation(attackedAnimPath, true, attackedAnimName);
					}
				}
			}


			if (squad[i]->GetName() == L"��󰭵�") {

				wstring skilName = skills[2]->GetAttackedName();
				wstring skilPath = skills[2]->GetAttackedPath();

				m_pAnimator->FindAnimation(skilName)->SetAllFrameOffset(Vec2(0.f, 240.f));
			}

		}
	}
}

void MonAtEffect::PlayPskAttacked(CHero* _player, CSkill* _skil)
{

	if (L"��󰭵�" == _player->GetJobName()) {

		wstring attackedAnimName = _skil->GetAttackedName();
		wstring attackedAnimPath = _skil->GetAttackedPath();

		if (_skil->GetSkillName() == L"����ź �߻� 1" ) {
			m_pAnimator->FindAnimation(attackedAnimName)->SetAllFrameOffset(Vec2(0.f, 240.f));
		}
		else if (_skil->GetSkillName() == L"���� ��� 1") {
			m_pAnimator->FindAnimation(attackedAnimName)->SetAllFrameOffset(Vec2(0.f, 280.f));
		}

		if (L"" != attackedAnimName) {
			m_pAnimator->Play(attackedAnimName, false);
			m_pAnimator->GetCurAnimation()->SetFrame(0);
		}
	}
	else if (L"���� �ǻ�" == _player->GetJobName()) {

		wstring attackedAnimName = _skil->GetAttackedName();
		wstring attackedAnimPath = _skil->GetAttackedPath();

		if (_skil->GetSkillName() == L"����ź 1") {
			m_pAnimator->FindAnimation(attackedAnimName)->SetAllFrameOffset(Vec2(0.f, 280.f));
		}

		if (L"" != attackedAnimName) {
			m_pAnimator->Play(attackedAnimName, false);
			m_pAnimator->GetCurAnimation()->SetFrame(0);
		}

	}
}

	
