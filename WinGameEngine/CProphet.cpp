#include "stdafx.h"
#include "CProphet.h"
#include "CSkill.h"

CProphet::CProphet()
{
	name = L"예언자";
	resPath = L"";
	monsterType = L"불경";

	curHp = 100;
	maxHp = 100;

	avoidRate = 0;
	shieldRate = 15;
	speed = 2;
	speed = 20;

	faintResist = 25;
	toxinResist = 10;
	bleedResist = 200;
	weakResist = 15;
	moveResist = 20;

	damageLower = 6;
	damageUpper = 12;

	// 피격 모션
	attackedAnimName = L"예언자 피격";
	attackedAnimPath = L"resource\\animations\\monster\\prophet\\prophet.sprite.defend-defend.atlas";

	attackedSoundName = L"예언자 피격 사운드";
	attackedSoundPath = L"resource\\sound\\Monsters\\Ruins\\char_en_prophet_mark_voice {a4739b70-a56e-4f5e-b0e1-8a7c5af4d72a}.wav";

	CSkill* prophecy = new CSkill;
	prophecy->SetSkillName(L"예언");
	prophecy->SetSkillPath(L"");

	prophecy->GetSkillRange()[0] = true;
	prophecy->GetSkillRange()[1] = true;
	prophecy->GetSkillRange()[2] = true;
	prophecy->GetSkillRange()[3] = true;

	prophecy->GetSkillPos()[0] = true;
	prophecy->GetSkillPos()[1] = true;
	prophecy->GetSkillPos()[2] = true;
	prophecy->GetSkillPos()[3] = true;

	prophecy->SetHitRate(82);
	prophecy->SetCritRate(6);
	prophecy->SetAttackRate(0);

	// 전투 idle모션은 monDiv에서 하고있음.. 이거도 장기적으로는 이쪽으로 옮겨서 처리하는게 맞긴함

	// 공격 모션
	prophecy->SetSkillAnimName(L"예언 모션 Attack");
	prophecy->SetAnimPath(L"resource\\animations\\monster\\prophet\\prophet.sprite.attack_melee-attack_melee.atlas");

	// 스킬 이펙트
	prophecy->SetRealAnimName(L"예언 모션 스킬 Effect");
	prophecy->SetRealAnimPath(L"resource\\animations\\monster\\prophet\\prophet.sprite.prognosticate-prognosticate.atlas");

	// 소리
	prophecy->SetSoundName(L"예언 모션 Attack Sound");
	prophecy->SetSoundPath(L"resource\\sound\\Monsters\\Ruins\\char_en_prophet_eye {e432387f-b420-422c-9135-5bf114fd65bb}.wav");

	// 피격시 적한테 나타나는 애니메이션
	/*prophecy->SetAttackedName(L"쇠뇌 발사 피격 Effect");
	prophecy->SetAttackedPath(L"resource\\animations\\monster\\Bone Arbalist\\Sprite\\skeleton_arbalist.sprite.crossbow_shot_target-crossbow_shot_target.atlas");*/

	curSkillArray[0] = prophecy;
	
	CSkill* debris = new CSkill;
	debris->SetSkillName(L"폐허의 돌무더기");
	debris->SetSkillPath(L"");

	debris->GetSkillRange()[0] = true;
	debris->GetSkillRange()[1] = true;
	debris->GetSkillRange()[2] = true;
	debris->GetSkillRange()[3] = true;

	debris->GetSkillPos()[0] = true;
	debris->GetSkillPos()[1] = true;
	debris->GetSkillPos()[2] = true;
	debris->GetSkillPos()[3] = true;

	debris->SetHitRate(82);
	debris->SetCritRate(6);
	debris->SetAttackRate(20);

	// 전투 idle모션은 monDiv에서 하고있음.. 이거도 장기적으로는 이쪽으로 옮겨서 처리하는게 맞긴함

	// 공격 모션
	debris->SetSkillAnimName(L"폐허의 돌무더기 모션 Attack");
	debris->SetAnimPath(L"resource\\animations\\monster\\prophet\\prophet.sprite.attack_debris-attack_debris.atlas");

	// 스킬 이펙트
	//debris->SetRealAnimName(L"폐허의 돌무더기 모션 스킬 Effect");
	//debris->SetRealAnimPath(L"resource\\animations\\monster\\prophet\\prophet.sprite.attack_debris-attack_debris.atlas");

	// 소리
	debris->SetSoundName(L"폐허의 돌무더기 Attack Sound");
	debris->SetSoundPath(L"resource\\sound\\Monsters\\Ruins\\char_en_prophet_attack {276d37cc-59ab-4dbe-9a80-593ebe4279ca}.wav");

	// 피격시 적한테 나타나는 애니메이션
	debris->SetAttackedName(L"폐허의 돌무더기 피격 Effect");
	debris->SetAttackedPath(L"resource\\animations\\monster\\prophet\\prophet.sprite.debris-debris.atlas");

	curSkillArray[1] = debris;

	CSkill* eyeOnYou = new CSkill;
	eyeOnYou->SetSkillName(L"주시");
	eyeOnYou->SetSkillPath(L"");

	eyeOnYou->GetSkillRange()[0] = true;
	eyeOnYou->GetSkillRange()[1] = true;
	eyeOnYou->GetSkillRange()[2] = true;
	eyeOnYou->GetSkillRange()[3] = true;

	eyeOnYou->GetSkillPos()[0] = true;
	eyeOnYou->GetSkillPos()[1] = true;
	eyeOnYou->GetSkillPos()[2] = true;
	eyeOnYou->GetSkillPos()[3] = true;

	eyeOnYou->SetHitRate(82);
	eyeOnYou->SetCritRate(6);
	eyeOnYou->SetAttackRate(20);

	// 전투 idle모션은 monDiv에서 하고있음.. 이거도 장기적으로는 이쪽으로 옮겨서 처리하는게 맞긴함

	// 공격 모션
	eyeOnYou->SetSkillAnimName(L"주시 모션 Attack");
	eyeOnYou->SetAnimPath(L"resource\\animations\\monster\\prophet\\prophet.sprite.attack_melee-attack_melee.atlas");

	// 스킬 이펙트
	eyeOnYou->SetRealAnimName(L"주시 모션 스킬 Effect");
	eyeOnYou->SetRealAnimPath(L"resource\\animations\\monster\\prophet\\prophet.sprite.eye_on_you-eye_on_you.atlas");

	// 소리
	eyeOnYou->SetSoundName(L"주시 Attack Sound");
	eyeOnYou->SetSoundPath(L"resource\\sound\\Monsters\\Ruins\\char_en_prophet_eye {e432387f-b420-422c-9135-5bf114fd65bb}.wav");

	// 피격시 적한테 나타나는 애니메이션
	//eyeOnYou->SetAttackedName(L"주시 피격 Effect");
	//eyeOnYou->SetAttackedPath(L"resource\\animations\\monster\\prophet\\prophet.sprite.debris-debris.atlas");

	curSkillArray[2] = eyeOnYou;

	CSkill* gibber = new CSkill;
	gibber->SetSkillName(L"설교");
	gibber->SetSkillPath(L"");

	gibber->GetSkillRange()[0] = true;
	gibber->GetSkillRange()[1] = true;
	gibber->GetSkillRange()[2] = true;
	gibber->GetSkillRange()[3] = true;

	gibber->GetSkillPos()[0] = true;
	gibber->GetSkillPos()[1] = true;
	gibber->GetSkillPos()[2] = true;
	gibber->GetSkillPos()[3] = true;

	gibber->SetHitRate(82);
	gibber->SetCritRate(6);
	gibber->SetAttackRate(20);

	gibber->SetMultiAttack(true);

	// 전투 idle모션은 monDiv에서 하고있음.. 이거도 장기적으로는 이쪽으로 옮겨서 처리하는게 맞긴함

	// 공격 모션
	gibber->SetSkillAnimName(L"설교 모션 Attack");
	gibber->SetAnimPath(L"resource\\animations\\monster\\prophet\\prophet.sprite.attack_gibber-attack_gibber.atlas");

	// 스킬 이펙트
	gibber->SetRealAnimName(L"설교 모션 스킬 Effect");
	gibber->SetRealAnimPath(L"resource\\animations\\monster\\prophet\\prophet.sprite.fulminate-fulminate.atlas");

	// 소리
	gibber->SetSoundName(L"설교 Attack Sound");
	gibber->SetSoundPath(L"resource\\sound\\Monsters\\Ruins\\char_en_prophet_fulminate {52dbf856-76fb-463a-9001-9630b2c66d35}.wav");

	// 피격시 적한테 나타나는 애니메이션
	gibber->SetAttackedName(L"설교 피격 Effect");
	gibber->SetAttackedPath(L"resource\\animations\\monster\\prophet\\prophet.sprite.fulminate_target-fulminate_target.atlas");

	curSkillArray[3] = gibber;
}
