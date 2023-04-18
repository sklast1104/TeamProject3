#pragma once
#include "DivUI.h"

class CDarkMonster;
class CSkill;
class CHero;

class MonAtEffect :
	public DivUI
{
private :

public :

	void InitAttackedAnim();
	void PlayPskAttacked(CHero* _player, CSkill* _skil);

};

