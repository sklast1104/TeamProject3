#include "stdafx.h"
#include "CNode.h"

int CNode::pkey = 0;

CNode::CNode()
	: visited{ false }
	, name{ L"" }
	, nodeType{ L"" }
	, isBattleNode{ false }
	, id{-1}
{
	pkey += 1;
	id = pkey;
}

CNode::~CNode()
{
}

void CNode::initSquad()
{
	squadNames.clear();

	squadNames.resize(4);

	squadNames[0] = L"ÇØ°ñ ¼öºñº´";
	squadNames[1] = L"ÇØ°ñ º´»ç";
	squadNames[2] = L"ÇØ°ñ ¼®±Ãº´";
	squadNames[3] = L"ÇØ°ñ º¸ÁÂ°ü";
}

void CNode::InitDoor()
{
	rKey = L"ROOM_TYPE_DOOR";
	rPath = L"resource\\Background\\ruins\\door.png";
}

void CNode::InitStartRoom()
{
	rKey = L"ROOM_TYPE_ROOM0";
	rPath = L"resource\\Background\\ruins\\room0.png";
}

void CNode::InitRandomRoom()
{
	ROOM_TYPE rType = (ROOM_TYPE)(rand() % 9);

	wstring rKey = L"";
	wstring rPath = L"";

	switch (rType) {
	case ROOM_TYPE::ROOM0: {
		rKey = L"ROOM_TYPE_ROOM0";
		rPath = L"resource\\Background\\ruins\\room0.png";
		break;
	}
	case ROOM_TYPE::ROOM1: {
		rKey = L"ROOM_TYPE_ROOM1";
		rPath = L"resource\\Background\\ruins\\room1.png";
		break;
	}
	case ROOM_TYPE::ROOM2: {
		rKey = L"ROOM_TYPE_ROOM2";
		rPath = L"resource\\Background\\ruins\\room2.png";
		break;
	}
	case ROOM_TYPE::ROOM3: {
		rKey = L"ROOM_TYPE_ROOM3";
		rPath = L"resource\\Background\\ruins\\room3.png";
		break;
	}
	case ROOM_TYPE::ROOM4: {
		rKey = L"ROOM_TYPE_ROOM4";
		rPath = L"resource\\Background\\ruins\\room4.png";
		break;
	}
	case ROOM_TYPE::ROOM5: {
		rKey = L"ROOM_TYPE_ROOM5";
		rPath = L"resource\\Background\\ruins\\room5.png";
		break;
	}
	case ROOM_TYPE::ROOM6: {
		rKey = L"ROOM_TYPE_ROOM6";
		rPath = L"resource\\Background\\ruins\\room6.png";
		break;
	}
	case ROOM_TYPE::ROOM7: {
		rKey = L"ROOM_TYPE_ROOM7";
		rPath = L"resource\\Background\\ruins\\room7.png";
		break;
	}
	case ROOM_TYPE::ROOM8: {
		rKey = L"ROOM_TYPE_ROOM8";
		rPath = L"resource\\Background\\ruins\\room8.png";
		break;
	}
	}

	this->rKey = rKey;
	this->rPath = rPath;
}

void CNode::InitRandomPath()
{
	WALL_TYPE rType = (WALL_TYPE)(rand() % 6);

	wstring rKey = L"";
	wstring rPath = L"";

	switch (rType) {
	case WALL_TYPE::WALL0: {
		rKey = L"ROOM_TYPE_WALL0";
		rPath = L"resource\\Background\\ruins\\wall0.png";
		break;
	}
	case WALL_TYPE::WALL1: {
		rKey = L"ROOM_TYPE_WALL1";
		rPath = L"resource\\Background\\ruins\\wall1.png";
		break;
	}
	case WALL_TYPE::WALL2: {
		rKey = L"ROOM_TYPE_WALL2";
		rPath = L"resource\\Background\\ruins\\wall2.png";
		break;
	}
	case WALL_TYPE::WALL3: {
		rKey = L"ROOM_TYPE_WALL3";
		rPath = L"resource\\Background\\ruins\\wall3.png";
		break;
	}
	case WALL_TYPE::WALL4: {
		rKey = L"ROOM_TYPE_WALL4";
		rPath = L"resource\\Background\\ruins\\wall4.png";
		break;
	}
	case WALL_TYPE::WALL5: {
		rKey = L"ROOM_TYPE_WALL5";
		rPath = L"resource\\Background\\ruins\\wall5.png";
		break;
	}
	}

	this->rKey = rKey;
	this->rPath = rPath;
}

void CNode::InitRoomStateByKey(wstring key)
{
	rKey = key;
	rPath = resMap[key];
}
