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

	// ��� �ڽ�DivUI���� ����
	void EnableAllDivChildUI(bool _isEnable);

	// ������ ���� �ε����� �������� Ű�� �������� �� ���� �Լ�
	// ���� �ε����� heroDiv ������ �ƴ϶� ���ӸŴ��� ��������� ���� �ε���
	void EnableOverlay(int _realIndex);

	// ��� �������� ���� �� ����
	void DisableAllOverlay();

	// id������� ����
	void SortChildUI();

	void EraseDiv(int _idx);

	// ���͵��� canTarget ���� ���ֱ�
	void makeTargetMons(bool _enable);

	void makeVisibleMons(bool _enable);

	void restorePos();

	void updateHpBar();

	CLONE(CMonSquad);
};

