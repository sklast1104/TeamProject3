#pragma once

class Object;

struct tEvent
{
	EVENT_TYPE eEven;
	DWORD_PTR IParam;
	DWORD_PTR wParam;
	wstring wstrParam;
};

class EventMgr
{
private :

	vector<tEvent> m_vecEvent;
	vector<Object*> m_vecDead;
	void Execute(const tEvent& _eve);

public :
	void update();
	void AddEvent(const tEvent& _eve) {
		m_vecEvent.push_back(_eve);
	}
public :
	SINGLE(EventMgr)
};

