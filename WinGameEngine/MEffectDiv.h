#pragma once
#include "DivUI.h"

class CDarkMonster;
class CSkill;

class MEffectDiv :
	public DivUI
{

private :

	CDarkMonster* dMon;

public :

	void Init();

	MEffectDiv(CDarkMonster* dMon);
	~MEffectDiv() {}

	void PlaySkillAnim(CSkill* skill);
	void PlayDamagedAnim(int damage);
};

