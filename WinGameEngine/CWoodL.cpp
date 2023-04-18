#include "stdafx.h"
#include "CWoodL.h"

CWoodL::CWoodL()
{
	name = L"나무 L";
	resPath = L"";
	monsterType = L"나무";

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

	// 피격 모션
	attackedAnimName = L"나무 L 피격";
	attackedAnimPath = L"resource\\animations\\monster\\wood_large\\pew_large.sprite.combat-combat.atlas";

	attackedSoundName = L"나무 L 피격 사운드";
	attackedSoundPath = L"resource\\sound\\Monsters\\Ruins\\char_en_vo_pew_hurt_03 {aaaba5a6-2423-413f-a917-96609e5e1867}.wav";

	// 스킬은 안만듬 (턴을 안줄거임)
}
