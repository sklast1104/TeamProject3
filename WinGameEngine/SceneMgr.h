#pragma once

class Scene;

class SceneMgr
{
private :

	Scene* m_arrScene[(size_t)SCENE_TYPE::END];
	Scene* m_pCurScene;

public :

	void init();
	void update();
	void render(HDC _dc);

	Scene* GetCurScene() { return m_pCurScene; }
	Scene* GetSceneByName(const wstring& _name);

	void ChangeScene(SCENE_TYPE _eNext);

public :
	SINGLE(SceneMgr);
};

