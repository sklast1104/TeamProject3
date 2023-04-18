#include "stdafx.h"
#include "CHighwayMan.h"
#include "CSkill.h"

CHighwayMan::CHighwayMan()
{
	key = L"Highwayman Portrait";
	path = L"resource\\heros\\highwayman.png";

	grayKey = L"Highwayman Portrait Gray";
	grayPath = L"resource\\heros\\highwayman_gray.png";

	name = L"�𽺸���";
	job_name = L"��󰭵�";

	equipKey = job_name + L"_weapon";
	equipPath = L"resource\\heros\\highwayman\\weapon0.png";

	armourKey = job_name + L"_armor";
	armourPath = L"resource\\heros\\highwayman\\armour0.png";

	curHp = 23;
	curHp = 47;
	hp = 23;
	hp = 47;

	curStress = 60;
	stress = 200;
	curExp = 5;

	// ���� ����
	hitRate = 0;
	// ȸ����
	avoidanceRate = 10;
	// ġ����
	criticalHitRate = 5;
	// ������ ����
	damageLower = 5;
	//damageLower = 25;
	// ������ ����
	damageUpper = 10;
	//damageUpper = 30;
	// �ӵ�
	speed = 5;
	speed = 10;

	InitSkill();
}

CHighwayMan::~CHighwayMan()
{
	curSkillArray.fill(nullptr);

	for (int i = 0; i < 7; i++) {
		Safe_Delete<CSkill*>(skillArray[i]);
	}

	for (int i = 0; i < 4; i++) {
		Safe_Delete<CSkill*>(curSkillArray[i]);
	}
}

void CHighwayMan::InitSkill()
{
	// ����� Į��
	CSkill* evilBlade = new CSkill;
	evilBlade->SetSkillName(L"����� Į�� 1");
	evilBlade->SetSkillPath(L"resource\\heros\\highwayman\\ab0.png");
	evilBlade->SetGraySkillPath(L"resource\\heros\\highwayman\\ab0_gray.png");
	evilBlade->GetSkillPos()[1] = true;
	evilBlade->GetSkillPos()[2] = true;
	evilBlade->GetSkillPos()[3] = true;

	evilBlade->GetSkillRange()[0] = true;
	evilBlade->GetSkillRange()[1] = true;

	evilBlade->SetHitRate(85);
	evilBlade->SetAttackRate(15);
	evilBlade->SetCritRate(5.f);

	evilBlade->SetSkillAnimName(L"����� Į��");
	evilBlade->SetAnimPath(L"resource\\animations\\hero\\Highwayman\\Sprite\\highway_man_attack_slice\\highwayman.sprite.attack_slice-attack_slice.atlas");

	evilBlade->SetRealAnimName(L"evil_blade_high_highwayman");
	evilBlade->SetRealAnimPath(L"resource\\animations\\hero\\Highwayman\\Sprite\\highwayman.sprite.wicked_slice-wicked_slice.atlas");

	evilBlade->SetSoundName(L"evil_blade_high_sound");
	evilBlade->SetSoundPath(L"resource\\sound\\Heroes\\Highwayman\\char_al_hwy_wickedslice {81b03b1f-667e-4de7-a36e-f785322ca7e6}.wav");

	skillArray[0] = evilBlade;

	// ���� ��� 1
	CSkill* pistolShot = new CSkill;
	pistolShot->SetSkillName(L"���� ��� 1");
	pistolShot->SetSkillPath(L"resource\\heros\\highwayman\\ab1.png");
	pistolShot->SetGraySkillPath(L"resource\\heros\\highwayman\\ab1_gray.png");
	pistolShot->GetSkillPos()[0] = true;
	pistolShot->GetSkillPos()[1] = true;
	pistolShot->GetSkillPos()[2] = true;

	pistolShot->SetMultiAttack(false);
	pistolShot->GetSkillRange()[0] = true;
	pistolShot->GetSkillRange()[1] = true;
	pistolShot->GetSkillRange()[2] = true;
	pistolShot->GetSkillRange()[3] = true;

	pistolShot->SetHitRate(85);
	pistolShot->SetAttackRate(300);
	pistolShot->SetCritRate(7.5f);

	pistolShot->SetSkillAnimName(L"���� ���");
	pistolShot->SetAnimPath(L"resource\\animations\\hero\\Highwayman\\Sprite\\highway_man_attack_pistol\\highwayman.sprite.attack_pistol-attack_pistol.atlas");
	pistolShot->SetOwnerJobName(L"��󰭵�");

	pistolShot->SetRealAnimName(L"pistol_shot_high_highwayman");
	pistolShot->SetRealAnimPath(L"resource\\animations\\hero\\Highwayman\\Sprite\\highwayman.sprite.pistol_shot-pistol_shot.atlas");

	pistolShot->SetAttackedName(L"���� �ǰ� effect");
	pistolShot->SetAttackedPath(L"resource\\animations\\hero\\Highwayman\\Sprite\\highwayman.sprite.pistol_shot_target-pistol_shot_target.atlas");

	pistolShot->SetSoundName(L"pistol_shot_high_sound");
	pistolShot->SetSoundPath(L"resource\\sound\\Heroes\\Highwayman\\char_al_hwy_grapeshot {bd02d1df-eeae-4378-828a-eafc9677513b}.wav");

	skillArray[1] = pistolShot;

	// ���Ÿ� ���
	CSkill* zeroShot = new CSkill;
	zeroShot->SetSkillName(L"���Ÿ� ��� 1");
	zeroShot->SetSkillPath(L"resource\\heros\\highwayman\\ab2.png");
	zeroShot->SetGraySkillPath(L"resource\\heros\\highwayman\\ab2_gray.png");
	zeroShot->GetSkillPos()[3] = true;

	zeroShot->GetSkillRange()[0] = true;

	zeroShot->SetHitRate(95);
	zeroShot->SetAttackRate(100);
	zeroShot->SetCritRate(5);

	skillArray[2] = zeroShot;

	// ����ź �߻�
	CSkill* grapeShot = new CSkill;
	grapeShot->SetSkillName(L"����ź �߻� 1");
	grapeShot->SetSkillPath(L"resource\\heros\\highwayman\\ab3.png");
	grapeShot->SetGraySkillPath(L"resource\\heros\\highwayman\\ab3_gray.png");
	grapeShot->GetSkillPos()[1] = true;
	grapeShot->GetSkillPos()[2] = true;

	grapeShot->SetMultiAttack(true);
	grapeShot->GetSkillRange()[0] = true;
	grapeShot->GetSkillRange()[1] = true;
	grapeShot->GetSkillRange()[2] = true;

	grapeShot->SetHitRate(75);
	grapeShot->SetAttackRate(-50);
	grapeShot->SetCritRate(-9.f);

	grapeShot->SetSkillAnimName(L"����ź �߻�");
	grapeShot->SetAnimPath(L"resource\\animations\\hero\\Highwayman\\Sprite\\highway_man_attack_pistol\\highwayman.sprite.attack_pistol-attack_pistol.atlas");

	grapeShot->SetRealAnimName(L"grape_shot_high_highwayman");
	grapeShot->SetRealAnimPath(L"resource\\animations\\hero\\Highwayman\\Sprite\\highwayman.sprite.grape_shot_blast-grape_shot_blast.atlas");

	grapeShot->SetAttackedName(L"����ź �߻� �ǰ� effect");
	grapeShot->SetAttackedPath(L"resource\\animations\\hero\\Highwayman\\Sprite\\highwayman.sprite.grape_shot_blast_target-grape_shot_blast_target.atlas");
	grapeShot->SetOwnerJobName(L"��󰭵�");

	grapeShot->SetSoundName(L"grape_shot_high_sound");
	grapeShot->SetSoundPath(L"resource\\sound\\Heroes\\Highwayman\\char_al_hwy_grapeshot {bd02d1df-eeae-4378-828a-eafc9677513b}.wav");


	skillArray[3] = grapeShot;

	// ����ź
	CSkill* traceShot = new CSkill;
	traceShot->SetSkillName(L"����ź 1");
	traceShot->SetSkillPath(L"resource\\heros\\highwayman\\ab4.png");
	traceShot->SetGraySkillPath(L"resource\\heros\\highwayman\\ab4_gray.png");
	traceShot->GetSkillPos()[0] = true;
	traceShot->GetSkillPos()[1] = true;
	traceShot->GetSkillPos()[2] = true;
	traceShot->GetSkillPos()[3] = true;

	traceShot->SetMultiAttack(true);
	traceShot->GetSkillRange()[1] = true;
	traceShot->GetSkillRange()[2] = true;
	traceShot->GetSkillRange()[3] = true;

	traceShot->SetHitRate(75);
	traceShot->SetAttackRate(-50);
	traceShot->SetCritRate(-9.f);

	skillArray[4] = traceShot;

	// �������� ����
	CSkill* advanceAttack = new CSkill;
	advanceAttack->SetSkillName(L"�������� ���� 1");
	advanceAttack->SetSkillPath(L"resource\\heros\\highwayman\\ab5.png");
	advanceAttack->SetGraySkillPath(L"resource\\heros\\highwayman\\ab5_gray.png");
	advanceAttack->GetSkillPos()[0] = true;
	advanceAttack->GetSkillPos()[1] = true;
	advanceAttack->GetSkillPos()[2] = true;

	advanceAttack->GetSkillRange()[0] = true;
	advanceAttack->GetSkillRange()[1] = true;
	advanceAttack->GetSkillRange()[2] = true;

	advanceAttack->SetHitRate(90);
	advanceAttack->SetAttackRate(-20);
	advanceAttack->SetCritRate(5.f);

	advanceAttack->SetSkillAnimName(L"�������� ����");
	advanceAttack->SetAnimPath(L"resource\\animations\\hero\\Highwayman\\Sprite\\highway_man_attack_lunge\\highwayman.sprite.attack_lunge-attack_lunge.atlas");

	advanceAttack->SetRealAnimName(L"advanced_attack_high_highwayman");
	advanceAttack->SetRealAnimPath(L"resource\\animations\\hero\\Highwayman\\Sprite\\highwayman.sprite.duelist_advance-duelist_advance.atlas");

	advanceAttack->SetSoundName(L"duelist_advance_high_sound");
	advanceAttack->SetSoundPath(L"resource\\sound\\Heroes\\Highwayman\\char_al_hwy_duelistadvance {8ef282ac-edf7-43df-99e5-d9f8279b5583}.wav");

	skillArray[5] = advanceAttack;

	// ����
	CSkill* incision = new CSkill;
	incision->SetSkillName(L"���� 1");
	incision->SetSkillPath(L"resource\\heros\\highwayman\\ab6.png");
	incision->SetGraySkillPath(L"resource\\heros\\highwayman\\ab6_gray.png");

	incision->GetSkillPos()[1] = true;
	incision->GetSkillPos()[2] = true;
	incision->GetSkillPos()[3] = true;

	incision->GetSkillRange()[0] = true;
	incision->GetSkillRange()[1] = true;

	incision->SetHitRate(95);
	incision->SetAttackRate(-15);

	skillArray[6] = incision;

	curSkillArray[0] = evilBlade;
	curSkillArray[1] = pistolShot;
	curSkillArray[2] = grapeShot;
	curSkillArray[3] = advanceAttack;
}