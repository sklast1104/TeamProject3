#pragma once

enum class QuestType {
	RECON,	// 정찰
	BATTLE,	// 전투
	BOSS,   // 보스전
	END,
};

class CQuest
{
private :

	QuestType qType; // 퀘스트 타입
	wstring qDisc; // 퀘스트 설명

	wstring dPath; // 퀘스트 길이 
	wstring qLevel; // 퀘스트 난이도

	wstring qGoal;  // 목표 설명

	wstring fillKey; // 타입에 따른 필 키
	wstring fillPath; // 타입에 따른 필 패스

public :

	CQuest(QuestType _qType);
	~CQuest() {}

	void SetQType(QuestType _qType) { qType = _qType; }
	const wstring GetQTypeTitle();

	void SetQDisc(const wstring& _qDisc) { qDisc = _qDisc; }
	const wstring GetQDisc() { return qDisc; }

	void SetDPath(const wstring& _dPath) { dPath = _dPath; }
	const wstring GetDPath() { return dPath; }

	void SetQLevel(const wstring& _qLevel) { qLevel = _qLevel; }
	const wstring GetQLevel() { return qLevel; }

	void SetQGoal(const wstring& _qGoal) { qGoal = _qGoal; }
	const wstring GetQGoal() { return qGoal; }

	const wstring GetFillKey() { return fillKey; }
	const wstring GetFillPath() { return fillPath; }
};

