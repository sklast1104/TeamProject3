#include "stdafx.h"
#include "CWoodM.h"

CWoodM::CWoodM()
{
	name = L"나무 M";
	resPath = L"";
	monsterType = L"나무";

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

	// 피격 모션
	attackedAnimName = L"나무 M 피격";
	attackedAnimPath = L"resource\\animations\\monster\\wood_medium\\pew_medium.sprite.combat-combat.atlas";

	attackedSoundName = L"나무 M 피격 사운드";
	attackedSoundPath = L"resource\\sound\\Monsters\\Ruins\\char_en_vo_pew_hurt_02 {0843e7c1-e423-4632-a9c7-a6e1a04a2872}.wav";

	// 스킬은 안만듬 (턴을 안줄거임)
}
