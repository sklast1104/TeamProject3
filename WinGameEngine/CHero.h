#pragma once

#include "CTurnPlayer.h"

class CSkill;

class CHero :
	public CTurnPlayer
{
protected :

	// primary key ������ �ϴ� ����
	static int id ;

	int pKey;

	// �̸�
	wstring name;
	// ����
	wstring job_name;
	// �ʻ�ȭ Ű
	wstring key;
	// �ʻ�ȭ ���
	wstring path;

	// �׷��� ������ �ʻ�ȭ Ű
	wstring grayKey;
	// �׷��� ������ �ʻ�ȭ ���
	wstring grayPath;

	// ���� ü��
	int curHp;
	// �� ü��
	int hp;

	// ���� ��Ʈ����
	UINT curStress;
	// �� ��Ʈ����
	UINT stress;

	// ���߷�
	int hitRate;
	// ȸ����
	int avoidanceRate;
	// ġ����
	int criticalHitRate;
	// �����
	int defenseRate;
	// ������ ����
	int damageLower;
	//������ ����
	int damageUpper;
	// �ӵ�
	int speed;

	// ����
	int level;

	// ����ġ ������ �ִ� ����ġ 8�̶�� ����
	int curExp;

	// ���� ��ų ����Ʈ
	array<CSkill*, 4> curSkillArray;

	// ������ �ִ� ��ų ����Ʈ
	array<CSkill*, 7> skillArray;

	// ���尣 ��� �̸� �� ��� (Enum���� �ϴ°� �������� ����)
	wstring equipKey;
	wstring equipPath;
	int equipLevel;

	wstring armourKey;
	wstring armourPath;
	int armorLevel;

public :

	CHero();
	virtual ~CHero();

	const array<CSkill*, 4> GetCurSkills() { return curSkillArray; }

	const wstring& GetGrayKey() { return grayKey; }
	const wstring& GetGrayPath() { return grayPath; }

	int GetPKey() { return pKey; }

	int GetCurExp() { return curExp; }
	void SetExp(int _exp) { curExp = _exp; }

	void SetEquipLevel(int _equipLevel) { equipLevel = _equipLevel; }
	int GetEquipLevel() { return equipLevel; }

	void SetArmorLevel(int _armorLevel) { armorLevel = _armorLevel; }
	int GetArmorLevel() { return armorLevel; }

	void SetEquipKey(const wstring& _equipKey) { equipKey = _equipKey; }
	const wstring& GetEquipKey() { return equipKey; }

	void SetEquipPath(const wstring& _equipPath) { equipPath = _equipPath; }
	const wstring& GetEquipPath() { return equipPath; }

	void SetArmourKey(const wstring& _armourKey) { armourKey = _armourKey; }
	const wstring& GetArmourKey() { return armourKey; }

	void SetArmourPath(const wstring& _armourPath) { armourPath = _armourPath; }
	const wstring& GetArmourPath() { return armourPath; }

	void SetCurStress(int _curStress) { curStress = _curStress; }
	int GetCurStress() { return curStress; }

	void SetStress(int _stress) { stress = _stress; }
	int GetStress() { return stress; }

	void SetCurHp(int _curHP) { curHp = _curHP; }
	int GetCurHp() { return curHp; }

	void SetName(const wstring& name) {
		this->name = name;
	}

	const wstring& GetName() {
		return name;
	}

	const wstring& GetJobName() { return job_name; }

	void SetKey(const wstring& key) {
		this->key = key;
	}

	const wstring& GetKey() {
		return key;
	}

	void SetPath(const wstring& path) {
		this->path = path;
	}

	const wstring& GetPath() {
		return path;
	}

	void SetHp(int hp) {
		this->hp = hp;
	}

	int GetHp() {
		return hp;
	}

	void SetHitRate(int hitRate) {
		this->hitRate = hitRate;
	}

	int GetHitRate() {
		return hitRate;
	}

	void SetAvoidanceRate(int avoidanceRate) {
		this->avoidanceRate = avoidanceRate;
	}

	int GetAvoidanceRate() {
		return avoidanceRate;
	}

	void SetCriticalHitRate(int criticalHitRate) {
		this->criticalHitRate = criticalHitRate;
	}

	int GetCriticalHitRate() {
		return criticalHitRate;
	}

	void SetDefenseRate(int defenseRate) {
		this->defenseRate = defenseRate;
	}

	int GetDefenseRate() {
		return defenseRate;
	}

	void SetDamageLower(int lowerDamage) {
		this->damageLower = lowerDamage;
	}

	int GetDamageLower() {
		return damageLower;
	}

	void SetDamageUppder(int upperDamage) {
		this->damageUpper = upperDamage;
	}

	int GetDamageUppder() {
		return damageUpper;
	}

	void SetSpeed(int speed) {
		this->speed = speed;
	}

	int GetSpeed() {
		return speed;
	}

	void SetLevel(int level) {
		this->level = level;
	}

	int GetLevel() {
		return level;
	}



};

