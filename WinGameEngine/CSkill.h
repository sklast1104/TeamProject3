#pragma once

class CSkill
{

private :

	// 스킬 이름 및 리소스 키
	wstring skillName;
	// 스킬 경로
	wstring skillPath;
	// 그레이스케일 스킬 경로
	wstring graySkillPath;

	// 공격 대상 배열 4개의 true, false로 정하자
	array<bool, 4> skillRange;
	// 공격 가능한 포지션
	array<bool, 4> skillPos;

	// 여러명 공격하는 종류의 스킬인지
	bool multiAttack;

	// 명중률
	size_t hitRate;

	// 피해 보정
	int attackRate;

	// 치명타 보정
	float criticalRate;

	// 활성화 상태인지
	bool isAlive;

	// 스킬 애니메이션 이름
	wstring skillAnimName;
	// 스킬 애니메이션 경로
	wstring skillAnimPath;

	// 위에껀 모션이고 아래는 이거는 진짜 애니메이션 이름
	wstring skilRealAnimName;
	wstring skilRealAnimPath;

	wstring soundName;
	wstring soundPath;

	// 스킬을 맞으면 피격당하는 애니메이션 이름 및 경로
	wstring skAttackedAnimName;
	wstring skAttackedAnimPath;

	// 스킬 주인 직업
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

