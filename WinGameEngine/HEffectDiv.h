#pragma once
#include "DivUI.h"

class CHero;
class CSkill;

class HEffectDiv :
	public DivUI
{
private :

	CHero* hero;

public :

	void Init();

	HEffectDiv(CHero* _hero);
	~HEffectDiv() {}

	void PlaySkillAnim(CSkill* skill);
	void PlayDamagedAnim(int damage);
};

