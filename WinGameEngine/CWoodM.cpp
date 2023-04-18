#include "stdafx.h"
#include "CWoodM.h"

CWoodM::CWoodM()
{
	name = L"���� M";
	resPath = L"";
	monsterType = L"����";

	curHp = 20;
	maxHp = 20;

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
	attackedAnimName = L"���� M �ǰ�";
	attackedAnimPath = L"resource\\animations\\monster\\wood_medium\\pew_medium.sprite.combat-combat.atlas";

	attackedSoundName = L"���� M �ǰ� ����";
	attackedSoundPath = L"resource\\sound\\Monsters\\Ruins\\char_en_vo_pew_hurt_02 {0843e7c1-e423-4632-a9c7-a6e1a04a2872}.wav";

	// ��ų�� �ȸ��� (���� ���ٰ���)
}
