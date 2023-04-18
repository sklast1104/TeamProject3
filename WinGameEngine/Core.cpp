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

	// �ػ󵵿� �°� ������ ũ�� ����
	ChangeWindowSize(Vec2((float)_ptResolution.x, (float)_ptResolution.y), false);

	m_hDC = GetDC(m_hWnd);

	// ���� ���۸� �뵵�� �ؽ��� ������ �����.
	m_pMemTex = ResMgr::GetInst()->CreateTexutre(L"BackBuffer", (UINT)m_ptResolution.x, (UINT)m_ptResolution.y);

	// ���� ��� �� �귯�� �� �� ����
	CreateBrushPen();

	// Manager �ʱ�ȭ
	PathMgr::GetInst()->init();
	TimeMgr::GetInst()->init();
	KeyMgr::GetInst()->init();
	Camera::GetInst()->init();
	SceneMgr::GetInst()->init();
	

	// �õ� �� �ʱ�ȭ
	// ���� �ð��� �õ尪���� ���
	std::srand(std::time(NULL));

	return S_OK;
}

void Core::progress()
{
	// Manager Update
	TimeMgr::GetInst()->update();
	KeyMgr::GetInst()->update();
	Camera::GetInst()->update();

	// �� ������Ʈ
	SceneMgr::GetInst()->update();

	// �浹 ó��
	CollisionMgr::GetInst()->update();

	// UI �̺�Ʈ üũ
	UIMgr::GetInst()->update();

	// Render
	// Clear
	Clear();

	SceneMgr::GetInst()->render(m_pMemTex->GetDC());
	Camera::GetInst()->render(m_pMemTex->GetDC());

	BitBlt(m_hDC, 0, 0, m_ptResolution.x, m_ptResolution.y,
		m_pMemTex->GetDC(), 0, 0, SRCCOPY);

	TimeMgr::GetInst()->render();

	// �̺�Ʈ ����ó��
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
