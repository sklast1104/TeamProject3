#pragma once
class TimeMgr
{
private :
	LARGE_INTEGER m_llCurCount;
	LARGE_INTEGER m_llPrevCount;
	LARGE_INTEGER m_llFrequency;

	double m_dDt;
	double m_dAcc;
	UINT m_iCallCount;
	UINT m_iFPS;

public :

	void init();
	void update();
	void render();

	double GetDT() { return m_dDt; }
	float GetfDT() { return (float)m_dDt; }

public :
	SINGLE(TimeMgr);
};

