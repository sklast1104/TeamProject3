#include "stdafx.h"
#include "CBoneSoldier.h"

#include "CSkill.h"

CBoneSoldier::CBoneSoldier()
{
	name = L"해골 병사";
	resPath = L"";
	monsterType = L"불경";

	curHp = 10;
	maxHp = 10;

	avoidRate = 0;
	shieldRate = 15;
	speed = 2;

	faintResist = 25;
	toxinResist = 10;
	bleedResist = 200;
	weakResist = 15;
	moveResist = 20;

	damageLower = 3;
	damageUpper = 8;

	CSkill* slash = new CSkill;
	slash->SetSkillName(L"묘지 가르기");
	slash->SetSkillPath(L"");

	slash->GetSkillRange()[0] = true;
	slash->GetSkillRange()[1] = true;
	slash->GetSkillRange()[2] = true;
	slash->GetSkillRange()[3] = true;

	slash->GetSkillPos()[0] = true;
	slash->GetSkillPos()[1] = true;
	slash->GetSkillPos()[2] = true;
	slash->GetSkillPos()[3] = true;

	slash->SetHitRate(82);
	slash->SetCritRate(6);
	slash->SetAttackRate(0);
	slash->SetSkillAnimName(L"묘지 가르기 Attack");
	slash->SetAnimPath(L"resource\\animations\\monster\\Bone Soldier\\Sprite\\attack\\bone_soldier_slash.atlas");

	slash->SetRealAnimName(L"slash_bone_soldier");
	slash->SetRealAnimPath(L"resource\\animations\\monster\\Bone Soldier\\Sprite\\skeleton_militia.sprite.sword_strike-sword_strike.atlas");

	slash->SetSoundName(L"묘지 가르기 Attack Sound");
	slash->SetSoundPath(L"resource\\sound\\Monsters\\Ruins\\char_share_imp_sword {5ed21b31-fd03-41fd-85e5-727aef54b0c1}.wav");

	curSkillArray[0] = slash;

	attackedAnimName = L"해골 병사 피격";
	attackedAnimPath = L"resource\\animations\\monster\\Bone Soldier\\Sprite\\defend\\bone_soldier_defend.atlas";

	attackedSoundName = L"해골 병사 피격 사운드";
	attackedSoundPath = L"resource\\sound\\Monsters\\Ruins\\char_en_vo_skel_hurt_03 {636dbebf-0995-4d85-994c-da4faab8eb53}.wav";
}

CBoneSoldier::~CBoneSoldier()
{
}
