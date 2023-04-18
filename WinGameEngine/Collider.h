#pragma once

class Object;

class Collider
{
private :

	static UINT g_iNextID;

	Object* m_pOwner; // collider�� �����ϰ� �ִ� ������Ʈ
	D3DXVECTOR3 m_vOffsetPos; // ������Ʈ�κ��� ������� ��ġ
	D3DXVECTOR3  m_vFinalPos; // final update���� �� �����Ӹ��� ���
	D3DXVECTOR3 m_vScale;     // �浹ü�� ũ��

	UINT m_iID;       // �浹ü ������ ID ��
	UINT m_iCol;

public :

	void SetOffsetPos(D3DXVECTOR3 _vPos) { m_vOffsetPos = _vPos; }
	void SetScale(D3DXVECTOR3 _vScale) { m_vScale = _vScale; }

	D3DXVECTOR3 GetOffsetPos() { return m_vOffsetPos; }
	D3DXVECTOR3 GetScale() { return m_vScale; }

	D3DXVECTOR3 GetFinalPos() { return m_vFinalPos; }

	Object* GetObj() { return m_pOwner; }

	UINT GetID() { return m_iID; }

	Collider();
	Collider(const Collider& _origin);
	~Collider();

	void finalUpdate();
	void render(HDC _dc);

	void OnCollision(Collider* _pOther);
	void OnCollisionEnter(Collider* _pOther);
	void OnCollisionExit(Collider* _pOther);

	Collider& operator = (Collider& _origin) = delete;

	friend class Object;
};

