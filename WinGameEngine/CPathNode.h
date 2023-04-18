#pragma once

#include "CNode.h"

enum PATH_DIR {
	LEFT,
	RIGHT,
	TOP,
	BOTTOM
};

class CPathNode :
	public CNode
{
private:

	PATH_DIR dir;
	CNode* leftNode;
	CNode* rightNode;

public:

	CPathNode();
	CPathNode(const wstring& rKey, const wstring& rPath);
	~CPathNode();

	CNode* GetLeftNode() {
		return leftNode;
	}

	void SetLeftNode(CNode* leftNode) {
		this->leftNode = leftNode;
	}

	CNode* GetRightNode() {
		return rightNode;
	}

	void SetRightNode(CNode* rightNode) {
		this->rightNode = rightNode;
	}

	void SetDir(PATH_DIR _dir) { dir = _dir; }
	PATH_DIR GetDir() { return dir; }
};

