#include "stdafx.h"
#include "CRoom.h"
#include "CPathNode.h"

int CRoom::CheckDir(int _nextRoomId)
{
	if (nullptr != upNode) {
		CRoom* room = FindRightRoom(upNode);

		if (room->GetId() == _nextRoomId) {
			return 0;
		}
	}

	if (nullptr != downNode) {
		CRoom* room = FindRightRoom(downNode);

		if (room->GetId() == _nextRoomId) {
			return 1;
		}
	}

	if (nullptr != leftNode) {
		CRoom* room = FindRightRoom(leftNode);

		if (room->GetId() == _nextRoomId) {
			return 2;
		}
	}

	if (nullptr != rightNode) {
		CRoom* room = FindRightRoom(rightNode);

		if (room->GetId() == _nextRoomId) {
			return 3;
		}
	}

	assert(nullptr);

	return -1;
}

CRoom* CRoom::FindRightRoom(CPathNode* startPath)
{
	CNode* cur = startPath;

	if (startPath->GetLeftNode()->GetNodeType() == L"CRoom") {

		while (nullptr != cur) {

			// ���� ��尡 ���� ��� �ش� ��带 ��ȯ
			if (cur->GetNodeType() == L"CRoom") {
				return (CRoom*)cur;
			}
			// ���� ��尡 ����̸� ���������� �̵�
			else if (cur->GetNodeType() == L"CPathNode") {
				CPathNode* pathCur = (CPathNode*)cur;

				cur = pathCur->GetRightNode();
			}
		}

	}
	else if (startPath->GetRightNode()->GetNodeType() == L"CRoom") {

		while (nullptr != cur) {

			// ���� ��尡 ���� ��� �ش� ��带 ��ȯ
			if (cur->GetNodeType() == L"CRoom") {
				return (CRoom*)cur;
			}
			// ���� ��尡 ����̸� ���������� �̵�
			else if (cur->GetNodeType() == L"CPathNode") {
				CPathNode* pathCur = (CPathNode*)cur;

				cur = pathCur->GetLeftNode();
			}
		}
	}

	

	// �������� ��� �ƴϸ� ���̹Ƿ� �̺κ��� ������� ����
	assert(nullptr);

	return nullptr;
}



CRoom::CRoom()
	: upNode{ nullptr }
	, downNode{ nullptr }
	, leftNode{ nullptr }
	, rightNode{ nullptr }
{
	nodeType = L"CRoom";
}

CRoom::CRoom(const wstring& rKey, const wstring& rPath)
	: upNode{ nullptr }
	, downNode{ nullptr }
	, leftNode{ nullptr }
	, rightNode{ nullptr }
{
	this->rKey = rKey;
	this->rPath = rPath;

	nodeType = L"CRoom";
}

CRoom::~CRoom()
{

}