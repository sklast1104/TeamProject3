#include "stdafx.h"
#include "Core.h"

#include "Texture.h"

#include "ResMgr.h"
#include "PathMgr.h"
#include "TimeMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "Camera.h"
#include "EventMgr.h"
#include "UIMgr.h"
#include "CollisionMgr.h"


Core::Core()
	: m_hWnd(0)
	, m_ptResolution{}
	, m_hDC(0)
	, m_arrBrush{}
	, m_arrPen{}
{
}

Core::~Core() {

	ReleaseDC(m_hWnd, m_hDC);

	for (size_t i = 0; i < (size_t)BRUSH_TYPE::END; ++i) {
		DeleteObject(m_arrBrush[i]);
	}

	for (size_t i = 0; i < (size_t)PEN_TYPE::END; ++i) {
		DeleteObject(m_arrPen[i]);
	}

}

int Core::init(HWND _hwnd, POINT _ptResolution)
{
	m_hWnd = _hwnd;
	m_ptResolution = _ptResolution;

	// 해상도에 맞게 윈도우 크기 조정
	ChangeWindowSize(Vec2((float)_ptResolution.x, (float)_ptResolution.y), false);

	m_hDC = GetDC(m_hWnd);

	// 이중 버퍼링 용도의 텍스쳐 한장을 만든다.
	m_pMemTex = ResMgr::GetInst()->CreateTexutre(L"BackBuffer", (UINT)m_ptResolution.x, (UINT)m_ptResolution.y);

	// 자주 사용 할 브러쉬 및 펜 생성
	CreateBrushPen();

	// Manager 초기화
	PathMgr::GetInst()->init();
	TimeMgr::GetInst()->init();
	KeyMgr::GetInst()->init();
	Camera::GetInst()->init();
	SceneMgr::GetInst()->init();
	

	// 시드 값 초기화
	// 현재 시간을 시드값으로 사용
	std::srand(std::time(NULL));

	return S_OK;
}

void Core::progress()
{
	// Manager Update
	TimeMgr::GetInst()->update();
	KeyMgr::GetInst()->update();
	Camera::GetInst()->update();

	// 씬 업데이트
	SceneMgr::GetInst()->update();

	// 충돌 처리
	CollisionMgr::GetInst()->update();

	// UI 이벤트 체크
	UIMgr::GetInst()->update();

	// Render
	// Clear
	Clear();

	SceneMgr::GetInst()->render(m_pMemTex->GetDC());
	Camera::GetInst()->render(m_pMemTex->GetDC());

	BitBlt(m_hDC, 0, 0, m_ptResolution.x, m_ptResolution.y,
		m_pMemTex->GetDC(), 0, 0, SRCCOPY);

	TimeMgr::GetInst()->render();

	// 이벤트 지연처리
	EventMgr::GetInst()->update();
}

void Core::CreateBrushPen()
{
	m_arrBrush[(size_t)BRUSH_TYPE::HOLLOW] = (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	m_arrBrush[(size_t)BRUSH_TYPE::RED] = (HBRUSH)CreateSolidBrush(RGB(255, 0, 0));
	m_arrBrush[(size_t)BRUSH_TYPE::ORANGE] = (HBRUSH)CreateSolidBrush(RGB(190, 74, 0));
	m_arrBrush[(size_t)BRUSH_TYPE::BLACK] = (HBRUSH)GetStockObject(BLACK_BRUSH);

	m_arrPen[(size_t)PEN_TYPE::RED] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	m_arrPen[(size_t)PEN_TYPE::BLUE] = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
	m_arrPen[(size_t)PEN_TYPE::GREEN] = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	m_arrPen[(size_t)PEN_TYPE::HOLLOW] = CreatePen(PS_NULL, 1, RGB(255, 0, 0));
}

void Core::Clear()
{
	Rectangle(m_pMemTex->GetDC(), -1, -1, m_ptResolution.x + 1, m_ptResolution.y + 1);
}

void Core::ChangeWindowSize(Vec2 _vResolution, bool _bMenu)
{
	RECT rt = { 0, 0, _vResolution.x, _vResolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, _bMenu);
	SetWindowPos(m_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);

}
