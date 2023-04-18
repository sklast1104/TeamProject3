#include "stdafx.h"
#include "CWoodS.h"

CWoodS::CWoodS()
{
	name = L"���� S";
	resPath = L"";
	monsterType = L"����";

	curHp = 12;
	maxHp = 12;

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
	attackedAnimName = L"���� S �ǰ�";
	attackedAnimPath = L"resource\\animations\\monster\\wood_small\\pew_small.sprite.combat-combat.atlas";

	attackedSoundName = L"���� S �ǰ� ����";
	attackedSoundPath = L"resource\\sound\\Monsters\\Ruins\\char_en_vo_pew_hurt_01 {0d3b8f39-1f44-4ba6-b645-385495d6b961}.wav";

	// ��ų�� �ȸ��� (���� ���ٰ���)
}
