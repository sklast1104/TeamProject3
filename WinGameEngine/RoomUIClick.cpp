#include "stdafx.h"
#include "RoomUIClick.h"
#include "GameMgr.h"
#include "CMap.h"
#include "CNode.h"
#include "CRoom.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Scene_Path.h"
#include "ResMgr.h"
#include "Sound.h"

// 기본적으로 방에 있을때만 이벤트 등록된다는걸 가정한다
// 게임매니저의 map의 현재 노드(방)의 아이디와 자신 노드를 비교한다
// 인접노드일 경우(항상 인접노드만 클릭한다고 가정) 
// 현재 방과 클릭된 자기 방 사이의 path를 계산해서 path씬에 넣어준다
// 그 다음에 Change씬을 Path쪽으로 호출한다

RoomUIClick::RoomUIClick(int _id)
	: id{_id}
{
}

void RoomUIClick::Execute()
{
	ResMgr::GetInst()->LoadSound(L"roomUIClick", L"resource\\sound\\UI\\ui_dungeon\\ui_dun_buttonroom {13156b8a-7348-497a-97d1-2b56edeb80b8}.wav");
	Sound* clickSound = ResMgr::GetInst()->FindSound(L"roomUIClick");

	clickSound->SetVolume(20.f);
	clickSound->Play(false);

	CMap* map = GameMgr::GetInst()->GetMap();
	// 
	CRoom* curNode = (CRoom*)GameMgr::GetInst()->GetMap()->GetCurNode();

	if (curNode->GetId() == id) {
		return;
	}
	else {
		// 원래는 인접방인지 검사가 들어가야 하는게 맞음
		CRoom* clickedRoom = (CRoom*)map->FindNodeById(id);
		
		CRoom* myRoom = (CRoom*)map->FindNodeById(curNode->GetId());

		int _dir = myRoom->CheckDir(id);

		// 디렉션도 같이 전달이 되야함
		vector<CPathNode*> paths = map->GetPathBtwRoom(curNode, clickedRoom, _dir);

		// paths씬에 path 주입 및 SceneChange
		
		Scene_Path* pScene = (Scene_Path*)SceneMgr::GetInst()->GetSceneByName(L"Scene_Path");
		pScene->SetPath(paths);

		ChangeScene(SCENE_TYPE::PATH);

	}
}
