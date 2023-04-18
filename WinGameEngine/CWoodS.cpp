#include "stdafx.h"
#include "CWoodS.h"

CWoodS::CWoodS()
{
	name = L"나무 S";
	resPath = L"";
	monsterType = L"나무";

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

	// 피격 모션
	attackedAnimName = L"나무 S 피격";
	attackedAnimPath = L"resource\\animations\\monster\\wood_small\\pew_small.sprite.combat-combat.atlas";

	attackedSoundName = L"나무 S 피격 사운드";
	attackedSoundPath = L"resource\\sound\\Monsters\\Ruins\\char_en_vo_pew_hurt_01 {0d3b8f39-1f44-4ba6-b645-385495d6b961}.wav";

	// 스킬은 안만듬 (턴을 안줄거임)
}
