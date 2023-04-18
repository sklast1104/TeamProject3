#include "stdafx.h"
#include "CMap.h"

#include "CRoom.h"
#include "CPathNode.h"

CMap::CMap()
	: startRoom{ nullptr }
	, curNode{ nullptr }
{
}

CMap::~CMap()
{
	ReleaseDFSNode(startRoom);
}

void CMap::ReleaseDFSNode(CNode* node)
{
	for (int i = 0; i < nodeLists.size(); i++) {
		delete nodeLists[i];
	}
}

void CMap::DefineDefaultMap()
{
	if (nullptr != startRoom || nullptr != curNode) return;

	CRoom* root = new CRoom();
	root->SetName(L"StartRoom");
	root->InitStartRoom();
	//root->MakeBattleNode();
	nodeLists.push_back(root);

	CRoom* rRoom = new CRoom();
	rRoom->InitRandomRoom();
	nodeLists.push_back(rRoom);

	MakeRightPath(root, rRoom);

	CRoom* botRoom = new CRoom();
	botRoom->InitRandomRoom();
	nodeLists.push_back(botRoom);

	MakeDownPath(root, botRoom);

	CRoom* bbRoom = new CRoom();
	bbRoom->InitRandomRoom();
	nodeLists.push_back(bbRoom);

	MakeDownPath(botRoom, bbRoom);

	CRoom* brRoom = new CRoom();
	brRoom->InitRandomRoom();
	nodeLists.push_back(brRoom);

	MakeDownPath(rRoom, brRoom);
	MakeRightPath(botRoom, brRoom);

	CRoom* brbRoom = new CRoom();
	brbRoom->InitRandomRoom();
	nodeLists.push_back(brbRoom);

	MakeDownPath(brRoom, brbRoom);

	CRoom* rrRoom = new CRoom();
	rrRoom->InitRandomRoom();
	nodeLists.push_back(rrRoom);

	MakeRightPath(brRoom, rrRoom);

	CRoom* rrrRoom = new CRoom();
	rrrRoom->InitRandomRoom();
	nodeLists.push_back(rrrRoom);

	MakeRightPath(rrRoom, rrrRoom);

	CRoom* rruRoom = new CRoom();
	rruRoom->InitRandomRoom();
	nodeLists.push_back(rruRoom);

	MakeUpPath(rrRoom, rruRoom);

	CRoom* rrurRoom = new CRoom();
	rrurRoom->InitRandomRoom();
	nodeLists.push_back(rrurRoom);

	MakeRightPath(rruRoom, rrurRoom);

	CRoom* rrbRoom = new CRoom();
	rrbRoom->InitRandomRoom();
	nodeLists.push_back(rrbRoom);

	MakeDownPath(rrRoom, rrbRoom);
	
	CRoom* rrbrRoom = new CRoom();
	rrbrRoom->InitRandomRoom();
	nodeLists.push_back(rrbrRoom);

	MakeRightPath(rrbRoom, rrbrRoom);

	CRoom* rrbrrRoom = new CRoom();
	rrbrrRoom->InitRandomRoom();
	rrbrrRoom->MakeBattleNode();
	nodeLists.push_back(rrbrrRoom);

	MakeRightPath(rrbrRoom, rrbrrRoom);


	//CRoom* upRoom = new CRoom();
	//upRoom->InitRandomRoom();
	//nodeLists.push_back(upRoom);

	//MakeUpPath(root, upRoom);

	//CRoom* urRoom = new CRoom();
	//urRoom->InitRandomRoom();
	//nodeLists.push_back(urRoom);

	//MakeUpPath(rRoom, urRoom);
	//MakeRightPath(upRoom, urRoom);

	//CRoom* leftRoom = new CRoom();
	//leftRoom->InitRandomRoom();
	//nodeLists.push_back(leftRoom);

	//MakeLeftPath(root, leftRoom);

	rightNodes[2]->MakeBattleNode();
	//botNodes[1]->MakeBattleNode();
	botNodes[9]->MakeBattleNode();

	startRoom = root;
	curNode = startRoom;

	// 위쪽

}

void CMap::BFS()
{
	deque<CNode*> q;
	q.push_back(startRoom);

	while (!q.empty()) {

		CNode* node = q.front();
		curNode = node;
		q.pop_front();

		if (node->GetVisited()) continue;

		node->SetVisited(true);

		if (CRoom* roomNode = dynamic_cast<CRoom*>(node)) {
			if (roomNode->GetUpNode() != nullptr) {
				q.push_back(roomNode->GetUpNode());
			}
			if (roomNode->GetDownNode() != nullptr) {
				q.push_back(roomNode->GetDownNode());
			}
			if (roomNode->GetLeftNode() != nullptr) {
				q.push_back(roomNode->GetLeftNode());
			}
			if (roomNode->GetRightNode() != nullptr) {
				q.push_back(roomNode->GetRightNode());
			}
		}
		else if (CPathNode* pathNode = dynamic_cast<CPathNode*>(node)) {
			if (pathNode->GetLeftNode() != nullptr) {
				q.push_back(pathNode->GetLeftNode());
			}
			if (pathNode->GetRightNode() != nullptr) {
				q.push_back(pathNode->GetRightNode());
			}
		}

	}

}

void CMap::MakeVisitedFalse()
{
	for (int i = 0; i < nodeLists.size(); i++) {
		nodeLists[i]->SetVisited(false);
	}
}

CNode* CMap::FindNodeById(int _id)
{
	for (int i = 0; i < nodeLists.size(); i++) {

		if (nodeLists[i]->GetId() == _id)
			return nodeLists[i];
	}

	return nullptr;
}

CRoom* CMap::findRightRoom(CPathNode* startPath)
{
	CNode* cur = startPath;

	while (nullptr != cur) {

		// 현재 노드가 방인 경우 해당 노드를 반환
		if (cur->GetNodeType() == L"CRoom") {
			return (CRoom*)cur;
		}
		// 현재 노드가 경로이면 오른쪽으로 이동
		else if (cur->GetNodeType() == L"CPathNode") {
			CPathNode* pathCur = (CPathNode*)cur;

			cur = pathCur->GetRightNode();
		}
	}

	// 오른쪽은 경로 아니면 방이므로 이부분을 통과하지 못함
	assert(nullptr);

	return nullptr;
}

CRoom* CMap::findLeftRoom(CPathNode* startPath)
{
	CNode* cur = startPath;

	while (nullptr != cur) {

		// 현재 노드가 방인 경우 해당 노드를 반환
		if (cur->isRoom()) {
			return (CRoom*)cur;
		}
		// 현재 노드가 경로이면 오른쪽으로 이동
		else {
			CPathNode* pathCur = (CPathNode*)cur;

			cur = pathCur->GetRightNode();
		}
	}

	// 오른쪽은 경로 아니면 방이므로 이부분을 통과하지 못함
	assert(nullptr);

	return nullptr;
}

vector<CPathNode*> CMap::GetLeftPaths(CRoom* startRoom)
{
	CNode* cur = startRoom->GetLeftNode();
	vector<CPathNode*> paths;

	if (((CPathNode*)cur)->GetLeftNode()->GetNodeType() == L"CRoom") {

		while (nullptr != cur) {

			// path부터 시작하므로 Room을 찾을 경우에는 리턴
			if (cur->isRoom()) {
				return paths;
			}

			else {
				CPathNode* pathCur = (CPathNode*)cur;
				paths.push_back(pathCur);
				cur = pathCur->GetRightNode();
			}
		}

	}
	else if (((CPathNode*)cur)->GetRightNode()->GetNodeType() == L"CRoom") {

		while (nullptr != cur) {

			// path부터 시작하므로 Room을 찾을 경우에는 리턴
			if (cur->isRoom()) {
				return paths;
			}

			else {
				CPathNode* pathCur = (CPathNode*)cur;
				paths.push_back(pathCur);
				cur = pathCur->GetLeftNode();
			}
		}
	}

	//while (nullptr != cur) {

	//	// path부터 시작하므로 Room을 찾을 경우에는 리턴
	//	if (cur->isRoom()) {
	//		return paths;
	//	}

	//	else {
	//		CPathNode* pathCur = (CPathNode*)cur;
	//		paths.push_back(pathCur);
	//		cur = pathCur->GetRightNode();
	//	}
	//}

	return paths;
}

vector<CPathNode*> CMap::GetRightPaths(CRoom* startRoom)
{
	CNode* cur = startRoom->GetRightNode();
	vector<CPathNode*> paths;

	if (((CPathNode*)cur)->GetLeftNode()->GetNodeType() == L"CRoom") {

		while (nullptr != cur) {

			// path부터 시작하므로 Room을 찾을 경우에는 리턴
			if (cur->isRoom()) {
				return paths;
			}

			else {
				CPathNode* pathCur = (CPathNode*)cur;
				paths.push_back(pathCur);
				cur = pathCur->GetRightNode();
			}
		}

	}
	else if (((CPathNode*)cur)->GetRightNode()->GetNodeType() == L"CRoom") {

		while (nullptr != cur) {

			// path부터 시작하므로 Room을 찾을 경우에는 리턴
			if (cur->isRoom()) {
				return paths;
			}

			else {
				CPathNode* pathCur = (CPathNode*)cur;
				paths.push_back(pathCur);
				cur = pathCur->GetLeftNode();
			}
		}
	}

	//while (nullptr != cur) {

	//	// path부터 시작하므로 Room을 찾을 경우에는 리턴
	//	if (cur->isRoom()) {
	//		return paths;
	//	}

	//	else {
	//		CPathNode* pathCur = (CPathNode*)cur;
	//		paths.push_back(pathCur);
	//		cur = pathCur->GetRightNode();
	//	}
	//}

	return paths;
}

vector<CPathNode*> CMap::GetUpPaths(CRoom* startRoom)
{
	CNode* cur = startRoom->GetUpNode();
	vector<CPathNode*> paths;

	if (((CPathNode*)cur)->GetLeftNode()->GetNodeType() == L"CRoom") {

		while (nullptr != cur) {

			// path부터 시작하므로 Room을 찾을 경우에는 리턴
			if (cur->isRoom()) {
				return paths;
			}

			else {
				CPathNode* pathCur = (CPathNode*)cur;
				paths.push_back(pathCur);
				cur = pathCur->GetRightNode();
			}
		}

	}
	else if (((CPathNode*)cur)->GetRightNode()->GetNodeType() == L"CRoom") {

		while (nullptr != cur) {

			// path부터 시작하므로 Room을 찾을 경우에는 리턴
			if (cur->isRoom()) {
				return paths;
			}

			else {
				CPathNode* pathCur = (CPathNode*)cur;
				paths.push_back(pathCur);
				cur = pathCur->GetLeftNode();
			}
		}
	}

	//while (nullptr != cur) {

	//	// path부터 시작하므로 Room을 찾을 경우에는 리턴
	//	if (cur->isRoom()) {
	//		return paths;
	//	}

	//	else {
	//		CPathNode* pathCur = (CPathNode*)cur;
	//		paths.push_back(pathCur);
	//		cur = pathCur->GetRightNode();
	//	}
	//}

	return paths;
}

vector<CPathNode*> CMap::GetBotPaths(CRoom* startRoom)
{
	CNode* cur = startRoom->GetDownNode();
	vector<CPathNode*> paths;

	if (((CPathNode*)cur)->GetLeftNode()->GetNodeType() == L"CRoom") {

		while (nullptr != cur) {

			// path부터 시작하므로 Room을 찾을 경우에는 리턴
			if (cur->isRoom()) {
				return paths;
			}

			else {
				CPathNode* pathCur = (CPathNode*)cur;
				paths.push_back(pathCur);
				cur = pathCur->GetRightNode();
			}
		}

	}
	else if (((CPathNode*)cur)->GetRightNode()->GetNodeType() == L"CRoom") {

		while (nullptr != cur) {

			// path부터 시작하므로 Room을 찾을 경우에는 리턴
			if (cur->isRoom()) {
				return paths;
			}

			else {
				CPathNode* pathCur = (CPathNode*)cur;
				paths.push_back(pathCur);
				cur = pathCur->GetLeftNode();
			}
		}
	}

	//while (nullptr != cur) {

	//	// path부터 시작하므로 Room을 찾을 경우에는 리턴
	//	if (cur->isRoom()) {
	//		return paths;
	//	}

	//	else {
	//		CPathNode* pathCur = (CPathNode*)cur;
	//		paths.push_back(pathCur);
	//		cur = pathCur->GetRightNode();
	//	}
	//}

	return paths;
}

vector<CPathNode*> CMap::GetRightPaths(CNode* startRoom)
{
	CNode* cur = ((CRoom*)startRoom)->GetRightNode();
	vector<CPathNode*> paths;

	while (nullptr != cur) {

		// path부터 시작하므로 Room을 찾을 경우에는 리턴
		if (cur->isRoom()) {
			return paths;
		}

		else {
			CPathNode* pathCur = (CPathNode*)cur;
			paths.push_back(pathCur);
			cur = pathCur->GetRightNode();
		}
	}

	return paths;
}

vector<CPathNode*> CMap::GetPathBtwRoom(CRoom* leftRoom, CRoom* rightRoom, int dir)
{
	vector<CPathNode*> paths;

	CRoom* toRoom = nullptr;

	// 우, 상은 FindRight 좌, 하는 findLeft

	if (dir == 2) {
		if (nullptr != leftRoom->GetLeftNode()) {
			paths = GetLeftPaths(leftRoom);
		}
	}
	else if (dir == 3) {
		if (nullptr != leftRoom->GetRightNode()) {
			paths = GetRightPaths(leftRoom);
		}
	}
	else if (dir == 0) {
		if (nullptr != leftRoom->GetUpNode()) {
			paths = GetUpPaths(leftRoom);

		}
	}
	else if (dir == 1) {
		if (nullptr != leftRoom->GetDownNode()) {
			paths = GetBotPaths(leftRoom);
			//  && findLeftRoom(leftRoom->GetDownNode())->GetName() == rightRoom->GetName()
		}
	}

	return paths;
}

void CMap::MakeLeftPath(CRoom* right, CRoom* left)
{
	CPathNode* path1 = new CPathNode();
	path1->SetDir(PATH_DIR::LEFT);
	nodeLists.push_back(path1);

	// 2번째 통로를 전투 노드로 만듬
	CPathNode* path2 = new CPathNode();
	path2->SetDir(PATH_DIR::LEFT);
	nodeLists.push_back(path2);

	CPathNode* path3 = new CPathNode();
	path3->SetDir(PATH_DIR::LEFT);
	nodeLists.push_back(path3);

	CPathNode* path4 = new CPathNode();
	path4->SetDir(PATH_DIR::LEFT);
	nodeLists.push_back(path4);

	right->SetLeftNode(path1);

	path1->SetLeftNode(right);
	path1->SetRightNode(path2);

	path2->SetLeftNode(path1);
	path2->SetRightNode(path3);

	path3->SetLeftNode(path2);
	path3->SetRightNode(path4);

	path4->SetLeftNode(path3);
	path4->SetRightNode(left);

	left->SetRightNode(path4);
}

void CMap::MakeRightPath(CRoom* left, CRoom* right)
{
	CPathNode* path1 = new CPathNode();
	path1->SetDir(PATH_DIR::RIGHT);
	nodeLists.push_back(path1);
	rightNodes.push_back(path1);

	// 2번째 통로를 전투 노드로 만듬
	CPathNode* path2 = new CPathNode();
	path2->SetDir(PATH_DIR::RIGHT);
	//path2->MakeBattleNode();
	nodeLists.push_back(path2);
	rightNodes.push_back(path2);

	CPathNode* path3 = new CPathNode();
	path3->SetDir(PATH_DIR::RIGHT);
	nodeLists.push_back(path3);
	rightNodes.push_back(path3);

	CPathNode* path4 = new CPathNode();
	path4->SetDir(PATH_DIR::RIGHT);
	nodeLists.push_back(path4);
	rightNodes.push_back(path4);

	left->SetRightNode(path1);

	path1->SetLeftNode(left);
	path1->SetRightNode(path2);

	path2->SetLeftNode(path1);
	path2->SetRightNode(path3);

	path3->SetLeftNode(path2);
	path3->SetRightNode(path4);

	path4->SetLeftNode(path3);
	path4->SetRightNode(right);

	right->SetLeftNode(path4);
}

void CMap::MakeUpPath(CRoom* down, CRoom* up)
{
	CPathNode* upPath1 = new CPathNode();
	upPath1->SetDir(PATH_DIR::TOP);
	nodeLists.push_back(upPath1);

	CPathNode* upPath2 = new CPathNode();
	upPath2->SetDir(PATH_DIR::TOP);
	nodeLists.push_back(upPath2);

	CPathNode* upPath3 = new CPathNode();
	upPath3->SetDir(PATH_DIR::TOP);
	nodeLists.push_back(upPath3);

	CPathNode* upPath4 = new CPathNode();
	upPath4->SetDir(PATH_DIR::TOP);
	nodeLists.push_back(upPath4);

	down->SetUpNode(upPath1);

	upPath1->SetLeftNode(down);
	upPath1->SetRightNode(upPath2);

	upPath2->SetLeftNode(upPath1);
	upPath2->SetRightNode(upPath3);

	upPath3->SetLeftNode(upPath2);
	upPath3->SetRightNode(upPath4);

	upPath4->SetLeftNode(upPath3);
	upPath4->SetRightNode(up);

	up->SetDownNode(upPath4);
}

void CMap::MakeDownPath(CRoom* up, CRoom* down)
{
	CPathNode* upPath1 = new CPathNode();
	upPath1->SetDir(PATH_DIR::BOTTOM);
	nodeLists.push_back(upPath1);
	botNodes.push_back(upPath1);

	CPathNode* upPath2 = new CPathNode();
	upPath2->SetDir(PATH_DIR::BOTTOM);
	nodeLists.push_back(upPath2);
	botNodes.push_back(upPath2);

	CPathNode* upPath3 = new CPathNode();
	upPath3->SetDir(PATH_DIR::BOTTOM);
	nodeLists.push_back(upPath3);
	botNodes.push_back(upPath3);

	CPathNode* upPath4 = new CPathNode();
	upPath4->SetDir(PATH_DIR::BOTTOM);
	nodeLists.push_back(upPath4);
	botNodes.push_back(upPath4);

	up->SetDownNode(upPath1);

	upPath1->SetLeftNode(up);
	upPath1->SetRightNode(upPath2);

	upPath2->SetLeftNode(upPath1);
	upPath2->SetRightNode(upPath3);

	upPath3->SetLeftNode(upPath2);
	upPath3->SetRightNode(upPath4);

	upPath4->SetLeftNode(upPath3);
	upPath4->SetRightNode(down);

	down->SetUpNode(upPath4);
}
