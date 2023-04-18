#pragma once

enum class QuestType {
	RECON,	// ����
	BATTLE,	// ����
	BOSS,   // ������
	END,
};

class CQuest
{
private :

	QuestType qType; // ����Ʈ Ÿ��
	wstring qDisc; // ����Ʈ ����

	wstring dPath; // ����Ʈ ���� 
	wstring qLevel; // ����Ʈ ���̵�

	wstring qGoal;  // ��ǥ ����

	wstring fillKey; // Ÿ�Կ� ���� �� Ű
	wstring fillPath; // Ÿ�Կ� ���� �� �н�

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

