#pragma once

class Collider;

union COLLIDER_ID
{
	struct {
		UINT Left_id;
		UINT Right_id;
	};
	ULONGLONG ID;
};

class CollisionMgr
{
private :
	map<ULONGLONG, bool> m_mapColInfo; // 충돌체 간의 이전프레임 충돌 정보
	UINT m_arrCheck[(UINT)GROUP_TYPE::END]; // 그룹간의 충돌 체크 매트릭스

	void CollisionUpdateGroup(GROUP_TYPE _eLeft, GROUP_TYPE _eRight);
	bool IsCollision(Collider* _pLeftCol, Collider* _pRightCol);
public :

	void update();
	void CheckGroup(GROUP_TYPE _eLeft, GROUP_TYPE _eRight);
	void Reset() {
		memset(m_arrCheck, 0, sizeof(UINT) * (UINT)GROUP_TYPE::END);
	}

public :

	SINGLE(CollisionMgr);

};

