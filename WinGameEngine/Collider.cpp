#include "stdafx.h"
#include "Collider.h"

#include "Camera.h"
#include "Object.h"

#include "SelectGDI.h"

UINT Collider::g_iNextID = 0;

Collider::Collider()
	: m_pOwner{ nullptr }
	, m_iID{ g_iNextID++ }
	, m_iCol{ 0 }
{
}

Collider::Collider(const Collider& _origin)
	: m_pOwner(nullptr)
	, m_vOffsetPos(_origin.m_vOffsetPos)
	, m_vScale(_origin.m_vScale)
	, m_iID(g_iNextID++)
	, m_iCol{ 0 }
{
}

Collider::~Collider()
{
}

void Collider::finalUpdate()
{
	D3DXVECTOR3 vObjectPos = m_pOwner->GetPos();
	m_vFinalPos = vObjectPos + m_vOffsetPos;
}

void Collider::render(HDC _dc)
{
	PEN_TYPE ePen = PEN_TYPE::GREEN;

	if (m_iCol)
		ePen = PEN_TYPE::RED;

	SelectGDI p(_dc, ePen);
	SelectGDI b(_dc, BRUSH_TYPE::HOLLOW);

	D3DXVECTOR3 vRenderPos = Camera::GetInst()->GetRenderPos(m_vFinalPos);

	Rectangle(_dc
		, (int)(vRenderPos.x - m_vScale.x / 2.f)
		, (int)(vRenderPos.y - m_vScale.y / 2.f)
		, (int)(vRenderPos.x + m_vScale.x / 2.f)
		, (int)(vRenderPos.y + m_vScale.y / 2.f));
}

void Collider::OnCollision(Collider* _pOther)
{
	m_pOwner->OnCollision(_pOther);
}

void Collider::OnCollisionEnter(Collider* _pOther)
{
	m_iCol = true;
	m_pOwner->OnCollisionEnter(_pOther);
}

void Collider::OnCollisionExit(Collider* _pOther)
{
	m_iCol = false;
	m_pOwner->OnCollisionExit(_pOther);
}
