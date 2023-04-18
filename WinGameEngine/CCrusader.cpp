#include "stdafx.h"
#include "CCrusader.h"
#include "CSkill.h"
#include "Sound.h"
#include "ResMgr.h"

CCrusader::CCrusader()
{
	key = L"Crusader Portrait";
	path = L"resource\\heros\\crusader.png";

	grayKey = L"Crusader Portrait Gray";
	grayPath = L"resource\\heros\\crusader_gray.png";

	name = L"���̳ε�";
	job_name = L"������";

	equipKey = job_name + L"_weapon";
	equipPath = L"resource\\heros\\crusader\\sword1.png";

	armourKey = job_name + L"_armor";
	armourPath = L"resource\\heros\\crusader\\armour1.png";

	curHp = 66;
	hp = 66;
	curExp = 3;

	curStress = 153;
	stress = 200;

	// ���� ����
	hitRate = 0;
	// ȸ����
	avoidanceRate = 5;
	// ġ����
	criticalHitRate = 3;
	// ������ ����
	//damageLower = 6;
	damageLower = 30;
	// ������ ����
	//damageUpper = 12;
	damageUpper = 42;
	// �ӵ�
	speed = 1;
	speed = 8;

	InitSkill();
}

CCrusader::~CCrusader()
{
	curSkillArray.fill(nullptr);

	for (int i = 0; i < 7; i++) {
		Safe_Delete<CSkill*>(skillArray[i]);
	}

	for (int i = 0; i < 4; i++) {
		Safe_Delete<CSkill*>(curSkillArray[i]);
	}
}

void CCrusader::InitSkill()
{
	// ��Ÿ
	CSkill* powerAttack = new CSkill;
	powerAttack->SetSkillName(L"��Ÿ 1");
	powerAttack->SetSkillPath(L"resource\\heros\\crusader\\ab1.png");
	powerAttack->SetGraySkillPath(L"resource\\heros\\crusader\\ab1_gray.png");
	powerAttack->GetSkillPos()[2] = true;
	powerAttack->GetSkillPos()[3] = true;

	powerAttack->GetSkillRange()[0] = true;
	powerAttack->GetSkillRange()[1] = true;

	powerAttack->SetHitRate(85);
	powerAttack->SetAttackRate(15);

	powerAttack->SetSkillAnimName(L"��Ÿ");
	powerAttack->SetAnimPath(L"resource\\animations\\hero\\Crusader\\Sprite\\crusader_attack_sword\\crusader.sprite.attack_sword-attack_sword.atlas");

	powerAttack->SetRealAnimName(L"powerattack_anim_cru_crusader");
	powerAttack->SetRealAnimPath(L"resource\\animations\\hero\\Crusader\\Sprite\\crusader.sprite.smite-smite.atlas");

	powerAttack->SetSoundName(L"cru_power_attack_sound");
	powerAttack->SetSoundPath(L"resource\\sound\\Heroes\\Crusader\\char_al_cru_smite {bff358c6-a158-40e9-8018-b64bc1e9c8fd}.wav");

	skillArray[0] = powerAttack;

	// ������ ���
	CSkill* denunciation = new CSkill;
	denunciation->SetSkillName(L"������ ��� 1");
	denunciation->SetSkillPath(L"resource\\heros\\crusader\\ab2.png");
	denunciation->SetGraySkillPath(L"resource\\heros\\crusader\\ab2_gray.png");
	denunciation->GetSkillPos()[2] = true;
	denunciation->GetSkillPos()[3] = true;

	denunciation->SetMultiAttack(true);
	denunciation->GetSkillRange()[0] = true;
	denunciation->GetSkillRange()[1] = true;
	denunciation->GetSkillRange()[2] = true;
	denunciation->GetSkillRange()[3] = true;

	denunciation->SetHitRate(85);
	denunciation->SetAttackRate(-40);
	denunciation->SetCritRate(-4);

	denunciation->SetSkillAnimName(L"������ ���");
	denunciation->SetAnimPath(L"resource\\animations\\hero\\Crusader\\Sprite\\crusader_attaack_scroll\\crusader.sprite.attack_scroll-attack_scroll.atlas");

	denunciation->SetRealAnimName(L"jealous_anim_cru_crusader");
	denunciation->SetRealAnimPath(L"resource\\animations\\hero\\Crusader\\Sprite\\jealous_anim\\crusader_jealous_anim.atlas");

	denunciation->SetSoundName(L"denuSound");
	denunciation->SetSoundPath(L"resource\\sound\\Heroes\\Crusader\\char_al_cru_zealousacc {6de675fd-595f-4da1-87d4-ac46c16747b6}.wav");

	skillArray[1] = denunciation;

	// ������ �ϰ�
	CSkill* stunAttack = new CSkill;
	stunAttack->SetSkillName(L"������ �ϰ� 1");
	stunAttack->SetSkillPath(L"resource\\heros\\crusader\\ab3.png");
	stunAttack->SetGraySkillPath(L"resource\\heros\\crusader\\ab3_gray.png");
	//stunAttack->GetSkillPos()[2] = true;
	//stunAttack->GetSkillPos()[3] = true;

	stunAttack->GetSkillRange()[0] = true;
	stunAttack->GetSkillRange()[1] = true;

	stunAttack->SetHitRate(90);
	stunAttack->SetAttackRate(-50);

	stunAttack->SetSkillAnimName(L"������ �ϰ�");
	stunAttack->SetAnimPath(L"resource\\animations\\hero\\Crusader\\Sprite\\crusader_attack_stun\\crusader.sprite.attack_sword-attack_sword.atlas");

	skillArray[2] = stunAttack;

	// �ž��� ����
	CSkill* shield = new CSkill;
	shield->SetSkillName(L"�ž��� ���� 1");
	shield->SetSkillPath(L"resource\\heros\\crusader\\ab4.png");
	shield->SetGraySkillPath(L"resource\\heros\\crusader\\ab4_gray.png");
	shield->GetSkillPos()[2] = true;
	shield->GetSkillPos()[3] = true;

	skillArray[3] = shield;

	// ���� ġ��
	CSkill* battleHeal = new CSkill;
	battleHeal->SetSkillName(L"���� ġ�� 1");
	battleHeal->SetSkillPath(L"resource\\heros\\crusader\\ab5.png");
	battleHeal->SetGraySkillPath(L"resource\\heros\\crusader\\ab5_gray.png");
	battleHeal->GetSkillPos()[0] = true;
	battleHeal->GetSkillPos()[1] = true;
	battleHeal->GetSkillPos()[2] = true;
	battleHeal->GetSkillPos()[3] = true;

	skillArray[4] = battleHeal;

	// �������� ����
	CSkill* chargeAttack = new CSkill;
	chargeAttack->SetSkillName(L"�������� ���� 1");
	chargeAttack->SetSkillPath(L"resource\\heros\\crusader\\ab6.png");
	chargeAttack->SetGraySkillPath(L"resource\\heros\\crusader\\ab6_gray.png");
	chargeAttack->GetSkillPos()[0] = true;
	chargeAttack->GetSkillPos()[1] = true;
	chargeAttack->GetSkillPos()[2] = true;
	chargeAttack->GetSkillPos()[3] = true;

	chargeAttack->GetSkillRange()[1] = true;
	chargeAttack->GetSkillRange()[2] = true;
	chargeAttack->GetSkillRange()[3] = true;

	chargeAttack->SetHitRate(85);
	chargeAttack->SetAttackRate(15);
	chargeAttack->SetCritRate(6.5f);

	chargeAttack->SetSkillName(L"�������� ����");
	chargeAttack->SetAnimPath(L"resource\\animations\\hero\\Crusader\\Sprite\\crusader_attack_charge\\crusader.sprite.attack_charge-attack_charge.atlas");

	chargeAttack->SetRealAnimName(L"holy_lance_cru_crusader");
	chargeAttack->SetRealAnimPath(L"resource\\animations\\hero\\Crusader\\Sprite\\crusader.sprite.holy_lance-holy_lance.atlas");

	chargeAttack->SetSoundName(L"cru_chargeattack_sound");
	chargeAttack->SetSoundPath(L"resource\\sound\\Heroes\\Crusader\\char_al_cry_holylance {d07d14b9-2929-4ff1-9174-be194ba85159}.wav");

	skillArray[5] = chargeAttack;

	// �ݷ��� �Լ�
	CSkill* cheer = new CSkill;
	cheer->SetSkillName(L"�ݷ��� �Լ� 1");
	cheer->SetSkillPath(L"resource\\heros\\crusader\\ab7.png");
	cheer->SetGraySkillPath(L"resource\\heros\\crusader\\ab7_gray.png");
	cheer->GetSkillPos()[0] = true;
	cheer->GetSkillPos()[1] = true;
	cheer->GetSkillPos()[2] = true;
	cheer->GetSkillPos()[3] = true;

	skillArray[6] = cheer;

	curSkillArray[0] = powerAttack;
	curSkillArray[1] = denunciation;
	curSkillArray[2] = stunAttack;
	curSkillArray[3] = chargeAttack;
}
