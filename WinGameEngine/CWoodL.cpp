#include "stdafx.h"
#include "CWoodL.h"

CWoodL::CWoodL()
{
	name = L"���� L";
	resPath = L"";
	monsterType = L"����";

	curHp = 35;
	maxHp = 35;

	avoidRate = 0;
	shieldRate = 15;
	speed = 2;

	faintResist = 25;
	toxinResist = 10;
	bleedResist = 200;
	weakResist = 15;
	moveResist = 20;

	damageLower = 6;
	damageUpper = 12;

	// �ǰ� ���
	attackedAnimName = L"���� L �ǰ�";
	attackedAnimPath = L"resource\\animations\\monster\\wood_large\\pew_large.sprite.combat-combat.atlas";

	attackedSoundName = L"���� L �ǰ� ����";
	attackedSoundPath = L"resource\\sound\\Monsters\\Ruins\\char_en_vo_pew_hurt_03 {aaaba5a6-2423-413f-a917-96609e5e1867}.wav";

	// ��ų�� �ȸ��� (���� ���ٰ���)
}
