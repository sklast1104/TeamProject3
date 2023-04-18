#include "stdafx.h"
#include "ForwardBtnClick.h"

#include "Scene.h"
#include "SceneMgr.h"
#include "GameMgr.h"
#include "CMap.h"
#include "ResMgr.h"
#include "Sound.h"

void ForwardBtnClick::Execute()
{
	ResMgr::GetInst()->LoadSound(L"forwardBtnClickSound", L"resource\\sound\\UI\\ui_shared\\ui_town_button_click.wav");
	Sound* downSound = ResMgr::GetInst()->FindSound(L"forwardBtnClickSound");

	downSound->SetVolume(30.f);
	downSound->Play(false);

	Scene* curScene = SceneMgr::GetInst()->GetCurScene();

	if (curScene->GetName() == L"Scene_Town") {
		ChangeScene(SCENE_TYPE::DSELECT);
	}
	else if (curScene->GetName() == L"Scene_DSelect") {
		ChangeScene(SCENE_TYPE::SHOP);
	}
	else if (curScene->GetName() == L"Scene_Shop") {

		// 여기서만 현재노드를 시작노드로 바꿔야함
		CMap* map = GameMgr::GetInst()->GetMap();
		map->SetCurNode(map->getStartRoom());

		ChangeScene(SCENE_TYPE::DROOM);
	}
}
