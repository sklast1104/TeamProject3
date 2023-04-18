#pragma once

class CHero;
class CDarkMonster;
class CItem;
class DarkestMachine;
class CMap;

class GameMgr
{
private :

	// ��
	int moneyCnt;
	// ���
	int bustCnt;
	// �ʻ�ȭ
	int portraitCnt;
	// ����
	int certCnt;
	// ����
	int bucklerCnt;

	// ���� �������� ������ �ִ� ����� �ν��͵�
	vector<CHero*> curHeros;

	// ���� ������
	array<CHero*, 4> curSquad;

	// ���� �����嵵 �׸ſ��� ��������
	array< CDarkMonster*, 4> monSquad;

	// �κ��丮 ����
	array<CItem*, 16> curItems;

	// ���¸ӽ�
	DarkestMachine* machine;

	// ���� ��Ŀ�� ������ ������ �ε���
	int focusIndex;

	// ���� ��Ŀ�� ������ ��ų �ε���
	int sIndex;

	// ���� ��Ŀ�� ������ ���� ������ �ε���
	int monFocusIdx;

	// ī�޶� ����ŷ ������ �ȹ޴� ������ �����ߴ� ī�޶� ��ǥ
	Vec2 rLookAt;

	// ��Ƽ���� ��Ŀ�̿�
	vector<int> mulMonIdx;

	// ���� �������� �� �־�� �׳�
	vector<CDarkMonster*> monTypes;

	vector<CDarkMonster*> squad1;
	vector<CDarkMonster*> squad2;
	vector<CDarkMonster*> squad3;

	vector<CDarkMonster*> bossSquad;

	// ���� ��
	CMap* map;
	int curNodeIdx;

	// �к� ���
	int bright;

public :

	void SetRandomSquad();
	void SetBossSquad();

	const vector<CDarkMonster*>& GetMonTypes() { return monTypes; }

	void init();

	int GetMoney() { return moneyCnt; }
	void SetMoney(int _money) { moneyCnt = _money; }

	int GetBustCnt() { return bustCnt; }
	void SetBust(int _bustCnt) { bustCnt = _bustCnt; }

	int GetPortraitCnt() { return portraitCnt; }
	void SetPortraitCnt(int _portraitCnt) { portraitCnt = _portraitCnt; }

	int GetCertCnt() { return certCnt; }
	void SetCertCnt(int _certCnt) { certCnt = _certCnt; }

	int GetBucklerCnt() { return bucklerCnt; }
	void SetBucklerCnt(int _bucklercnt) { bucklerCnt = _bucklercnt; }

	const vector<CHero*>& GetCurLoster() { return curHeros; }

	// �ν��Ϳ��� ã�� �Լ�
	CHero* FindHeroByName(const wstring& _heroName);
	
	// �����忡�� ã�� �Լ�
	int FindIndexByName(const wstring& _heroName);
	void MakeEmpySlot(int _index) { curSquad[_index] = nullptr; }
	void AddSquad(int _index, const wstring& _heroName);
	bool isSlotEmpty(int _index);
	const array<CHero*, 4>& GetSquad() { return curSquad; }
	void MoveSquadRight();

	void SwapSquad(int _from, int _to);
	void CleanSqaud();
	CHero* GetHeroBySquad(int _index);
	int GetSquadNum();
	void MakeSquadAlive();
	
	// ���� ������ ���� �Լ�
	const array<CDarkMonster*, 4>& GetMonSquad() { return monSquad; }
	int GetMonSquadNum();
	bool checkMonDead();
	void MakeTurnAlive();

	// �κ��丮 ���� �Լ�
	array<CItem*, 16>& GetInventory() { return curItems; }
	void CreateItem(wstring _key, int _index);
	void MoveInventory(int _from, int _to);
	void SwapInventory(int _from, int _to);
	void RemoveItem(int _index);
	void ClearInventory();

	void CheckCanTurn();

	// ���¸ӽ� ����
	DarkestMachine* GetMachine() { return machine; }
	int GetFocusIndex() { return focusIndex;}
	CHero* GetFocusedHero();
	void SetFocusIndex(int _focusIndex) { focusIndex = _focusIndex; }

	void SetMonFocusIdx(int _focusIdx) { monFocusIdx = _focusIdx; }
	int GetMonFocusIdx() { return monFocusIdx; }
	CDarkMonster* GetFocusedMonster();
	CDarkMonster* GetMonsterByIdx(int _idx);

	void SetSIndex(int _sIndex) { sIndex = _sIndex; }
	int GetSIndex() { return sIndex; }

	// ȸ�� ī�޶� ��ǥ ����
	void SetRLook(Vec2 _vLook) { rLookAt = _vLook; }
	Vec2 GetRLook() { return rLookAt; }

	// �� ���� �Լ�
	CMap* GetMap() { return map; }
	void SetCurNodeIdx(int _idx) { curNodeIdx = _idx; }
	int GetCurNodeIdx() { return curNodeIdx; }

	vector<int>& GetMulMonIdx() { return mulMonIdx;}

	void SetBright(int _bright) { bright = _bright; }
	int GetBright() { return bright; }

public :
	SINGLE(GameMgr);
};

