#pragma once
#include "DivUI.h"

class CMonDiv;

class CMonSquad :
	public DivUI
{
private :

	vector<CMonDiv*> monDivs;
	vector<CMonDiv*> deadDivs;

public :

	CMonSquad();
	~CMonSquad();

	virtual void update() override;

	void AddMonster(CMonDiv* _monDiv) { monDivs.push_back(_monDiv); }

	void PlayIdleCombatAnim();

	void MoveToFrontMonDiv(int _idx);

	void MoveToBackRender(int _idx);

	int GetSquadNum() { return monDivs.size(); }
	CMonDiv* GetMonDivByIdx(int _idx) { return monDivs[_idx]; }

	const vector<CMonDiv*>& GetMonDivs() { return monDivs; }

	// 모든 자식DivUI렌드 끄기
	void EnableAllDivChildUI(bool _isEnable);

	// 선택한 리얼 인덱스를 오버레이 키고 나머지는 다 끄는 함수
	// 리얼 인덱스는 heroDiv 순서가 아니라 게임매니저 스쿼드상의 실제 인덱스
	void EnableOverlay(int _realIndex);

	// 모든 오버레이 전부 다 끄기
	void DisableAllOverlay();

	// id기반으로 정렬
	void SortChildUI();

	void EraseDiv(int _idx);

	// 몬스터들의 canTarget 전부 켜주기
	void makeTargetMons(bool _enable);

	void makeVisibleMons(bool _enable);

	void restorePos();

	void updateHpBar();

	CLONE(CMonSquad);
};

