#pragma once
#include "DivUI.h"

class CHeroDiv;

class CSquadDiv :
	public DivUI
{
private:

	vector<CHeroDiv*> heros;
	float speed;

public:

	CSquadDiv();
	~CSquadDiv();

	virtual void update() override;

	float GetSpeed() { return speed; }

	void AddHero(CHeroDiv* _hero) {
		heros.push_back(_hero);
	}

	int GetSquadNum() { return heros.size(); }
	CHeroDiv* GetHeroDivByIdx(int _idx) { return heros[_idx]; }

	
	void PlayHeroIdleAnim();
	void PlayHeroWalkAnim();
	void PlayHeroCombatAnim();

	// ������ ���� �ε����� �������� Ű�� �������� �� ���� �Լ�
	// ���� �ε����� heroDiv ������ �ƴ϶� ���ӸŴ��� ��������� ���� �ε���
	void EnableOverlay(int _realIndex);

	// ��� �������� ���� �� ����
	void DisableAllOverlay();
		
	// ���� ���õ� �ε����� ��Ŀ�� �����ϰ��ϰ� �������� ���� Ÿ���� �ȵǰ� ���� �� �������̵�ó��
	void EnableFocus(int _realIndex);

	// ���� ���õ� �ε��� ���� ��ų Ȱ��ȭ �� ��Ȱ��ȭ
	void EnableSkill(int _realIndex);

	// ������ �ε��� ���� �Ǿ����� y����
	void MoveToFrontMonDiv(int _idx);

	// ������ �ε��� ���� �ǵڷ� ����
	void MoveToBackRender(int _idx);


	// ��� �ڽ�DivUI���� ����
	void EnableAllDivChildUI(bool _isEnable);

	void EnableAttackedOverlay(int _idx);
	void EnableAllAttackedOverlay();

	void EnableAllCanTarget();
	void EnableAllOnYou(bool _isEnable);

	CLONE(CSquadDiv);
	
};
