#include "stdafx.h"
#include "Object.h"

#include "Animator.h"
#include "Collider.h"

#include "Camera.h"
#include "ViewMgr.h"

Object::Object()
	: m_vPos{}
	, m_vScale{}
	, m_pCollider(nullptr)
	, m_pAnimator{ nullptr }
	, m_bAlive{ true }
{
}

Object::Object(const Object& _origin)
	: m_strName{ _origin.m_strName }
	, m_vPos{ _origin.m_vPos }
	, m_vScale{ _origin.m_vScale }
	, m_pCollider{ nullptr }
	, m_pAnimator{ nullptr }
	, m_bAlive{ true }
{
	if (_origin.m_pCollider) {
		m_pCollider = new Collider(*_origin.m_pCollider);
		m_pCollider->m_pOwner = this;
	}

	if (_origin.m_pAnimator) {
		m_pAnimator = new Animator(*_origin.m_pAnimator);
		m_pAnimator->m_pOwner = this;
	}
}

Object::~Object()
{
	if (nullptr != m_pCollider) {
		delete m_pCollider;
		m_pCollider = nullptr;
	}


	if (nullptr != m_pAnimator) {
		delete m_pAnimator;
		m_pAnimator = nullptr;
	}
}

void Object::CreateCollider()
{
	m_pCollider = new Collider;
	m_pCollider->m_pOwner = this;
}

void Object::CreateAnimator()
{
	m_pAnimator = new Animator;
	m_pAnimator->m_pOwner = this;
}

void Object::CreateAnimator(Animator* _animator)
{
	m_pAnimator = _animator;
	m_pAnimator->m_pOwner = this;
}

void Object::CreateRigidBody()
{
}

void Object::finalupdate()
{
	if (m_pCollider) {
		m_pCollider->finalUpdate();
	}

	if (m_pAnimator)
		m_pAnimator->finalupdate();
}

void Object::render(HDC _dc)
{
	D3DXVECTOR3 vRenderPos = Camera::GetInst()->GetRenderPos(m_vPos);
	D3DXVECTOR3 vScale = GetScale();

	Rectangle(_dc, (int)(vRenderPos.x - vScale.x / 2.f), (int)(vRenderPos.y - vScale.y / 2.f),
		(int)(vRenderPos.x + vScale.x / 2.f), (int)(vRenderPos.y + vScale.y / 2.f));

	ComponentRender(_dc);
}

void Object::ComponentRender(HDC _dc)
{
	if (nullptr != m_pCollider) {
		m_pCollider->render(_dc);
	}

	if (nullptr != m_pAnimator) {
		m_pAnimator->render(_dc);
	}
}
