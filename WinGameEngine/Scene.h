#pragma once

class Object;
class DivUI;

class Scene
{
private :

	vector<Object*> m_arrObj[(size_t)GROUP_TYPE::END];
	wstring m_strName;

protected :

	DivUI* pseudoUI;

public :

	Scene();
	virtual ~Scene();

	void AddObject(Object* _pObj, GROUP_TYPE _eType) {
		m_arrObj[(UINT)_eType].push_back(_pObj);
	}

	const vector<Object*>& GetGroupObject(GROUP_TYPE _eType) {
		return m_arrObj[(UINT)_eType];
	}

	void DeleteGroup(GROUP_TYPE _eTarget);
	void DeleteAll();

	vector<Object*>& GetUIGroup() { return m_arrObj[(UINT)GROUP_TYPE::UI]; }

	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName; }

	virtual void update();
	virtual void finalupdate();
	virtual void render(HDC _hc);

	virtual void Enter() = 0;
	virtual void Exit();

	DivUI* GetPseudoUI() { return pseudoUI; }
};

