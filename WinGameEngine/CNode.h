#pragma once
enum class WALL_TYPE {
	WALL0,
	WALL1,
	WALL2,
	WALL3,
	WALL4,
	WALL5,
};

enum class ROOM_TYPE {
	ROOM0,
	ROOM1,
	ROOM2,
	ROOM3,
	ROOM4,
	ROOM5,
	ROOM6,
	ROOM7,
	ROOM8
};

class CNode
{
private:
	unordered_map<wstring, wstring> resMap;

protected:

	int id;
	static int pkey;

	wstring rKey;
	wstring rPath;
	wstring name;

	// �湮�� ������ ����ϱ� ���� ��� ����
	wstring nodeType;

	bool visited;

	// ������ �Ͼ�� �������
	bool isBattleNode;
	// ������ �Ͼ�� ��� ������ ���� �̸� ���
	vector<wstring> squadNames;
public:

	CNode();
	virtual ~CNode();

	int GetId() { return id; }

	virtual bool isRoom() const { return false; }

	void MakeBattleNode() { isBattleNode = true; }
	bool IsBattleNode() { return isBattleNode; }

	void SetVisited(bool _visited) { visited = _visited; }
	bool GetVisited() { return visited; }

	const wstring& GetNodeType() { return nodeType; }

	void SetName(const wstring& _name) { name = _name; }
	const wstring& GetName() { return name; }

	const wstring& GetRKey() const {
		return rKey;
	}

	void SetRKey(const wstring& rKey) {
		this->rKey = rKey;
	}

	const wstring& GetRPath() const {
		return rPath;
	}

	void SetRPath(const wstring& rPath) {
		this->rPath = rPath;
	}

	void initSquad();
	const vector<wstring>& GetSquadNames() { return squadNames; }

	void InitDoor();
	void InitStartRoom();
	void InitRandomRoom();
	void InitRandomPath();
	void InitRoomStateByKey(wstring key);
};

