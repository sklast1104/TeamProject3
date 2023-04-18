#include "stdafx.h"
#include "CDoctor.h"
#include "CSkill.h"

CDoctor::CDoctor()
{
	key = L"CDoctor Portrait";
	path = L"resource\\heros\\doctor.png";

	grayKey = L"CDoctor Portrait Gray";
	grayPath = L"resource\\heros\\doctor_gray.png";

	name = L"¼Ø³×¸®";
	job_name = L"¿ªº´ ÀÇ»ç";

	equipKey = job_name + L"_weapon";
	equipPath = L"resource\\heros\\doctor\\weapon.png";

	armourKey = job_name + L"_armor";
	armourPath = L"resource\\heros\\doctor\\armour.png";

	curHp = 66;
	hp = 66;
	curExp = 3;

	curStress = 88;
	stress = 200;

	// ¸íÁß º¸Á¤
	hitRate = 0;
	// È¸ÇÇÀ²
	avoidanceRate = 5;
	// Ä¡¸íÀ²
	criticalHitRate = 3;
	// µ¥¹ÌÁö ÇÏÇÑ
	//damageLower = 6;
	damageLower = 6;
	// µ¥¹ÌÁö »óÇÑ
	//damageUpper = 12;
	damageUpper = 10;
	// ¼Óµµ
	speed = 1;
	speed = 8;

	InitSkill();

}

CDoctor::~CDoctor()
{
}

void CDoctor::InitSkill()
{
	CSkill* incision = new CSkill;
	incision->SetSkillName(L"Àý°³ 1");
	incision->SetSkillPath(L"resource\\heros\\doctor\\ab1.png");
	incision->SetGraySkillPath(L"resource\\heros\\doctor\\ab1_gray.png");
	incision->GetSkillPos()[0] = true;
	incision->GetSkillPos()[1] = true;
	incision->GetSkillPos()[2] = true;
	incision->GetSkillPos()[3] = true;

	incision->GetSkillRange()[0] = true;
	incision->GetSkillRange()[1] = true;

	incision->SetHitRate(85);
	incision->SetAttackRate(15);

	// ¸ð¼Ç
	incision->SetSkillAnimName(L"¿ªº´ÀÇ»ç Àý°³ anim");
	incision->SetAnimPath(L"resource\\animations\\hero\\Doctor\\Sprite\\plague_doctor.sprite.attack_dagger-attack_dagger.atlas");

	// ÀÌÆåÆ®
	incision->SetRealAnimName(L"incision_anim_doctor");
	incision->SetRealAnimPath(L"resource\\animations\\hero\\Doctor\\Sprite\\plague_doctor.sprite.incision-incision.atlas");

	// »ç¿îµå
	incision->SetSoundName(L"doctor_incision_attack_sound");
	incision->SetSoundPath(L"resource\\sound\\Heroes\\Plague Doctor\\char_al_plg_incision {dff8b8aa-af86-4f52-8d9f-d348081d5ebe}.wav");

	skillArray[0] = incision;
	curSkillArray[0] = incision;

	CSkill* generade = new CSkill;
	generade->SetSkillName(L"¼¶±¤Åº 1");
	generade->SetSkillPath(L"resource\\heros\\doctor\\ab2.png");
	generade->SetGraySkillPath(L"resource\\heros\\doctor\\ab2_gray.png");
	generade->GetSkillPos()[0] = true;
	generade->GetSkillPos()[1] = true;
	generade->GetSkillPos()[2] = true;
	generade->GetSkillPos()[3] = true;

	generade->GetSkillRange()[0] = true;
	generade->GetSkillRange()[1] = true;
	generade->GetSkillRange()[2] = true;
	generade->GetSkillRange()[3] = true;

	generade->SetHitRate(85);
	generade->SetAttackRate(15);
	generade->SetMultiAttack(true);

	// ¸ð¼Ç
	generade->SetSkillAnimName(L"¿ªº´ÀÇ»ç ¼¶±¤Åº anim");
	generade->SetAnimPath(L"resource\\animations\\hero\\Doctor\\Sprite\\plague_doctor.sprite.attack_grenade-attack_grenade.atlas");

	// ÀÌÆåÆ®
	//generade->SetRealAnimName(L"generade_anim_doctor");
	//generade->SetRealAnimPath(L"resource\\animations\\hero\\Doctor\\Sprite\\plague_doctor.sprite.blinding_gas_target-blinding_gas_target.atlas");

	// ÇÇ°Ý ÀÌÆåÆ®
	generade->SetAttackedName(L"¼¶±¤Åº ÇÇ°Ý effect");
	generade->SetAttackedPath(L"resource\\animations\\hero\\Doctor\\Sprite\\plague_doctor.sprite.blinding_gas_target-blinding_gas_target.atlas");

	// »ç¿îµå
	generade->SetSoundName(L"doctor_generade_attack_sound");
	generade->SetSoundPath(L"resource\\sound\\Heroes\\Plague Doctor\\char_al_plg_blindinggas {d3381d16-9d72-4af2-ac18-8d4926a915b9}.wav");

	skillArray[1] = generade;
	curSkillArray[1] = generade;

	CSkill* burst = new CSkill;
	burst->SetSkillName(L"À¯µ¶±âÃ¼ Æø¹ß 1");
	burst->SetSkillPath(L"resource\\heros\\doctor\\ab3.png");
	burst->SetGraySkillPath(L"resource\\heros\\doctor\\ab3_gray.png");
	burst->GetSkillPos()[0] = false;
	burst->GetSkillPos()[1] = false;
	burst->GetSkillPos()[2] = false;
	burst->GetSkillPos()[3] = false;

	burst->GetSkillRange()[2] = true;
	burst->GetSkillRange()[3] = true;

	burst->SetHitRate(85);
	burst->SetAttackRate(15);

	//// ¸ð¼Ç
	//burst->SetSkillAnimName(L"¿ªº´ÀÇ»ç ¼¶±¤Åº anim");
	//burst->SetAnimPath(L"resource\\animations\\hero\\Doctor\\Sprite\\plague_doctor.sprite.attack_grenade-attack_grenade.atlas");

	//// ÀÌÆåÆ®
	//burst->SetRealAnimName(L"generade_anim_doctor");
	//burst->SetRealAnimPath(L"resource\\animations\\hero\\Doctor\\Sprite\\plague_doctor.sprite.blinding_gas_target-blinding_gas_target.atlas");

	//// »ç¿îµå
	//burst->SetSoundName(L"doctor_generade_attack_sound");
	//burst->SetSoundPath(L"resource\\sound\\Heroes\\Crusader\\char_al_cru_smite {bff358c6-a158-40e9-8018-b64bc1e9c8fd}.wav");

	skillArray[2] = burst;
	curSkillArray[2] = burst;

	CSkill* dShoot = new CSkill;
	dShoot->SetSkillName(L"¿ªº´ ¼ö·ùÅº 1");
	dShoot->SetSkillPath(L"resource\\heros\\doctor\\ab4.png");
	dShoot->SetGraySkillPath(L"resource\\heros\\doctor\\ab4_gray.png");
	dShoot->GetSkillPos()[0] = false;
	dShoot->GetSkillPos()[1] = false;
	dShoot->GetSkillPos()[2] = false;
	dShoot->GetSkillPos()[3] = false;

	dShoot->GetSkillRange()[2] = true;
	dShoot->GetSkillRange()[3] = true;

	dShoot->SetHitRate(85);
	dShoot->SetAttackRate(15);

	//// ¸ð¼Ç
	//burst->SetSkillAnimName(L"¿ªº´ÀÇ»ç ¼¶±¤Åº anim");
	//burst->SetAnimPath(L"resource\\animations\\hero\\Doctor\\Sprite\\plague_doctor.sprite.attack_grenade-attack_grenade.atlas");

	//// ÀÌÆåÆ®
	//burst->SetRealAnimName(L"generade_anim_doctor");
	//burst->SetRealAnimPath(L"resource\\animations\\hero\\Doctor\\Sprite\\plague_doctor.sprite.blinding_gas_target-blinding_gas_target.atlas");

	//// »ç¿îµå
	//burst->SetSoundName(L"doctor_generade_attack_sound");
	//burst->SetSoundPath(L"resource\\sound\\Heroes\\Crusader\\char_al_cru_smite {bff358c6-a158-40e9-8018-b64bc1e9c8fd}.wav");

	skillArray[3] = dShoot;
	curSkillArray[3] = dShoot;
}
