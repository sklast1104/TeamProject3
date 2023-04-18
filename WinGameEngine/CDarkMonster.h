#pragma once

#include "CTurnPlayer.h"

class CSkill;

class CDarkMonster :
	public CTurnPlayer
{

protected:

	// 이름
	wstring name;
	// 리소스 경로
	wstring resPath;
	// 몬스터 타입 (인 게임에서는 2~3개 가지룻도 있는거같은데 일단 하나만 잇다고 가정
	wstring monsterType;

	// 현재 체력
	int curHp;
	// 총 체력
	int maxHp;

	// 방어율
	int shieldRate;
	// 회피율
	int avoidRate;
	// 속도
	int speed;
	// 데미지 하한
	int damageLower;
	//데미지 상한
	int damageUpper;

	// 저항력
	// 기절 저항력
	int faintResist;
	// 중독 저항력
	int toxinResist;
	// 출혈 저항력
	int bleedResist;
	// 약화 저항력
	int weakResist;
	// 이동 저항력
	int moveResist;

	// 스킬 이름은 최대 4개까지, 1~3개일수도 있음
	array<CSkill*, 4> curSkillArray;

	// 피격 애니메이션 이름
	wstring attackedAnimName;

	// 피격 애니메이션 경로
	wstring attackedAnimPath;

	// 피격 사운드 이름
	wstring attackedSoundName;

	// 피격 사운드 경로
	wstring attackedSoundPath;

public :

	CDarkMonster();
	virtual ~CDarkMonster();

	const wstring& GetASName() { return attackedSoundName; }
	void SetASName(const wstring& _sName) { attackedSoundName = _sName; }

	const wstring& GetASPath() { return attackedSoundPath; }
	void SetASPath(const wstring& _sPath) { attackedSoundPath = _sPath; }

	const wstring& GetAttackedAnimName() { return attackedAnimName; }
	void SetAttackedAnimName(const wstring& _attackedAnimName) { attackedAnimName = _attackedAnimName; }

	const wstring& GetAttackedAnimPath() { return attackedAnimPath; }
	void SetAttackedAnimPath(const wstring& _attackedAnimPath) { attackedAnimPath = _attackedAnimPath; }

	const array<CSkill*, 4> GetCurSkills() { return curSkillArray; }

	const wstring& GetName() { return name; }
	void SetName(const wstring& _name) { name = _name; }

	const wstring& GetPath() { return resPath; }
	void SetPath(const wstring& _path) { resPath = _path; }

	const wstring& GetMonType() { return monsterType; }
	void SetMonType(const wstring& _monType) { monsterType = _monType; }

	int GetCurHp() { return curHp; }
	void SetCurHp(int _hp) { curHp = _hp; }
	int GetMaxHp() { return maxHp; }
	void SetMaxHp(int _maxHp) { maxHp = _maxHp; }

	int GetShieldRate() { return shieldRate; }
	void SetShieldRate(int _shieldRate) { shieldRate = _shieldRate; }
	int GetAvoidRate() { return avoidRate; }
	void SetAvoidRate(int _avoidRate) { avoidRate = _avoidRate; }
	int GetSpeed() { return speed; }
	void SetSpeed(int _speed) { speed = _speed; }

	int GetFaintResist() { return faintResist; }
	void SetFaintResist(int _faintResist) { faintResist = _faintResist; }
	int GetToxinResist() { return toxinResist; }
	void SetToxinResist(int _toxinResist) { toxinResist = _toxinResist; }
	int GetBleedResist() { return bleedResist; }
	void SetBleedResist(int _bleedResist) { bleedResist = _bleedResist; }
	int GetWeakResist() { return weakResist; }
	void SetWeakResist(int _weakResist) { weakResist = _weakResist; }
	int GetMoveResist() { return moveResist; }
	void SetMoveResist(int _moveResist) { moveResist = _moveResist; }

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
};

