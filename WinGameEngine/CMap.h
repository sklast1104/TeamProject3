#pragma once

class CNode;
class CRoom;
class CPathNode;

class CMap
{

private :

	CNode* startRoom;
	CNode* curNode;

	vector<CNode*> nodeLists;

	vector<CNode*> rightNodes;
	vector<CNode*> botNodes;

public :

	CMap();
	~CMap();

	void ReleaseDFSNode(CNode* node);

	CNode* getStartRoom() {
		return startRoom;
	}

	void SetStartRoom(CNode* node) {
		startRoom = node;
	}

	CNode* GetCurNode() { return curNode; }
	void SetCurNode(CNode* node) { curNode = node; }

	void DefineDefaultMap();

	void BFS();

	// ���� ���� �׸��� ���� �湮 �������� ��� false
	void MakeVisitedFalse();

	CNode* FindNodeById(int _id);

	CRoom* findRightRoom(CPathNode* startPath);
	CRoom* findLeftRoom(CPathNode* startPath);

	vector<CPathNode*> GetLeftPaths(CRoom* startRoom);
	vector<CPathNode*> GetRightPaths(CRoom* startRoom);
	vector<CPathNode*> GetUpPaths(CRoom* startRoom);
	vector<CPathNode*> GetBotPaths(CRoom* startRoom);

	vector<CPathNode*> GetRightPaths(CNode* startRoom);

	// �� Room ������ ��� ��带 ��ȯ
	vector<CPathNode*> GetPathBtwRoom(CRoom* leftRoom, CRoom* rightRoom, int dir);

	void MakeLeftPath(CRoom* right, CRoom* left);
	void MakeRightPath(CRoom* left, CRoom* right);
	void MakeUpPath(CRoom* down, CRoom* up);
	void MakeDownPath(CRoom* up, CRoom* down);
};

