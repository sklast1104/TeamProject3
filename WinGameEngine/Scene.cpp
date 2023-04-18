#include "stdafx.h"
#include "Scene.h"

#include "Object.h"

Scene::Scene()
{
}

Scene::~Scene()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i) {
		Safe_Delete_Vec(m_arrObj[i]);
	}
}

void Scene::update()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i) {
		for (size_t j = 0; j < m_arrObj[i].size(); ++j) {
			if (!m_arrObj[i][j]->isDead())
				m_arrObj[i][j]->update();
		}
	}
}

void Scene::finalupdate()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i) {
		for (size_t j = 0; j < m_arrObj[i].size(); ++j) {
			m_arrObj[i][j]->finalupdate();
		}
	}
}

void Scene::render(HDC _hc)
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i) {

		vector<Object*>::iterator iter = m_arrObj[i].begin();

		for (; iter != m_arrObj[i].end();) {
			if (!(*iter)->isDead()) {
				(*iter)->render(_hc);
				++iter;
			}
			else {
				iter = m_arrObj[i].erase(iter);
			}
		}
	}
}

void Scene::Exit()
{
	DeleteAll();
}

void Scene::DeleteGroup(GROUP_TYPE _eTarget)
{
	Safe_Delete_Vec<Object*>(m_arrObj[(size_t)_eTarget]);
}

void Scene::DeleteAll()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i) {
		DeleteGroup((GROUP_TYPE)i);
	}
}
