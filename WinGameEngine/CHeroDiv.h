#pragma once
#include "DivUI.h"

class CHero;
class CSelectedOverlay;
class HEffectDiv;
class HeroAtEffect;
class CDarkMonster;
class CSkill;

class CHeroDiv :
	public DivUI
{
private :

	CHero* hero;
	HEffectDiv* effect;
	HeroAtEffect* atEffect;
	CSelectedOverlay* overlay;
	DivUI* attackedOverlay;
	DivUI* curHpBar;
	DivUI* onYouOvl;

	wstring idleAnimName;
	wstring walkAnimName;
	wstring combatAnimName;
	wstring attackedAnimName;

public :

	CHeroDiv(CHero* _hero);
	~CHeroDiv() {}

	virtual void CreateAnimator() override;

	void PlayHeroIdleAnim();
	void PlayHeroWalkAnim();
	void PlayHeroCombatAnim();
	void PlayCurSkillByIdx(int _idx);
	void PlayAttackedAnim(CDarkMonster* _monster, CSkill* skill);

	void SetEffect(HEffectDiv* _effect) { effect = _effect; }
	void SetAtEffect(HeroAtEffect* _atEffect) { atEffect = _atEffect; }
	HEffectDiv* GetEffect() { return effect; }

	void EnableOverlay(bool _isEnable);
	void EnableAttackedOverlay(bool _isEnable);
	void SetOverlay(CSelectedOverlay* _overlay) { overlay = _overlay; }
	void SetAttackedOverlay(DivUI* _overlay) { attackedOverlay = _overlay; }
	void SetCurHpBar(DivUI* _hpBar) { curHpBar = _hpBar; }
	void SetOnYouOvl(DivUI* _ovl) { onYouOvl = _ovl; }

	void UpdateHpBar();

	void EnableAllChildUI(bool _enable);

	void EnableSkill();
	
	void EnableOnYouOvl(bool _isEnable);

	CLONE(CHeroDiv);
};

