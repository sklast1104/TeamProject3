#include "stdafx.h"
#include "CollisionMgr.h"

#include "Collider.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Object.h"

CollisionMgr::CollisionMgr()
	: m_arrCheck{}
{

}

CollisionMgr::~CollisionMgr() {

}

void CollisionMgr::CollisionUpdateGroup(GROUP_TYPE _eLeft, GROUP_TYPE _eRight)
{
	Scene* pCurScene = SceneMgr::GetInst()->GetCurScene();

	const vector<Object*>& vecLeft = pCurScene->GetGroupObject(_eLeft);
	const vector<Object*>& vecRight = pCurScene->GetGroupObject(_eRight);

	map<ULONGLONG, bool>::iterator iter;

	for (size_t i = 0; i < vecLeft.size(); ++i) {

		if (nullptr == vecLeft[i]->GetCollider())
			continue;

		for (size_t j = 0; j < vecRight.size(); ++j) {

			if (nullptr == vecRight[j]->GetCollider() || vecLeft[i] == vecRight[j])
				continue;

			Collider* pLeftCol = vecLeft[i]->GetCollider();
			Collider* pRightCol = vecRight[j]->GetCollider();

			COLLIDER_ID ID;
			ID.Left_id = pLeftCol->GetID();
			ID.Right_id = pRightCol->GetID();

			iter = m_mapColInfo.find(ID.ID);

			if (m_mapColInfo.end() == iter) {
				m_mapColInfo.insert(make_pair(ID.ID, false));
				iter = m_mapColInfo.find(ID.ID);
			}

			if (IsCollision(pLeftCol, pRightCol)) {
				// 현재 충돌 중이다.

				if (iter->second) {
					// 이전에도 충돌 중

					if (vecLeft[i]->isDead() || vecRight[j]->isDead()) {

						// 둘중 하나가 삭제 예정이라면 충돌 해제
						pLeftCol->OnCollisionExit(pRightCol);
						pRightCol->OnCollisionExit(pLeftCol);
						iter->second = false;
					}
					else {
						pLeftCol->OnCollision(pRightCol);
						pRightCol->OnCollision(pLeftCol);
					}
				}
				else {
					// 이전에도 충돌하지 않음
					// 둘중 하나가 삭제 예정이라면 충돌하지 않은것으로 취급
					if (!vecLeft[i]->isDead() && !vecRight[j]->isDead()) {

						pLeftCol->OnCollisionEnter(pRightCol);
						pRightCol->OnCollisionEnter(pLeftCol);
						iter->second = true;
					}
				}

			}
			else {
				// 현재 충돌하고 있지 않다
				if (iter->second) {

					// 이전에는 충돌 했었다
					pLeftCol->OnCollisionExit(pRightCol);
					pRightCol->OnCollisionExit(pLeftCol);
					iter->second = false;
				}
			}
		}
	}
}

bool CollisionMgr::IsCollision(Collider* _pLeftCol, Collider* _pRightCol)
{
	D3DXVECTOR3 vLeftPos = _pLeftCol->GetFinalPos();
	D3DXVECTOR3 vLeftScale = _pLeftCol->GetScale();

	D3DXVECTOR3 vRightPos = _pRightCol->GetFinalPos();
	D3DXVECTOR3 vRightScale = _pRightCol->GetScale();

	if (abs(vRightPos.x - vLeftPos.x) <= ((vLeftScale.x + vRightScale.x) / 2.f)
		&& abs(vRightPos.y - vLeftPos.y) <= ((vLeftScale.y + vRightScale.y) / 2.f)
		)
	{
		return true;
	}

	return false;
}

void CollisionMgr::update()
{
	for (UINT iRow = 0; iRow < (UINT)GROUP_TYPE::END; ++iRow) {
		m_arrCheck[iRow];
		for (UINT iCol = iRow; iCol < (UINT)GROUP_TYPE::END; ++iCol) {
			if (m_arrCheck[iRow] & (1 << iCol)) {
				CollisionUpdateGroup((GROUP_TYPE)iRow, (GROUP_TYPE)iCol);
			}
		}
	}
}

void CollisionMgr::CheckGroup(GROUP_TYPE _eLeft, GROUP_TYPE _eRight)
{
	UINT iRow = (UINT)_eLeft;
	UINT iCol = (UINT)_eRight;

	if (iCol < iRow) {
		iRow = (UINT)_eRight;
		iCol = (UINT)_eLeft;
	}

	if (m_arrCheck[iRow] & (1 << iCol)) {
		m_arrCheck[iRow] &= ~(1 << iCol);
	}
	else {
		m_arrCheck[iRow] |= (1 << iCol);
	}
}
