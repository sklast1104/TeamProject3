#include "stdafx.h"
#include "CMonDiv.h"
#include "CDarkMonster.h"
#include "AnimatorDK.h"
#include "Animation.h"
#include "CSelectedOverlay.h"
#include "CSkill.h"
#include "ResMgr.h"
#include "Sound.h"
#include "MEffectDiv.h"
#include "MonAtEffect.h"


CMonDiv::CMonDiv(CDarkMonster* _monster)
	: monster{_monster}
{
	CreateAnimator();

	combatAnimName = monster->GetName() + L"_combat";

	float heightFloat = 483.f;

	if (monster->GetName() == L"ÇØ°ñ º´»ç") {

		m_pAnimator->LoadAnimation(L"resource\\animations\\monster\\Bone Soldier\\Sprite\\skeleton_militia.sprite.combat-combat.atlas", true, combatAnimName);
		m_pAnimator->LoadAnimation(monster->GetAttackedAnimPath(), true, monster->GetAttackedAnimName());

		Animation* combatAnim = m_pAnimator->FindAnimation(combatAnimName);
		//float combatHeight = combatAnim->GetFrameHeight();
		combatAnim->SetAllFrameOffset(Vec2(0.f, 180.f));
		combatAnim->SetMulScale(1.1f);

		Animation* attackedAnim = m_pAnimator->FindAnimation(monster->GetAttackedAnimName());
		attackedAnim->SetAllFrameOffset(Vec2(0.f, 180.f));
		attackedAnim->SetMulScale(1.4f);
		

		for (int i = 0; i < 4; i++) {
			CSkill* skill = monster->GetCurSkills()[i];

			if (nullptr != skill) {
				wstring skillName = skill->GetSkilAnimName();
				wstring skillPath = skill->GetAnimPath();

				m_pAnimator->LoadAnimation(skillPath, true, skillName);

				Animation* skillAnim = m_pAnimator->FindAnimation(skillName);
				float animHeight = skillAnim->GetFrameHeight();
				skillAnim->SetAllFrameOffset(Vec2(-150.f, 170.f));
				skillAnim->SetMulScale(1.3f);
			}
		}
	}
	else if (monster->GetName() == L"ÇØ°ñ ¹æ¾îº´") {
		m_pAnimator->LoadAnimation(L"resource\\animations\\monster\\Bone Defender\\Sprite\\skeleton_defender.sprite.combat-combat.atlas", true, combatAnimName);
		m_pAnimator->LoadAnimation(monster->GetAttackedAnimPath(), true, monster->GetAttackedAnimName());

		Animation* combatAnim = m_pAnimator->FindAnimation(combatAnimName);
		//float combatHeight = combatAnim->GetFrameHeight();
		combatAnim->SetAllFrameOffset(Vec2(-40.f, 180.f));
		combatAnim->SetMulScale(1.1f);

		Animation* attackedAnim = m_pAnimator->FindAnimation(monster->GetAttackedAnimName());
		attackedAnim->SetAllFrameOffset(Vec2(-60.f, 180.f));
		attackedAnim->SetMulScale(1.2f);


		for (int i = 0; i < 4; i++) {
			CSkill* skill = monster->GetCurSkills()[i];

			if (nullptr != skill) {
				wstring skillName = skill->GetSkilAnimName();
				wstring skillPath = skill->GetAnimPath();

				m_pAnimator->LoadAnimation(skillPath, true, skillName);

				Animation* skillAnim = m_pAnimator->FindAnimation(skillName);
				float animHeight = skillAnim->GetFrameHeight();
				skillAnim->SetAllFrameOffset(Vec2(-150.f, 170.f));
				skillAnim->SetMulScale(1.3f);
			}
		}
	}
	else if (monster->GetName() == L"ÇØ°ñ ±Ã¼ö") {
		m_pAnimator->LoadAnimation(L"resource\\animations\\monster\\Bone Arbalist\\Sprite\\skeleton_arbalist.sprite.combat-combat.atlas", true, combatAnimName);
		m_pAnimator->LoadAnimation(monster->GetAttackedAnimPath(), true, monster->GetAttackedAnimName());

		Animation* combatAnim = m_pAnimator->FindAnimation(combatAnimName);
		//float combatHeight = combatAnim->GetFrameHeight();
		combatAnim->SetAllFrameOffset(Vec2(-50.f, 180.f));
		combatAnim->SetMulScale(1.1f);

		Animation* attackedAnim = m_pAnimator->FindAnimation(monster->GetAttackedAnimName());
		attackedAnim->SetAllFrameOffset(Vec2(0.f, 150.f));
		attackedAnim->SetMulScale(1.3f);


		for (int i = 0; i < 4; i++) {
			CSkill* skill = monster->GetCurSkills()[i];

			if (nullptr != skill) {
				wstring skillName = skill->GetSkilAnimName();
				wstring skillPath = skill->GetAnimPath();

				m_pAnimator->LoadAnimation(skillPath, true, skillName);

				Animation* skillAnim = m_pAnimator->FindAnimation(skillName);
				float animHeight = skillAnim->GetFrameHeight();
				skillAnim->SetAllFrameOffset(Vec2(-150.f, 170.f));
				skillAnim->SetMulScale(1.3f);
			}
		}
	}
	else if (monster->GetName() == L"ÇØ°ñ º¸ÁÂ°ü") {
		m_pAnimator->LoadAnimation(L"resource\\animations\\monster\\Bone Courtier\\Sprite\\skeleton_courtier.sprite.combat-combat.atlas", true, combatAnimName);
		m_pAnimator->LoadAnimation(monster->GetAttackedAnimPath(), true, monster->GetAttackedAnimName());

		Animation* combatAnim = m_pAnimator->FindAnimation(combatAnimName);
		//float combatHeight = combatAnim->GetFrameHeight();
		combatAnim->SetAllFrameOffset(Vec2(0.f, 180.f));
		combatAnim->SetMulScale(1.1f);

		Animation* attackedAnim = m_pAnimator->FindAnimation(monster->GetAttackedAnimName());
		attackedAnim->SetAllFrameOffset(Vec2(0.f, 180.f));
		attackedAnim->SetMulScale(1.4f);


		for (int i = 0; i < 4; i++) {
			CSkill* skill = monster->GetCurSkills()[i];

			if (nullptr != skill) {
				wstring skillName = skill->GetSkilAnimName();
				wstring skillPath = skill->GetAnimPath();

				m_pAnimator->LoadAnimation(skillPath, true, skillName);

				Animation* skillAnim = m_pAnimator->FindAnimation(skillName);
				float animHeight = skillAnim->GetFrameHeight();
				skillAnim->SetAllFrameOffset(Vec2(-150.f, 170.f));
				skillAnim->SetMulScale(1.3f);
			}
		}
	}
	else if (monster->GetName() == L"¿¹¾ðÀÚ") {

		m_pAnimator->LoadAnimation(L"resource\\animations\\monster\\prophet\\prophet.sprite.combat-combat.atlas", true, combatAnimName);
		m_pAnimator->LoadAnimation(monster->GetAttackedAnimPath(), true, monster->GetAttackedAnimName());

		Animation* combatAnim = m_pAnimator->FindAnimation(combatAnimName);
		//float combatHeight = combatAnim->GetFrameHeight();
		combatAnim->SetAllFrameOffset(Vec2(-160.f, -30.f));
		combatAnim->SetMulScale(1.1f);

		Animation* attackedAnim = m_pAnimator->FindAnimation(monster->GetAttackedAnimName());
		attackedAnim->SetAllFrameOffset(Vec2(-200.f, -200.f));
		attackedAnim->SetMulScale(1.4f);


		for (int i = 0; i < 4; i++) {
			CSkill* skill = monster->GetCurSkills()[i];

			if (nullptr != skill) {
				wstring skillName = skill->GetSkilAnimName();
				wstring skillPath = skill->GetAnimPath();

				m_pAnimator->LoadAnimation(skillPath, true, skillName);

				Animation* skillAnim = m_pAnimator->FindAnimation(skillName);
				float animHeight = skillAnim->GetFrameHeight();
				skillAnim->SetAllFrameOffset(Vec2(-150.f, -100.f));
				skillAnim->SetMulScale(1.3f);
			}
		}

	}
	else if (monster->GetName() == L"³ª¹« S") {
		m_pAnimator->LoadAnimation(L"resource\\animations\\monster\\wood_small\\pew_small.sprite.realcombat-combat.atlas", true, combatAnimName);
		m_pAnimator->LoadAnimation(monster->GetAttackedAnimPath(), true, monster->GetAttackedAnimName());

		Animation* combatAnim = m_pAnimator->FindAnimation(combatAnimName);
		//float combatHeight = combatAnim->GetFrameHeight();
		combatAnim->SetAllFrameOffset(Vec2(0.f, 320.f));
		combatAnim->SetMulScale(1.1f);

		Animation* attackedAnim = m_pAnimator->FindAnimation(monster->GetAttackedAnimName());
		attackedAnim->SetAllFrameOffset(Vec2(0.f, 280.f));
		attackedAnim->SetMulScale(1.4f);
	}
	else if (monster->GetName() == L"³ª¹« M") {
		m_pAnimator->LoadAnimation(L"resource\\animations\\monster\\wood_medium\\pew_medium.sprite.realcombat-combat.atlas", true, combatAnimName);
		m_pAnimator->LoadAnimation(monster->GetAttackedAnimPath(), true, monster->GetAttackedAnimName());

		Animation* combatAnim = m_pAnimator->FindAnimation(combatAnimName);
		//float combatHeight = combatAnim->GetFrameHeight();
		combatAnim->SetAllFrameOffset(Vec2(0.f, 260.f));
		combatAnim->SetMulScale(1.1f);

		Animation* attackedAnim = m_pAnimator->FindAnimation(monster->GetAttackedAnimName());
		attackedAnim->SetAllFrameOffset(Vec2(0.f, 220.f));
		attackedAnim->SetMulScale(1.4f);
	}
	else if (monster->GetName() == L"³ª¹« L") {
		m_pAnimator->LoadAnimation(L"resource\\animations\\monster\\wood_large\\pew_large.sprite.combat-realcombat.atlas", true, combatAnimName);
		m_pAnimator->LoadAnimation(monster->GetAttackedAnimPath(), true, monster->GetAttackedAnimName());

		Animation* combatAnim = m_pAnimator->FindAnimation(combatAnimName);
		//float combatHeight = combatAnim->GetFrameHeight();
		combatAnim->SetAllFrameOffset(Vec2(0.f, 200.f));
		combatAnim->SetMulScale(1.1f);

		Animation* attackedAnim = m_pAnimator->FindAnimation(monster->GetAttackedAnimName());
		attackedAnim->SetAllFrameOffset(Vec2(0.f, 160.f));
		attackedAnim->SetMulScale(1.4f);
	}

	//PlayCurSkilByIdx(0);
	PlayCombatAnim();
	
}

void CMonDiv::CreateAnimator()
{
	m_pAnimator = new AnimatorDK;

	m_pAnimator->SetOwnerObject(this);
}

void CMonDiv::PlayCombatAnim()
{
	m_pAnimator->Play(combatAnimName, true);
}

void CMonDiv::PlayAttackedAnim(CHero* _hero, CSkill* _skil)
{
	m_pAnimator->Play(monster->GetAttackedAnimName(), true);
	effect->PlayDamagedAnim(3);
	atEffect->PlayPskAttacked(_hero, _skil);
}

void CMonDiv::PlayCurSkilByIdx(int _idx)
{
	wstring animName = monster->GetCurSkills()[_idx]->GetSkilAnimName();

	wstring soundName = monster->GetCurSkills()[_idx]->GetSoundName();
	wstring soundPath = monster->GetCurSkills()[_idx]->GetSoundPath();

	ResMgr::GetInst()->LoadSound(soundName, soundPath);
	Sound* skilSound = ResMgr::GetInst()->FindSound(soundName);
	skilSound->Play(false);

	m_pAnimator->Play(animName, true);

	if (nullptr != effect) {
		effect->PlaySkillAnim(monster->GetCurSkills()[_idx]);
	}
}

void CMonDiv::PlayMonAttackedSoud()
{
	wstring attackedSName = monster->GetASName();
	wstring attackedSPath = monster->GetASPath();

	ResMgr::GetInst()->LoadSound(attackedSName, attackedSPath);
	Sound* attackedSound = ResMgr::GetInst()->FindSound(attackedSName);
	attackedSound->Play(false);
}

void CMonDiv::EnableAllChildUI(bool _enable)
{
	vector<UI*> vec = GetChildUI();

	if (_enable) {

		for (int i = 0; i < vec.size(); i++) {
			DivUI* div = dynamic_cast<DivUI*>(vec[i]);
			if (div) {

				if (div->GetName() != L"focusedOverlay_monster") {
					div->SetCanRend(_enable);
				}
			}
		}

	}
	else {
		for (int i = 0; i < vec.size(); i++) {
			DivUI* div = dynamic_cast<DivUI*>(vec[i]);
			if (div) {
				if (div->GetName() == L"mEffect" || div->GetName() == L"mAtEffect") {
					continue;
				}
				div->SetCanRend(_enable);
			}
		}
	}
}

void CMonDiv::EnableOverlay(bool _isEnable)
{
	if (_isEnable) {
		overlay->SetCanRend(true);
	}
	else {
		overlay->SetCanRend(false);
	}
}

void CMonDiv::UpdateHpBar()
{
	int curHp = monster->GetCurHp();
	int maxHp = monster->GetMaxHp();

	float hpPercent = (float)curHp / maxHp;

	curHpBar->SetScale(Vec2(100.f * hpPercent, 10.f));
}
