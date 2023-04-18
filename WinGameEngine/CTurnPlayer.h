#pragma once
class CTurnPlayer
{

protected :

	bool canTurn;
	bool isDead;

public :

	void SetCanTurn(bool _isTurn) { canTurn = _isTurn; }
	bool GetCanTurn() { return canTurn; }

	void SetDead() { isDead = true; }
	void SetAlive() { isDead = false; }
	bool IsDead() { return isDead; }

	CTurnPlayer();
	virtual ~CTurnPlayer() {}
};

