#include "stdafx.h"
#include "CHero.h"

int CHero::id = 0;

CHero::CHero()
	: name{ L"" }, key{ L"" }, path{ L"" }
	, hp{ 0 }, hitRate{ 0 }, avoidanceRate{ 0 }, criticalHitRate{ 0 }
	, defenseRate{ 0 }, damageLower{ 0 }, damageUpper{ 0 }
	, speed{ 0 }, level{ 1 }, equipLevel{1}, armorLevel{1}, curExp{0}
{
	skillArray.fill(nullptr);
	curSkillArray.fill(nullptr);
	id += 1;
	pKey = id;
}

CHero::~CHero()
{
	// ��ü ��ų�� �������� ���� ��ų�� �������� ����� ������ �� �ʿ� X
	for (int i = 0; i < 7; i++) {
		Safe_Delete<CSkill*>(skillArray[i]);
	}

	/*for (int i = 0; i < 4; i++) {
		Safe_Delete<CSkill*>(curSkillArray[i]);
	}*/
}
