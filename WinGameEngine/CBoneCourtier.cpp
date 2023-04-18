#include "stdafx.h"
#include "CBoneCourtier.h"
#include "CSkill.h"

CBoneCourtier::CBoneCourtier()
{
	name = L"�ذ� ���°�";
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

	CSkill* colarAttack = new CSkill;
	colarAttack->SetSkillName(L"��Ȥ�� ����");
	colarAttack->SetSkillPath(L"");

	colarAttack->GetSkillRange()[0] = true;
	colarAttack->GetSkillRange()[1] = true;
	colarAttack->GetSkillRange()[2] = true;
	colarAttack->GetSkillRange()[3] = true;

	colarAttack->GetSkillPos()[0] = true;
	colarAttack->GetSkillPos()[1] = true;
	colarAttack->GetSkillPos()[2] = true;
	colarAttack->GetSkillPos()[3] = true;

	colarAttack->SetHitRate(82);
	colarAttack->SetCritRate(6);
	colarAttack->SetAttackRate(0);

	// ���� idle����� monDiv���� �ϰ�����.. �̰ŵ� ��������δ� �������� �Űܼ� ó���ϴ°� �±���

	// ���� ���
	colarAttack->SetSkillAnimName(L"��Ȥ�� ���� Attack");
	colarAttack->SetAnimPath(L"resource\\animations\\monster\\Bone Courtier\\Sprite\\skeleton_courtier.sprite.attack_goblet-attack_goblet.atlas");

	// ��ų ����Ʈ
	colarAttack->SetRealAnimName(L"colar_attack_bone_courtier");
	colarAttack->SetRealAnimPath(L"resource\\animations\\monster\\Bone Courtier\\Sprite\\skeleton_courtier.sprite.tempting_goblet-tempting_goblet.atlas");

	// �Ҹ�
	colarAttack->SetSoundName(L"��Ȥ�� ���� Attack Sound");
	colarAttack->SetSoundPath(L"resource\\sound\\Monsters\\Ruins\\char_en_sklco_temptinggob {59fb2421-655d-4d06-a8c8-5af02a70e744}.wav");

	curSkillArray[0] = colarAttack;

	// �ǰ� ���
	attackedAnimName = L"�ذ� ������ �ǰ�";
	attackedAnimPath = L"resource\\animations\\monster\\Bone Courtier\\Sprite\\skeleton_courtier.sprite.defend-defend.atlas";

	attackedSoundName = L"�ذ� ������ �ǰ� ����";
	attackedSoundPath = L"resource\\sound\\Monsters\\Ruins\\char_en_vo_skel_hurt_02 {9c63dd53-67c5-4b71-8150-dcce376b4186}.wav";
}
