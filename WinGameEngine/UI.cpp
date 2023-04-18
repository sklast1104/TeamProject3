#include "stdafx.h"
#include "UI.h"

#include "Camera.h"
#include "ViewMgr.h"
#include "SelectGDI.h"

#include "KeyMgr.h"

UI::UI(bool _bCamAff)
	: m_pParentUI{ nullptr }
	, m_bCamAffected{ _bCamAff }
	, m_bMouseOn{ false }
	, m_bLbtnDown{ false }
	, m_canTarget{ true }
	, m_viewAffected{true}
{
}

UI::UI(const UI& _origin)
	: Object(_origin)
	, m_pParentUI{ nullptr }
	, m_bCamAffected{ _origin.m_bCamAffected }
	, m_bMouseOn{ false }
	, m_bLbtnDown{ false }
	, m_canTarget{ true }
	, m_viewAffected{true}
{
	for (size_t i = 0; i < _origin.m_vecChildUI.size(); ++i) {
		AddChild(_origin.m_vecChildUI[i]->Clone());
	}
}

UI::~UI()
{
	Safe_Delete_Vec(m_vecChildUI);
}

void UI::AllCanTarget(bool _canTarget)
{
	m_canTarget = _canTarget;

	for (auto child : m_vecChildUI) {

		if (child->GetName() == L"indicator") continue;

		child->AllCanTarget(_canTarget);
	}
}

void UI::update()
{
	update_child();
}

void UI::finalupdate()
{
	Object::finalupdate();

	m_vFinalPos = GetPos();

	if (GetParent()) {

		D3DXVECTOR3 vParentPos = GetParent()->GetFinalPos();
		m_vFinalPos += vParentPos;
	}

	MouseOnCheck();

	finalupdate_child();
}

void UI::render(HDC _dc)
{
	D3DXVECTOR3 vPos = GetFinalPos();
	D3DXVECTOR3 vScale = GetScale();

	SelectGDI brush(_dc, BRUSH_TYPE::HOLLOW);
	//SelectGDI pen(_dc, PEN_TYPE::RED);
	SelectGDI pen(_dc, PEN_TYPE::HOLLOW);

	if (m_bCamAffected) {
		vPos = Camera::GetInst()->GetRenderPos(vPos);
	}

	if (m_bLbtnDown) {
		SelectGDI select(_dc, PEN_TYPE::GREEN);

		Rectangle(_dc
			, int(vPos.x)
			, int(vPos.y)
			, int(vPos.x + vScale.x)
			, int(vPos.y + vScale.y));
	}
	else {
		Rectangle(_dc
			, int(vPos.x)
			, int(vPos.y)
			, int(vPos.x + vScale.x)
			, int(vPos.y + vScale.y));
	}

	// child ui render
	render_child(_dc);
}

void UI::MouseOn()
{
}

void UI::MouseLbtnUp()
{
}

void UI::MouseLbtnDown()
{
}

void UI::MouseLbtnClicked()
{
}

void UI::update_child()
{
	for (size_t i = 0; i < m_vecChildUI.size(); ++i) {
		m_vecChildUI[i]->update();
	}
}

void UI::finalupdate_child()
{
	for (size_t i = 0; i < m_vecChildUI.size(); ++i) {
		m_vecChildUI[i]->finalupdate();
	}
}

void UI::render_child(HDC _dc)
{
	for (size_t i = 0; i < m_vecChildUI.size(); ++i) {
		m_vecChildUI[i]->render(_dc);
	}
}

void UI::MouseOnCheck()
{
	D3DXVECTOR3 vMousePos = MOUSE_POS;
	D3DXVECTOR3 vScale = GetScale();

	if (m_bCamAffected) {
		vMousePos = Camera::GetInst()->GetRealPos(vMousePos);
	}

	if (m_viewAffected) {
		
	}

	if (m_vFinalPos.x <= vMousePos.x && vMousePos.x <= m_vFinalPos.x + vScale.x
		&& m_vFinalPos.y <= vMousePos.y && vMousePos.y <= m_vFinalPos.y + vScale.y) {
		m_bMouseOn = true;
	}
	else {
		m_bMouseOn = false;
	}
}
