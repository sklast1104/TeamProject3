#pragma once
#include "DivUI.h"

class CDarkMonster;
class CSelectedOverlay;
class DivUI;
class MEffectDiv;
class MonAtEffect;
class CSkill;
class CHero;

class CMonDiv :
	public DivUI
{

private :

	CDarkMonster* monster;
	CSelectedOverlay* overlay;
	DivUI* curHpBar;
	MEffectDiv* effect;
	MonAtEffect* atEffect;

	wstring combatAnimName;

public :

	CMonDiv(CDarkMonster* _monster);
	~CMonDiv() {}

	virtual void CreateAnimator() override;
	void PlayCombatAnim();
	void PlayAttackedAnim(CHero* _hero, CSkill* _skil);
	void PlayCurSkilByIdx(int _idx);
	void PlayMonAttackedSoud();

	void EnableAllChildUI(bool _enable);

	void SetOverlay(CSelectedOverlay* _overlay) { overlay = _overlay; }
	void EnableOverlay(bool _isEnable);
	void SetCuHpBar(DivUI* _hpBar) { curHpBar = _hpBar; }
	void UpdateHpBar();

	void SetEffect(MEffectDiv* _effect) { effect = _effect; }
	void SetAtEffect(MonAtEffect* _effect) { atEffect = _effect; }

	CLONE(CMonDiv);
};

