#pragma once
#include "CItem.h"

class CInvItem :
	public CItem
{
private :

	int cost;

public :

	CInvItem(const wstring& name);
	virtual ~CInvItem();

	int GetCost() { return cost; }
	void SetCost(int cost) { this->cost = cost; }
};

