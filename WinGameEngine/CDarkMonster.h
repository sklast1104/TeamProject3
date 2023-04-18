#pragma once

#include "CTurnPlayer.h"

class CSkill;

class CDarkMonster :
	public CTurnPlayer
{

protected:

	// �̸�
	wstring name;
	// ���ҽ� ���
	wstring resPath;
	// ���� Ÿ�� (�� ���ӿ����� 2~3�� ������ �ִ°Ű����� �ϴ� �ϳ��� �մٰ� ����
	wstring monsterType;

	// ���� ü��
	int curHp;
	// �� ü��
	int maxHp;

	// �����
	int shieldRate;
	// ȸ����
	int avoidRate;
	// �ӵ�
	int speed;
	// ������ ����
	int damageLower;
	//������ ����
	int damageUpper;

	// ���׷�
	// ���� ���׷�
	int faintResist;
	// �ߵ� ���׷�
	int toxinResist;
	// ���� ���׷�
	int bleedResist;
	// ��ȭ ���׷�
	int weakResist;
	// �̵� ���׷�
	int moveResist;

	// ��ų �̸��� �ִ� 4������, 1~3���ϼ��� ����
	array<CSkill*, 4> curSkillArray;

	// �ǰ� �ִϸ��̼� �̸�
	wstring attackedAnimName;

	// �ǰ� �ִϸ��̼� ���
	wstring attackedAnimPath;

	// �ǰ� ���� �̸�
	wstring attackedSoundName;

	// �ǰ� ���� ���
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

