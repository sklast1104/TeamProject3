#pragma once
#include "DivUI.h"

class CDarkMonster;
class CSkill;
class CHero;

class HeroAtEffect :
	public DivUI
{


private :

public :

	void InitAttackedAnim();
	void PlayMskAttacked(CDarkMonster* _monster, CSkill* _skil);

};

