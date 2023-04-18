#include "stdafx.h"
#include "CDarkMonster.h"

CDarkMonster::CDarkMonster()
	: name{ L"" }, resPath{ L"" }, monsterType{ L"" }
	, curHp{ 0 }, maxHp{ 0 }
	, shieldRate{ 0 }, avoidRate{ 0 }, speed{ 0 }
	, faintResist{ 0 }, toxinResist{ 0 }, bleedResist{ 0 }
	, weakResist{ 0 }, moveResist{ 0 }
{
	for (int i = 0; i < 4; i++) {
		curSkillArray[i] = nullptr;
	}
}

CDarkMonster::~CDarkMonster()
{
	for (int i = 0; i < curSkillArray.size(); i++) {
		Safe_Delete<CSkill*>(curSkillArray[i]);
	}

	
}
