#include "stdafx.h"
#include "CProphet.h"
#include "CSkill.h"

CProphet::CProphet()
{
	name = L"������";
	resPath = L"";
	monsterType = L"�Ұ�";

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

	// �ǰ� ���
	attackedAnimName = L"������ �ǰ�";
	attackedAnimPath = L"resource\\animations\\monster\\prophet\\prophet.sprite.defend-defend.atlas";

	attackedSoundName = L"������ �ǰ� ����";
	attackedSoundPath = L"resource\\sound\\Monsters\\Ruins\\char_en_prophet_mark_voice {a4739b70-a56e-4f5e-b0e1-8a7c5af4d72a}.wav";

	CSkill* prophecy = new CSkill;
	prophecy->SetSkillName(L"����");
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

	// ���� idle����� monDiv���� �ϰ�����.. �̰ŵ� ��������δ� �������� �Űܼ� ó���ϴ°� �±���

	// ���� ���
	prophecy->SetSkillAnimName(L"���� ��� Attack");
	prophecy->SetAnimPath(L"resource\\animations\\monster\\prophet\\prophet.sprite.attack_melee-attack_melee.atlas");

	// ��ų ����Ʈ
	prophecy->SetRealAnimName(L"���� ��� ��ų Effect");
	prophecy->SetRealAnimPath(L"resource\\animations\\monster\\prophet\\prophet.sprite.prognosticate-prognosticate.atlas");

	// �Ҹ�
	prophecy->SetSoundName(L"���� ��� Attack Sound");
	prophecy->SetSoundPath(L"resource\\sound\\Monsters\\Ruins\\char_en_prophet_eye {e432387f-b420-422c-9135-5bf114fd65bb}.wav");

	// �ǰݽ� ������ ��Ÿ���� �ִϸ��̼�
	/*prophecy->SetAttackedName(L"��� �߻� �ǰ� Effect");
	prophecy->SetAttackedPath(L"resource\\animations\\monster\\Bone Arbalist\\Sprite\\skeleton_arbalist.sprite.crossbow_shot_target-crossbow_shot_target.atlas");*/

	curSkillArray[0] = prophecy;
	
	CSkill* debris = new CSkill;
	debris->SetSkillName(L"������ ��������");
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

	// ���� idle����� monDiv���� �ϰ�����.. �̰ŵ� ��������δ� �������� �Űܼ� ó���ϴ°� �±���

	// ���� ���
	debris->SetSkillAnimName(L"������ �������� ��� Attack");
	debris->SetAnimPath(L"resource\\animations\\monster\\prophet\\prophet.sprite.attack_debris-attack_debris.atlas");

	// ��ų ����Ʈ
	//debris->SetRealAnimName(L"������ �������� ��� ��ų Effect");
	//debris->SetRealAnimPath(L"resource\\animations\\monster\\prophet\\prophet.sprite.attack_debris-attack_debris.atlas");

	// �Ҹ�
	debris->SetSoundName(L"������ �������� Attack Sound");
	debris->SetSoundPath(L"resource\\sound\\Monsters\\Ruins\\char_en_prophet_attack {276d37cc-59ab-4dbe-9a80-593ebe4279ca}.wav");

	// �ǰݽ� ������ ��Ÿ���� �ִϸ��̼�
	debris->SetAttackedName(L"������ �������� �ǰ� Effect");
	debris->SetAttackedPath(L"resource\\animations\\monster\\prophet\\prophet.sprite.debris-debris.atlas");

	curSkillArray[1] = debris;

	CSkill* eyeOnYou = new CSkill;
	eyeOnYou->SetSkillName(L"�ֽ�");
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

	// ���� idle����� monDiv���� �ϰ�����.. �̰ŵ� ��������δ� �������� �Űܼ� ó���ϴ°� �±���

	// ���� ���
	eyeOnYou->SetSkillAnimName(L"�ֽ� ��� Attack");
	eyeOnYou->SetAnimPath(L"resource\\animations\\monster\\prophet\\prophet.sprite.attack_melee-attack_melee.atlas");

	// ��ų ����Ʈ
	eyeOnYou->SetRealAnimName(L"�ֽ� ��� ��ų Effect");
	eyeOnYou->SetRealAnimPath(L"resource\\animations\\monster\\prophet\\prophet.sprite.eye_on_you-eye_on_you.atlas");

	// �Ҹ�
	eyeOnYou->SetSoundName(L"�ֽ� Attack Sound");
	eyeOnYou->SetSoundPath(L"resource\\sound\\Monsters\\Ruins\\char_en_prophet_eye {e432387f-b420-422c-9135-5bf114fd65bb}.wav");

	// �ǰݽ� ������ ��Ÿ���� �ִϸ��̼�
	//eyeOnYou->SetAttackedName(L"�ֽ� �ǰ� Effect");
	//eyeOnYou->SetAttackedPath(L"resource\\animations\\monster\\prophet\\prophet.sprite.debris-debris.atlas");

	curSkillArray[2] = eyeOnYou;

	CSkill* gibber = new CSkill;
	gibber->SetSkillName(L"����");
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

	// ���� idle����� monDiv���� �ϰ�����.. �̰ŵ� ��������δ� �������� �Űܼ� ó���ϴ°� �±���

	// ���� ���
	gibber->SetSkillAnimName(L"���� ��� Attack");
	gibber->SetAnimPath(L"resource\\animations\\monster\\prophet\\prophet.sprite.attack_gibber-attack_gibber.atlas");

	// ��ų ����Ʈ
	gibber->SetRealAnimName(L"���� ��� ��ų Effect");
	gibber->SetRealAnimPath(L"resource\\animations\\monster\\prophet\\prophet.sprite.fulminate-fulminate.atlas");

	// �Ҹ�
	gibber->SetSoundName(L"���� Attack Sound");
	gibber->SetSoundPath(L"resource\\sound\\Monsters\\Ruins\\char_en_prophet_fulminate {52dbf856-76fb-463a-9001-9630b2c66d35}.wav");

	// �ǰݽ� ������ ��Ÿ���� �ִϸ��̼�
	gibber->SetAttackedName(L"���� �ǰ� Effect");
	gibber->SetAttackedPath(L"resource\\animations\\monster\\prophet\\prophet.sprite.fulminate_target-fulminate_target.atlas");

	curSkillArray[3] = gibber;
}
