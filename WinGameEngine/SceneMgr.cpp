#include "stdafx.h"
#include "SceneMgr.h"

#include "Scene.h"
#include "Scene_Test.h"

SceneMgr::SceneMgr()
	: m_arrScene{}
	, m_pCurScene{ nullptr }
{
}

SceneMgr::~SceneMgr()
{
	for (UINT i = 0; i < (UINT)SCENE_TYPE::END; ++i) {
		if (nullptr != m_arrScene[i]) {
			delete m_arrScene[i];
		}
	}
}

void SceneMgr::init()
{
	m_arrScene[(size_t)SCENE_TYPE::TEST] = new Scene_Test;

	m_pCurScene = m_arrScene[(size_t)SCENE_TYPE::TEST];
	m_pCurScene->Enter();
}

void SceneMgr::update()
{
	m_pCurScene->update();

	m_pCurScene->finalupdate();

}

void SceneMgr::render(HDC _dc)
{
	m_pCurScene->render(_dc);
}

Scene* SceneMgr::GetSceneByName(const wstring& _name)
{
	for (int i = 0; i < (UINT)SCENE_TYPE::END; i++) {

		if (m_arrScene[i]->GetName() == _name) {
			return m_arrScene[i];
		}
	}

	return nullptr;
}

void SceneMgr::ChangeScene(SCENE_TYPE _eNext)
{
	m_pCurScene->Exit();

	m_pCurScene = m_arrScene[(UINT)_eNext];

	m_pCurScene->Enter();
}
