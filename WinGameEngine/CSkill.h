#pragma once

class CSkill
{

private :

	// ��ų �̸� �� ���ҽ� Ű
	wstring skillName;
	// ��ų ���
	wstring skillPath;
	// �׷��̽����� ��ų ���
	wstring graySkillPath;

	// ���� ��� �迭 4���� true, false�� ������
	array<bool, 4> skillRange;
	// ���� ������ ������
	array<bool, 4> skillPos;

	// ������ �����ϴ� ������ ��ų����
	bool multiAttack;

	// ���߷�
	size_t hitRate;

	// ���� ����
	int attackRate;

	// ġ��Ÿ ����
	float criticalRate;

	// Ȱ��ȭ ��������
	bool isAlive;

	// ��ų �ִϸ��̼� �̸�
	wstring skillAnimName;
	// ��ų �ִϸ��̼� ���
	wstring skillAnimPath;

	// ������ ����̰� �Ʒ��� �̰Ŵ� ��¥ �ִϸ��̼� �̸�
	wstring skilRealAnimName;
	wstring skilRealAnimPath;

	wstring soundName;
	wstring soundPath;

	// ��ų�� ������ �ǰݴ��ϴ� �ִϸ��̼� �̸� �� ���
	wstring skAttackedAnimName;
	wstring skAttackedAnimPath;

	// ��ų ���� ����
	wstring ownerJobName;

public :

	CSkill();
	~CSkill();

	const wstring& GetOwnerJobName() { return ownerJobName; }
	void SetOwnerJobName(const wstring& _jobName) { ownerJobName = _jobName; }

	const wstring& GetAttackedName() { return skAttackedAnimName; }
	void SetAttackedName(const wstring& _name) { skAttackedAnimName = _name; }

	const wstring& GetAttackedPath() { return skAttackedAnimPath; }
	void SetAttackedPath(const wstring& _path) { skAttackedAnimPath = _path; }

	const wstring& GetSoundName() { return soundName; }
	void SetSoundName(const wstring& _name) { soundName = _name; }

	const wstring& GetSoundPath() { return soundPath; }
	void SetSoundPath(const wstring& _path) { soundPath = _path; }

	const wstring& GetRealAnimName() { return skilRealAnimName; }
	void SetRealAnimName(const wstring& _name) { skilRealAnimName = _name; }

	const wstring& GetRealAnimPath() { return skilRealAnimPath; }
	void SetRealAnimPath(const wstring& _path) { skilRealAnimPath = _path; }

	const wstring& GetSkilAnimName() { return skillAnimName; }
	void SetSkillAnimName(const wstring& _skilName) { skillAnimName = _skilName; }

	const wstring& GetAnimPath() { return skillAnimPath; }
	void SetAnimPath(const wstring& _animPath) { skillAnimPath = _animPath; }

	const wstring& GetSkillName() { return skillName; }
	void SetSkillName(const wstring& _skillName) { skillName = _skillName; }

	const wstring& GetSkillPath() { return skillPath; }
	void SetSkillPath(const wstring& _skillPath) { skillPath = _skillPath; }

	const wstring& GetGraySkillPath() { return graySkillPath; }
	void SetGraySkillPath(const wstring& _graySkillPath) { graySkillPath = _graySkillPath; }

	array<bool, 4>& GetSkillRange() { return skillRange; }
	array<bool, 4>& GetSkillPos() { return skillPos; }

	void SetMultiAttack(bool _isMulti) { multiAttack = _isMulti; }
	bool GetMulti() { return multiAttack; }

	size_t GetHitRate() { return hitRate; }
	void SetHitRate(size_t _hitRate) { hitRate = _hitRate; }

	int GetAttackRate() { return attackRate; }
	void SetAttackRate(int _attackRate) { attackRate = _attackRate; }

	float GetCritRate() { return criticalRate; }
	void SetCritRate(float _criticalRate) { criticalRate = _criticalRate; }

	void SetSkillAlive(bool _isAlive) { isAlive = _isAlive; }
	bool IsAlive() { return isAlive; }
};

