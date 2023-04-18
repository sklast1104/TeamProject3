#pragma once
#include "CState.h"

class CSquadDiv;
class CMonSquad;
class CTurnPlayer;
class CHeroDiv;
class CMonDiv;
class DamageDiv;

class CCutScene :
	public CState
{

private :

	// ¿µ¿õ ½ºÄõµå
	CSquadDiv* heroSquad;

	// ¸ó½ºÅÍ ½ºÄõµå
	CMonSquad* monSquad;

	CHeroDiv* player;
	//CMonDiv* monster;

	vector<CHeroDiv*> players;
	vector<CMonDiv*> monsters;

	DamageDiv* heroDmgUI;
	vector<DamageDiv*> heroDmgUIs;
	vector<DamageDiv*> monDmgUIs;

	bool _isPlayerAttack;
	bool moveBack;

	virtual void Enter() override;
	virtual void Update() override;
	virtual void Exit() override;

	float elapsedTime;

public :

	CCutScene();
	~CCutScene();

	void SetHeroDmgUI(DamageDiv* ui) { heroDmgUI = ui; }
	void AddHeroDmgUIs(DamageDiv* ui) { heroDmgUIs.push_back(ui); }
	void AddMonDmgUIs(DamageDiv* ui) { monDmgUIs.push_back(ui);}

	void IsPlayerAttack(bool __isPlayerAttack) { _isPlayerAttack = __isPlayerAttack; }
	vector<DamageDiv*>& GetDamageDivs() {
		return monDmgUIs
			;
	}

	vector<DamageDiv*>& GetHeroDamageDivs() { return heroDmgUIs; }
};

