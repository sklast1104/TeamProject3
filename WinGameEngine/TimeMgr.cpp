#include "stdafx.h"
#include "TimeMgr.h"

#include "Core.h"

TimeMgr::TimeMgr() : m_llCurCount{}
, m_llFrequency{}
, m_llPrevCount{}
, m_dDt(0.)
, m_dAcc(0.)
, m_iCallCount(0)
{

}

TimeMgr::~TimeMgr()
{

}

void TimeMgr::init()
{
	QueryPerformanceCounter(&m_llPrevCount);
	QueryPerformanceFrequency(&m_llFrequency);
}

void TimeMgr::update()
{
	QueryPerformanceCounter(&m_llCurCount);

	m_dDt = (double)(m_llCurCount.QuadPart - m_llPrevCount.QuadPart) / (double)(m_llFrequency.QuadPart);

	m_llPrevCount = m_llCurCount;

#ifdef _DEBUG
	if (m_dDt > (1. / 60.))
		m_dDt = (1. / 60.);
#endif
}

void TimeMgr::render()
{
	++m_iCallCount;
	m_dAcc += m_dDt;

	if (m_dAcc >= 1.) {
		m_iFPS = m_iCallCount;
		m_dAcc = 0.;
		m_iCallCount = 0;

		wchar_t szBuffer[255] = {};
		swprintf_s(szBuffer, L"FPS : %d, DT : %f", m_iFPS, m_dDt);
		SetWindowText(Core::GetInst()->GetMainHwnd(), szBuffer);
	}
}
