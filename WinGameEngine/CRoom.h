#pragma once

#include "CNode.h"

class CPathNode;

enum class Dir {

	UP,
	DOWN,
	LEFT,
	RIGHT
};

class CRoom :
	public CNode
{
private:

	// ���� ��带 �������� RoomScene�� ���Ë����� �����¿�� �ʱ�ȭ��
	Dir dir;

	CPathNode* upNode;
	CPathNode* downNode;
	CPathNode* leftNode;
	CPathNode* rightNode;

public:

	int CheckDir(int _nextRoomId);

	CRoom* FindRightRoom(CPathNode* startPath);

	virtual bool isRoom() const override { return true; }

	void SetDir(Dir _dir) { dir = _dir; }
	Dir GetDir() { return dir; }

	CPathNode* GetUpNode() {
		return upNode;
	}

	void SetUpNode(CPathNode* upNode) {
		this->upNode = upNode;
	}

	CPathNode* GetDownNode() {
		return downNode;
	}

	void SetDownNode(CPathNode* downNode) {
		this->downNode = downNode;
	}

	CPathNode* GetLeftNode() {
		return leftNode;
	}

	void SetLeftNode(CPathNode* leftNode) {
		this->leftNode = leftNode;
	}

	CPathNode* GetRightNode() {
		return rightNode;
	}

	void SetRightNode(CPathNode* rightNode) {
		this->rightNode = rightNode;
	}

	CRoom();
	CRoom(const wstring& rKey, const wstring& rPath);
	virtual ~CRoom();

};

