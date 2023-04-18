#include "stdafx.h"
#include "CBoneDefender.h"
#include "CSkill.h"

CBoneDefender::CBoneDefender()
{
	name = L"해골 방어병";
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

	CSkill* weightDeath = new CSkill;
	weightDeath->SetSkillName(L"죽음의 무게");
	weightDeath->SetSkillPath(L"");

	weightDeath->GetSkillRange()[0] = true;
	weightDeath->GetSkillRange()[1] = true;
	weightDeath->GetSkillRange()[2] = true;
	weightDeath->GetSkillRange()[3] = true;

	weightDeath->GetSkillPos()[0] = true;
	weightDeath->GetSkillPos()[1] = true;
	weightDeath->GetSkillPos()[2] = true;
	weightDeath->GetSkillPos()[3] = true;

	weightDeath->SetHitRate(82);
	weightDeath->SetCritRate(6);
	weightDeath->SetAttackRate(0);

	// 전투 idle모션은 monDiv에서 하고있음.. 이거도 장기적으로는 이쪽으로 옮겨서 처리하는게 맞긴함

	// 공격 모션
	weightDeath->SetSkillAnimName(L"죽음의 무게 Attack");
	weightDeath->SetAnimPath(L"resource\\animations\\monster\\Bone Defender\\Sprite\\skeleton_defender.sprite.attack_shield-attack_shield.atlas");

	// 스킬 이펙트
	weightDeath->SetRealAnimName(L"weight_of_death_bone_defender");
	weightDeath->SetRealAnimPath(L"resource\\animations\\monster\\Bone Defender\\Sprite\\skeleton_defender.sprite.shield_bash-shield_bash.atlas");

	// 소리
	weightDeath->SetSoundName(L"죽음의 무게 Attack Sound");
	weightDeath->SetSoundPath(L"resource\\sound\\Monsters\\Ruins\\char_en_sklde_axestrike {c7ec19a5-54b7-46e8-bf27-801b46ef04da}.wav");

	curSkillArray[0] = weightDeath;

	// 피격 모션
	attackedAnimName = L"해골 방어병 피격";
	attackedAnimPath = L"resource\\animations\\monster\\Bone Defender\\Sprite\\skeleton_defender.sprite.defend-defend.atlas";

	attackedSoundName = L"해골 방어벽 피격 사운드";
	attackedSoundPath = L"resource\\sound\\Monsters\\Ruins\\char_en_vo_skel_hurt_02 {9c63dd53-67c5-4b71-8150-dcce376b4186}.wav";
}

CBoneDefender::~CBoneDefender()
{
}
