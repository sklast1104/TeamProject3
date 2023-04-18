#include "stdafx.h"
#include "DoorClick.h"
#include "CMap.h"
#include "GameMgr.h"
#include "CRoom.h"

DoorClick::DoorClick(int _roomId)
	: roomId{_roomId}
{
}

void DoorClick::Execute()
{
	CMap* map = GameMgr::GetInst()->GetMap();
	
	CRoom* clickedRoom = (CRoom*)map->FindNodeById(roomId);

	map->SetCurNode(clickedRoom);
	GameMgr::GetInst()->SetCurNodeIdx(roomId);

	ChangeScene(SCENE_TYPE::DROOM);
}
