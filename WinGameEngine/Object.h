#pragma once

class Collider;
class Animator;

class Object
{
protected:
	wstring m_strName;

	D3DXVECTOR3		m_vPos;
	D3DXVECTOR3		m_vScale;

	// Componenet
	Collider* m_pCollider;
	Animator* m_pAnimator;

	bool m_bAlive;

	void SetDead() { m_bAlive = false; }

public :
	Object();
	Object(const Object& _origin);
	virtual ~Object();

	void SetPos(D3DXVECTOR3 _vPos) { m_vPos = _vPos; }
	void SetScale(D3DXVECTOR3 _vScale) { m_vScale = _vScale; }

	D3DXVECTOR3 GetPos() { return m_vPos; }
	D3DXVECTOR3 GetScale() { return m_vScale; }

	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName; }

	Collider* GetCollider() { return m_pCollider; }
	Animator* GetAnimator() { return m_pAnimator; }

	bool isDead() { return !m_bAlive; }

	void CreateCollider();
	virtual void CreateAnimator();
	void CreateAnimator(Animator* _animator);
	void CreateRigidBody();

	virtual void OnCollision(Collider* _pOther) {}
	virtual void OnCollisionEnter(Collider* _pOther) {}
	virtual void OnCollisionExit(Collider* _pOther) {}

	virtual void update() = 0;
	virtual void finalupdate();
	virtual void render(HDC _dc);

	void ComponentRender(HDC _dc);

	virtual Object* Clone() = 0;

	friend class EventMgr;
};

