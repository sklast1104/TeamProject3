#include "stdafx.h"
#include "CHeroDiv.h"
#include "AnimatorDK.h"
#include "Animation.h"
#include "CHero.h"
#include "CSelectedOverlay.h"
#include "DivUI.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "CSkill.h"
#include "HEffectDiv.h"
#include "HeroAtEffect.h"

CHeroDiv::CHeroDiv(CHero* _hero)
	: hero{_hero}
{
	CreateAnimator();

	idleAnimName = hero->GetJobName() + L"_idle";
	walkAnimName = hero->GetJobName() + L"_walk";
	combatAnimName = hero->GetJobName() + L"_combat";
	attackedAnimName = hero->GetJobName() + L"_attacked";

	float heightFloat = 483.f;

	if (hero->GetJobName() == L"������") {

		m_pAnimator->LoadAnimation(L"resource\\animations\\hero\\Crusader\\Sprite\\crusader.sprite.idle-idle.atlas", idleAnimName);
		m_pAnimator->LoadAnimation(L"resource\\animations\\hero\\Crusader\\Sprite\\crusader.sprite.walk-walk.atlas", walkAnimName);
		m_pAnimator->LoadAnimation(L"resource\\animations\\hero\\Crusader\\Sprite\\crusader.sprite.combat-combat.atlas", combatAnimName);
		m_pAnimator->LoadAnimation(L"resource\\animations\\hero\\Crusader\\Sprite\\crusader_defend\\crusader.sprite.defend-defend.atlas", attackedAnimName);
		// �ִϸ��̼� yũ�Ⱑ ���� �ٸ��� �� ũ�⸦ �޾ƿͼ� ���� ũ��� �˾Ƽ� ������ ���������� �ڵ�����
		// ����ϴ� ������ ¥ ���� �Ǵ��� ���

		// ������ ���� ��ġ�� 353 + 130 = 483
		// 
		Animation* idleAnim = m_pAnimator->FindAnimation(idleAnimName);
		float idleHeight = idleAnim->GetFrameHeight();
		idleAnim->SetAllFrameOffset(Vec2(0.f, heightFloat - idleHeight));
		idleAnim->SetMulScale(1.1f);

		Animation* walkAnim = m_pAnimator->FindAnimation(walkAnimName);
		float walkHeight = walkAnim->GetFrameHeight();
		walkAnim->SetAllFrameOffset(Vec2(0.f, heightFloat - walkHeight));
		walkAnim->SetMulScale(1.1f);

		Animation* combatAnim = m_pAnimator->FindAnimation(combatAnimName);
		float combatHeight = combatAnim->GetFrameHeight();
		combatAnim->SetAllFrameOffset(Vec2(0.f, heightFloat - combatHeight));
		combatAnim->SetMulScale(1.1f);

		Animation* attackedAnim = m_pAnimator->FindAnimation(attackedAnimName);
		float attackedHeight = attackedAnim->GetFrameHeight();
		attackedAnim->SetAllFrameOffset(Vec2(0.f, heightFloat - attackedHeight));
		attackedAnim->SetMulScale(1.2f);

		// �⺻ �ִϸ��̼� ������ �߽���ġ ����ε�
		// ui�� ��ġ�� lefttop�̶� �̰��� ����

		for (int i = 0; i < 4; i++) {
			CSkill* skill = hero->GetCurSkills()[i];
			wstring skillName =  skill->GetSkilAnimName();
			wstring skillPath = skill->GetAnimPath();

			m_pAnimator->LoadAnimation(skillPath, skillName);

			Animation* skillAnim = m_pAnimator->FindAnimation(skillName);
			float animHeight = skillAnim->GetFrameHeight();
			skillAnim->SetAllFrameOffset(Vec2(0.f, heightFloat - animHeight));
			skillAnim->SetMulScale(1.2f);

			wstring realAnimName = skill->GetRealAnimName();
			wstring realAnimPath = skill->GetRealAnimPath();

			if (L"" != realAnimName) {

				m_pAnimator->LoadAnimation(realAnimPath, realAnimName);
			}
		}

		/*CSkill* renu = hero->GetCurSkills()[3];
		wstring realAnimName = renu->GetRealAnimName();

		Animation* skillAnim = m_pAnimator->FindAnimation(realAnimName);
		float animHeight = skillAnim->GetFrameHeight();
		skillAnim->SetAllFrameOffset(Vec2(0.f, 100.f));*/
		//skillAnim->SetMulScale(1.2f);

		//m_pAnimator->Play(realAnimName, true);
		//m_pAnimator->Play(idleAnimName, true);
	}
	else if (hero->GetJobName() == L"��󰭵�") {

		m_pAnimator->LoadAnimation(L"resource\\animations\\hero\\Highwayman\\Sprite\\highwayman.sprite.idle-idle.atlas", idleAnimName);
		m_pAnimator->LoadAnimation(L"resource\\animations\\hero\\Highwayman\\Sprite\\highwayman.sprite.walk-walk.atlas", walkAnimName);
		m_pAnimator->LoadAnimation(L"resource\\animations\\hero\\Highwayman\\Sprite\\highwayman.sprite.combat-combat.atlas", combatAnimName);
		m_pAnimator->LoadAnimation(L"resource\\animations\\hero\\Highwayman\\Sprite\\highway_man_defend\\highwayman.sprite.defend-defend.atlas", attackedAnimName);

		Animation* idleAnim = m_pAnimator->FindAnimation(idleAnimName);
		float idleHeight = idleAnim->GetFrameHeight();
		idleAnim->SetAllFrameOffset(Vec2(0.f, heightFloat - idleHeight));
		idleAnim->SetMulScale(1.1f);

		Animation* walkAnim = m_pAnimator->FindAnimation(walkAnimName);
		float walkHeight = walkAnim->GetFrameHeight();
		walkAnim->SetAllFrameOffset(Vec2(0.f, heightFloat - walkHeight));
		walkAnim->SetMulScale(1.1f);

		Animation* combatAnim = m_pAnimator->FindAnimation(combatAnimName);
		float combatHeight = combatAnim->GetFrameHeight();
		combatAnim->SetAllFrameOffset(Vec2(0.f, heightFloat - combatHeight));
		combatAnim->SetMulScale(1.1f);

		Animation* attackedAnim = m_pAnimator->FindAnimation(attackedAnimName);
		float attackedHeight = attackedAnim->GetFrameHeight();
		attackedAnim->SetMulScale(1.2f);
		attackedAnim->SetAllFrameOffset(Vec2(0.f, heightFloat - attackedHeight));

		for (int i = 0; i < 4; i++) {
			CSkill* skill = hero->GetCurSkills()[i];
			wstring skillName = skill->GetSkilAnimName();
			wstring skillPath = skill->GetAnimPath();

			m_pAnimator->LoadAnimation(skillPath, skillName);

			Animation* skillAnim = m_pAnimator->FindAnimation(skillName);
			float animHeight = skillAnim->GetFrameHeight();
			skillAnim->SetAllFrameOffset(Vec2(0.f, heightFloat - animHeight));
			skillAnim->SetMulScale(1.2f);
		}

		m_pAnimator->Play(idleAnimName, true);
	}
	else if (hero->GetJobName() == L"���� �ǻ�") {

		m_pAnimator->LoadAnimation(L"resource\\animations\\hero\\Doctor\\Sprite\\plague_doctor.sprite.idle-idle.atlas", idleAnimName);
		m_pAnimator->LoadAnimation(L"resource\\animations\\hero\\Doctor\\Sprite\\plague_doctor.sprite.walk-walk.atlas", walkAnimName);
		m_pAnimator->LoadAnimation(L"resource\\animations\\hero\\Doctor\\Sprite\\plague_doctor.sprite.combat-combat.atlas", combatAnimName);
		m_pAnimator->LoadAnimation(L"resource\\animations\\hero\\Doctor\\Sprite\\plague_doctor.sprite.defend-defend.atlas", attackedAnimName);

		Animation* idleAnim = m_pAnimator->FindAnimation(idleAnimName);
		float idleHeight = idleAnim->GetFrameHeight();
		idleAnim->SetAllFrameOffset(Vec2(0.f, heightFloat - idleHeight));
		idleAnim->SetMulScale(1.1f);

		Animation* walkAnim = m_pAnimator->FindAnimation(walkAnimName);
		float walkHeight = walkAnim->GetFrameHeight();
		walkAnim->SetAllFrameOffset(Vec2(0.f, heightFloat - walkHeight));
		walkAnim->SetMulScale(1.1f);

		Animation* combatAnim = m_pAnimator->FindAnimation(combatAnimName);
		float combatHeight = combatAnim->GetFrameHeight();
		combatAnim->SetAllFrameOffset(Vec2(0.f, heightFloat - combatHeight));
		combatAnim->SetMulScale(1.1f);

		Animation* attackedAnim = m_pAnimator->FindAnimation(attackedAnimName);
		float attackedHeight = attackedAnim->GetFrameHeight();
		attackedAnim->SetMulScale(1.2f);
		attackedAnim->SetAllFrameOffset(Vec2(0.f, heightFloat - attackedHeight));

		for (int i = 0; i < 4; i++) {
			CSkill* skill = hero->GetCurSkills()[i];
			wstring skillName = skill->GetSkilAnimName();
			wstring skillPath = skill->GetAnimPath();

			if (L"" != skillName) {
				m_pAnimator->LoadAnimation(skillPath, skillName);

				Animation* skillAnim = m_pAnimator->FindAnimation(skillName);
				float animHeight = skillAnim->GetFrameHeight();
				skillAnim->SetAllFrameOffset(Vec2(0.f, heightFloat - animHeight));
				skillAnim->SetMulScale(1.2f);
			}
		}

		m_pAnimator->Play(idleAnimName, true);

	}
}

void CHeroDiv::CreateAnimator()
{
	m_pAnimator = new AnimatorDK;

	m_pAnimator->SetOwnerObject(this);
}

void CHeroDiv::PlayHeroIdleAnim()
{
	m_pAnimator->Play(idleAnimName, true);
}

void CHeroDiv::PlayHeroWalkAnim()
{
	m_pAnimator->Play(walkAnimName, true);
}

void CHeroDiv::PlayHeroCombatAnim()
{
	m_pAnimator->Play(combatAnimName, true);
}

void CHeroDiv::PlayCurSkillByIdx(int _idx)
{
	m_pAnimator->Play(hero->GetCurSkills()[_idx]->GetSkilAnimName(), true);
	if (nullptr != effect) {
		effect->PlaySkillAnim(hero->GetCurSkills()[_idx]);
	}
	
}

void CHeroDiv::PlayAttackedAnim(CDarkMonster* _monster, CSkill* skill)
{
	m_pAnimator->Play(attackedAnimName, true);
	effect->PlayDamagedAnim(3);
	atEffect->PlayMskAttacked(_monster, skill);
}

void CHeroDiv::EnableOverlay(bool _isEnable)
{
	if (_isEnable) {
		overlay->SetCanRend(true);
	}
	else {
		overlay->SetCanRend(false);
	}
}

void CHeroDiv::EnableAttackedOverlay(bool _isEnable)
{
	if (_isEnable) {
		attackedOverlay->SetCanRend(true);
	}
	else {
		attackedOverlay->SetCanRend(false);
	}
}

void CHeroDiv::UpdateHpBar()
{
	int curHp = hero->GetCurHp();
	int maxHp = hero->GetHp();

	float hpPercent = (float)curHp / maxHp;

	curHpBar->SetScale(Vec2(100.f * hpPercent, 10.f));
}

void CHeroDiv::EnableAllChildUI(bool _enable)
{
	vector<UI*> vec = GetChildUI();

	if (_enable) {

		for (int i = 0; i < vec.size(); i++) {
			DivUI* div = dynamic_cast<DivUI*>(vec[i]);
			if (div) {
				if (div->GetName() != L"focusedOverlay_hero") {
					div->SetCanRend(_enable);
				}

				
				
			}
		}

	}
	else {
		for (int i = 0; i < vec.size(); i++) {
			DivUI* div = dynamic_cast<DivUI*>(vec[i]);
			if (div) {
				if (div->GetName() == L"heroEffect" || div->GetName() == L"hAtEffect") {
					continue;
				}
				div->SetCanRend(_enable);
			}
		}
	}

}

void CHeroDiv::EnableSkill()
{
	DivUI* pseudoUI = SceneMgr::GetInst()->GetCurScene()->GetPseudoUI();
	DivUI* skillContainer = (DivUI*)FindUIByName(pseudoUI, L"skillContainer");
	skillContainer->updateValue();
}

void CHeroDiv::EnableOnYouOvl(bool _isEnable)
{

	onYouOvl->SetCanRend(_isEnable);
}
