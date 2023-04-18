#include "stdafx.h"
#include "CBoneArbalist.h"
#include "CSkill.h"

CBoneArbalist::CBoneArbalist()
{
	name = L"�ذ� �ü�";
	resPath = L"";
	monsterType = L"�Ұ�";

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
	arrowAttack->SetSkillName(L"��� �߻�");
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

	// ���� idle����� monDiv���� �ϰ�����.. �̰ŵ� ��������δ� �������� �Űܼ� ó���ϴ°� �±���

	// ���� ���
	arrowAttack->SetSkillAnimName(L"��� �߻� Attack");
	arrowAttack->SetAnimPath(L"resource\\animations\\monster\\Bone Arbalist\\Sprite\\skeleton_arbalist.sprite.attack_crossbow-attack_crossbow.atlas");

	// ��ų ����Ʈ
	arrowAttack->SetRealAnimName(L"arrow_attack_bone_arbalist");
	arrowAttack->SetRealAnimPath(L"resource\\animations\\monster\\Bone Arbalist\\Sprite\\skeleton_arbalist.sprite.crossbow_shot-crossbow_shot.atlas");

	// �Ҹ�
	arrowAttack->SetSoundName(L"��� �߻� Attack Sound");
	arrowAttack->SetSoundPath(L"resource\\sound\\Monsters\\Ruins\\char_en_sklar_crossbowshot {8c69343c-115e-4297-9ab2-e41f662cce6c}.wav");

	// �ǰݽ� ������ ��Ÿ���� �ִϸ��̼�
	arrowAttack->SetAttackedName(L"��� �߻� �ǰ� Effect");
	arrowAttack->SetAttackedPath(L"resource\\animations\\monster\\Bone Arbalist\\Sprite\\skeleton_arbalist.sprite.crossbow_shot_target-crossbow_shot_target.atlas");

	curSkillArray[0] = arrowAttack;

	// �ǰ� ���
	attackedAnimName = L"�ذ� �ü� �ǰ�";
	attackedAnimPath = L"resource\\animations\\monster\\Bone Arbalist\\Sprite\\skeleton_arbalist.sprite.defend-defend.atlas";

	attackedSoundName = L"�ذ� �ü� �ǰ� ����";
	attackedSoundPath = L"resource\\sound\\Monsters\\Ruins\\char_en_vo_skel_hurt_02 {9c63dd53-67c5-4b71-8150-dcce376b4186}.wav";
}
