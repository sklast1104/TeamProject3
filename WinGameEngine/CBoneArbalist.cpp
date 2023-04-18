#include "stdafx.h"
#include "CBoneArbalist.h"
#include "CSkill.h"

CBoneArbalist::CBoneArbalist()
{
	name = L"해골 궁수";
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

	CSkill* arrowAttack = new CSkill;
	arrowAttack->SetSkillName(L"쇠뇌 발사");
	arrowAttack->SetSkillPath(L"");

	arrowAttack->GetSkillRange()[0] = true;
	arrowAttack->GetSkillRange()[1] = true;
	arrowAttack->GetSkillRange()[2] = true;
	arrowAttack->GetSkillRange()[3] = true;

	arrowAttack->GetSkillPos()[0] = true;
	arrowAttack->GetSkillPos()[1] = true;
	arrowAttack->GetSkillPos()[2] = true;
	arrowAttack->GetSkillPos()[3] = true;

	arrowAttack->SetHitRate(82);
	arrowAttack->SetCritRate(6);
	arrowAttack->SetAttackRate(0);

	// 전투 idle모션은 monDiv에서 하고있음.. 이거도 장기적으로는 이쪽으로 옮겨서 처리하는게 맞긴함

	// 공격 모션
	arrowAttack->SetSkillAnimName(L"쇠뇌 발사 Attack");
	arrowAttack->SetAnimPath(L"resource\\animations\\monster\\Bone Arbalist\\Sprite\\skeleton_arbalist.sprite.attack_crossbow-attack_crossbow.atlas");

	// 스킬 이펙트
	arrowAttack->SetRealAnimName(L"arrow_attack_bone_arbalist");
	arrowAttack->SetRealAnimPath(L"resource\\animations\\monster\\Bone Arbalist\\Sprite\\skeleton_arbalist.sprite.crossbow_shot-crossbow_shot.atlas");

	// 소리
	arrowAttack->SetSoundName(L"쇠뇌 발사 Attack Sound");
	arrowAttack->SetSoundPath(L"resource\\sound\\Monsters\\Ruins\\char_en_sklar_crossbowshot {8c69343c-115e-4297-9ab2-e41f662cce6c}.wav");

	// 피격시 적한테 나타나는 애니메이션
	arrowAttack->SetAttackedName(L"쇠뇌 발사 피격 Effect");
	arrowAttack->SetAttackedPath(L"resource\\animations\\monster\\Bone Arbalist\\Sprite\\skeleton_arbalist.sprite.crossbow_shot_target-crossbow_shot_target.atlas");

	curSkillArray[0] = arrowAttack;

	// 피격 모션
	attackedAnimName = L"해골 궁수 피격";
	attackedAnimPath = L"resource\\animations\\monster\\Bone Arbalist\\Sprite\\skeleton_arbalist.sprite.defend-defend.atlas";

	attackedSoundName = L"해골 궁수 피격 사운드";
	attackedSoundPath = L"resource\\sound\\Monsters\\Ruins\\char_en_vo_skel_hurt_02 {9c63dd53-67c5-4b71-8150-dcce376b4186}.wav";
}
