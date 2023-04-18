#include "stdafx.h"
#include "Scene_Test.h"

#include "CPlayer.h"
#include "CMonster.h"
#include "Core.h"
#include "DivUI.h"

#include "KeyMgr.h"
#include "Camera.h"
#include "CollisionMgr.h"
#include "Collider.h"

Scene_Test::Scene_Test()
{
}

Scene_Test::~Scene_Test()
{
}

void Scene_Test::update()
{
	Scene::update();
}

void Scene_Test::Enter()
{
	//ViewMgr::GetInst()->SetZoomRatio(2.f);

	Vec2 vResolution = Core::GetInst()->GetResolution();

	CPlayer* myRect = new CPlayer;
	myRect->SetScale(D3DXVECTOR3(100.f, 100.f, 0.f));
	myRect->SetPos(D3DXVECTOR3(960.f, 540.f, 0.f));
	myRect->CreateCollider();
	myRect->GetCollider()->SetScale(myRect->GetScale());

	AddObject(myRect, GROUP_TYPE::PLAYER);

	CMonster* obstacle = new CMonster;
	obstacle->SetScale(D3DXVECTOR3(100.f, 100.f, 0.f));
	obstacle->SetPos(D3DXVECTOR3(560.f, 540.f, 0.f));
	obstacle->CreateCollider();
	obstacle->GetCollider()->SetScale(obstacle->GetScale());
	obstacle->SetTarget(myRect);

	AddObject(obstacle, GROUP_TYPE::MONSTER);

	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);
}

void Scene_Test::Exit()
{
	CollisionMgr::GetInst()->Reset();
	Scene::DeleteAll();
}


