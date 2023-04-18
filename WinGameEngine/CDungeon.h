#pragma once

class CQuest;

class CDungeon
{
private :

	wstring name;
	vector<CQuest*> questVec;

public :

	CDungeon(const wstring& _name);
	~CDungeon();

	const vector<CQuest*>& GetQuests() { return questVec; }

	void SetName(const wstring& _name) { name = _name; }
	const wstring& GetName() { return name; }

	void InitRuin();
	void InitCourt();
	void InitBay();
};

