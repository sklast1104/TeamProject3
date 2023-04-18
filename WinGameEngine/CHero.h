#pragma once

#include "CTurnPlayer.h"

class CSkill;

class CHero :
	public CTurnPlayer
{
protected :

	// primary key 역할을 하는 변수
	static int id ;

	int pKey;

	// 이름
	wstring name;
	// 직업
	wstring job_name;
	// 초상화 키
	wstring key;
	// 초상화 경로
	wstring path;

	// 그레이 스케일 초상화 키
	wstring grayKey;
	// 그레이 스케일 초상화 경로
	wstring grayPath;

	// 현재 체력
	int curHp;
	// 총 체력
	int hp;

	// 현재 스트레스
	UINT curStress;
	// 총 스트레스
	UINT stress;

	// 명중률
	int hitRate;
	// 회피율
	int avoidanceRate;
	// 치명율
	int criticalHitRate;
	// 방어율
	int defenseRate;
	// 데미지 하한
	int damageLower;
	//데미지 상한
	int damageUpper;
	// 속도
	int speed;

	// 레벨
	int level;

	// 경험치 무조건 최대 경험치 8이라고 가정
	int curExp;

	// 현재 스킬 리스트
	array<CSkill*, 4> curSkillArray;

	// 가지고 있는 스킬 리스트
	array<CSkill*, 7> skillArray;

	// 대장간 장비 이름 및 경로 (Enum으로 하는게 좋을수도 있음)
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

