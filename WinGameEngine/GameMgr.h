#pragma once

class CHero;
class CDarkMonster;
class CItem;
class DarkestMachine;
class CMap;

class GameMgr
{
private :

	// 돈
	int moneyCnt;
	// 흉상
	int bustCnt;
	// 초상화
	int portraitCnt;
	// 증서
	int certCnt;
	// 문장
	int bucklerCnt;

	// 현재 영지에서 가지고 있는 히어로 로스터들
	vector<CHero*> curHeros;

	// 현재 스쿼드
	array<CHero*, 4> curSquad;

	// 몬스터 스쿼드도 겜매에서 관리하자
	array< CDarkMonster*, 4> monSquad;

	// 인벤토리 관리
	array<CItem*, 16> curItems;

	// 상태머신
	DarkestMachine* machine;

	// 현재 포커싱 상태인 스쿼드 인덱스
	int focusIndex;

	// 현재 포커싱 상태인 스킬 인덱스
	int sIndex;

	// 현재 포커싱 상태인 몬스터 스쿼드 인덱스
	int monFocusIdx;

	// 카메라 쉐이킹 영향을 안받는 이전에 저장했던 카메라 좌표
	Vec2 rLookAt;

	// 멀티어텍 포커싱용
	vector<int> mulMonIdx;

	// 몬스터 종류별로 다 넣어놈 그냥
	vector<CDarkMonster*> monTypes;

	vector<CDarkMonster*> squad1;
	vector<CDarkMonster*> squad2;
	vector<CDarkMonster*> squad3;

	vector<CDarkMonster*> bossSquad;

	// 던전 맵
	CMap* map;
	int curNodeIdx;

	// 촛불 밝기
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

	// 로스터에서 찾는 함수
	CHero* FindHeroByName(const wstring& _heroName);
	
	// 스쿼드에서 찾는 함수
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
	
	// 몬스터 스쿼드 관련 함수
	const array<CDarkMonster*, 4>& GetMonSquad() { return monSquad; }
	int GetMonSquadNum();
	bool checkMonDead();
	void MakeTurnAlive();

	// 인벤토리 관리 함수
	array<CItem*, 16>& GetInventory() { return curItems; }
	void CreateItem(wstring _key, int _index);
	void MoveInventory(int _from, int _to);
	void SwapInventory(int _from, int _to);
	void RemoveItem(int _index);
	void ClearInventory();

	void CheckCanTurn();

	// 상태머신 관련
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

	// 회복 카메라 좌표 관련
	void SetRLook(Vec2 _vLook) { rLookAt = _vLook; }
	Vec2 GetRLook() { return rLookAt; }

	// 맵 관련 함수
	CMap* GetMap() { return map; }
	void SetCurNodeIdx(int _idx) { curNodeIdx = _idx; }
	int GetCurNodeIdx() { return curNodeIdx; }

	vector<int>& GetMulMonIdx() { return mulMonIdx;}

	void SetBright(int _bright) { bright = _bright; }
	int GetBright() { return bright; }

public :
	SINGLE(GameMgr);
};

