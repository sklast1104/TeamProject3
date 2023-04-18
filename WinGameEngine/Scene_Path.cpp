#include "stdafx.h"
#include "Scene_Path.h"
#include "Core.h"
#include "DivUI.h"
#include "KeyMgr.h"
#include "UIMgr.h"
#include "Camera.h"
#include "UIFactory.h"
#include "CSquadDiv.h"
#include "DivUI.h"
#include "CMonSquad.h"
#include "CMap.h"
#include "CPathNode.h"
#include "GameMgr.h"
#include "DarkestMachine.h"
#include "CBattleTrigger.h"
#include "Collider.h"
#include "CRectangle.h"
#include "CSquadCol.h"
#include "CollisionMgr.h"
#include "CMoveTrigger.h"
#include "CPathNode.h"
#include "CRoom.h"
#include "DoorClick.h"
#include "DMapUI.h"
#include "DamageDiv.h"
#include "CCutScene.h"
#include "TorchGazeUI.h"
#include "AnimatorDK.h"
#include "TorchAnimUI.h"

Scene_Path::Scene_Path()
{
}

Scene_Path::~Scene_Path()
{
}

void Scene_Path::render(HDC _dc)
{
	Scene::render(_dc);

	/*TextOutA(_dc, 20, 20, camCoordText.c_str(), camCoordText.length());

	TextOutA(_dc, 20, 40, playerCoordText.c_str(), playerCoordText.length());

	wstring stateName = GameMgr::GetInst()->GetMachine()->GetCurStateName();
	std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
	std::string str = conv.to_bytes(stateName);

	TextOutA(_dc, 20, 80, str.c_str(), str.length());*/
}

void Scene_Path::Enter()
{
	GameMgr::GetInst()->SetRandomSquad();
	// PathDir이 Left일때만 빼고 전부 왼쪽노드가 우리가 온 방
	/*if (paths[0]->GetDir() == PATH_DIR::LEFT) {
		prevRoom = (CRoom*)paths[0]->GetRightNode();
		nextRoom = (CRoom*)paths[paths.size() - 1]->GetLeftNode();
	}
	else {
		prevRoom = (CRoom*)paths[0]->GetLeftNode();
		nextRoom = (CRoom*)paths[paths.size() - 1]->GetRightNode();
	}*/

	CRoom* curNode = (CRoom*)GameMgr::GetInst()->GetMap()->GetCurNode();

	//int dir = curNode->CheckDir()
	if (paths[0]->GetLeftNode()->GetNodeType() == L"CRoom") {
		prevRoom = (CRoom*)paths[0]->GetLeftNode();
	}
	else if (paths[0]->GetRightNode()->GetNodeType() == L"Croom") {
		prevRoom = (CRoom*)paths[0]->GetRightNode();
	}

	if (paths[paths.size() - 1]->GetLeftNode()->GetNodeType() == L"CRoom") {
		nextRoom = (CRoom*)paths[paths.size() - 1]->GetLeftNode();
	}
	else if (paths[paths.size() - 1]->GetRightNode()->GetNodeType() == L"CRoom") {
		nextRoom = (CRoom*)paths[paths.size() - 1]->GetRightNode();
	}

	/*prevRoom = (CRoom*)paths[0]->GetLeftNode();
	nextRoom = (CRoom*)paths[paths.size() - 1]->GetRightNode();*/

	// 맵 초기화
	//dMap = GameMgr::GetInst()->GetMap();

	// 카메라가 특정 위치부터 시작하도록 고정
	Camera::GetInst()->SetCurLookAt(Vec2(960.f, 540.f) + Vec2(300.f, 0.f));

	Vec2 vResolution = Core::GetInst()->GetResolution();

	pseudoUI = new DivUI;
	pseudoUI->SetScale(vResolution);
	pseudoUI->SetPos(Vec2(0.f, 0.f));
	pseudoUI->CanTarget(false);

	// 드래그 되는 인벤토리용 오브젝트
	itemDragger = new DivUI;
	itemDragger->SetScale(Vec2(72.f, 144.f));
	itemDragger->SetPos(Vec2(960.f, 540.f));
	itemDragger->SetName(L"itemDragger");
	itemDragger->CanTarget(false);
	itemDragger->SetCanRend(false);

#pragma region Background

	Vec2 pbgScale = Vec2(1920.f, 720.f);

	for (int i = 0; i < 15; i++) {
		DivUI* backGround = new DivUI;
		backGround->CanTarget(false);
		backGround->SetPos(Vec2(i * 384.f, 170.f));
		backGround->SetScale(Vec2(384.f + 2.f, 360.f));
		backGround->SetCamAffected(true);
		backGround->InitImageModule(L"CRYPTS_CORRIDOR_BG", L"resource\\Background\\ruins\\crypts.corridor_bg.png");

		pseudoUI->AddChild(backGround);
	}

	for (int i = 0; i < 12; i++) {
		DivUI* backGround = new DivUI;
		backGround->CanTarget(false);
		backGround->SetPos(Vec2(i * 480.f, 98.f));
		backGround->SetScale(Vec2(480.f + 2.f, 480.f));
		backGround->SetCamAffected(true);
		backGround->InitImageModule(L"CRYPTS_CORRIDOR_MID_BG", L"resource\\Background\\ruins\\crypts.corridor_mid.png");

		pseudoUI->AddChild(backGround);
	}

	Vec2 pathScale = Vec2(720.f, 720.f);

	DivUI* doorLeftSide = new DivUI;
	doorLeftSide->CanTarget(false);
	doorLeftSide->SetPos(Vec2(0.f, 0.f));
	doorLeftSide->SetScale(Vec2(pathScale.x, pathScale.y));
	doorLeftSide->SetCamAffected(true);
	doorLeftSide->InitImageModule(L"ROOM_TYPE_WALL0", L"resource\\Background\\ruins\\wall0.png");

	pseudoUI->AddChild(doorLeftSide);

	DivUI* doorLeft = new DivUI;
	doorLeft->CanTarget(false);
	doorLeft->SetPos(Vec2(pathScale.x, 0.f));
	doorLeft->SetScale(Vec2(pathScale.x, pathScale.y));
	doorLeft->SetCamAffected(true);
	doorLeft->InitImageModule(L"ROOM_TYPE_DOOR", L"resource\\Background\\ruins\\door.png");

	pseudoUI->AddChild(doorLeft);

	DivUI* ldoor = new DivUI;
	ldoor->SetPos(Vec2(265.f, 180.f));
	ldoor->SetScale(Vec2(202.f, 429.f));
	ldoor->SetCamAffected(true);
	ldoor->InitImageModule(L"DOOR_CLOSED", L"resource\\Background\\ruins\\door\\closed.png");
	int prevRoomId = prevRoom->GetId();
	ldoor->InitOnMouseClick(new DoorClick(prevRoom->GetId()));

	doorLeft->AddChild(ldoor);

	DivUI* tableLeft = new DivUI;
	tableLeft->CanTarget(false);
	tableLeft->SetPos(Vec2(120.f, -40.f));
	tableLeft->SetScale(Vec2(pathScale.x, pathScale.y) * 1.1f);
	tableLeft->SetCamAffected(true);
	tableLeft->InitImageModule(L"ROOM_TYPE_TABLE_LEFT", L"resource\\Background\\ruins\\endhall_left.png");

	pseudoUI->AddChild(tableLeft);

	DivUI* doorRight = new DivUI;
	doorRight->CanTarget(false);
	doorRight->SetPos(Vec2(pathScale.x * (paths.size() + 2), 0.f));
	doorRight->SetScale(Vec2(pathScale.x, pathScale.y));
	doorRight->SetCamAffected(true);
	doorRight->InitImageModule(L"ROOM_TYPE_DOOR", L"resource\\Background\\ruins\\door.png");

	pseudoUI->AddChild(doorRight);

	DivUI* rdoor = new DivUI;
	rdoor->SetPos(Vec2(265.f, 180.f));
	rdoor->SetScale(Vec2(202.f, 429.f));
	rdoor->SetCamAffected(true);
	rdoor->InitImageModule(L"DOOR_CLOSED", L"resource\\Background\\ruins\\door\\closed.png");
	int nextRoomId = nextRoom->GetId();
	rdoor->InitOnMouseClick(new DoorClick(nextRoom->GetId()));

	doorRight->AddChild(rdoor);

	DivUI* doorRightSide = new DivUI;
	doorRightSide->CanTarget(false);
	doorRightSide->SetPos(Vec2(pathScale.x * (paths.size() + 3), 0.f));
	doorRightSide->SetScale(Vec2(pathScale.x, pathScale.y));
	doorRightSide->SetCamAffected(true);
	doorRightSide->InitImageModule(L"ROOM_TYPE_WALL0", L"resource\\Background\\ruins\\wall0.png");

	pseudoUI->AddChild(doorRightSide);

	DivUI* tableRight = new DivUI;
	tableRight->CanTarget(false);
	tableRight->SetPos(Vec2(pathScale.x * (paths.size() + 3) - 120.f, -40.f));
	tableRight->SetScale(Vec2(pathScale.x, pathScale.y) * 1.1f);
	tableRight->SetCamAffected(true);
	tableRight->InitImageModule(L"ROOM_TYPE_TABLE_RIGHT", L"resource\\Background\\ruins\\endhall.png");

	pseudoUI->AddChild(tableRight);

	for (int i = 0; i < paths.size(); i++) {

		paths[i]->InitRandomPath();

		DivUI* path = new DivUI;
		path->CanTarget(false);
		path->SetPos(Vec2((i + 2) * pathScale.x, 0.f));
		path->SetScale(Vec2(pathScale.x + 2, pathScale.y));
		path->SetCamAffected(true);

		const wstring& key = paths[i]->GetRKey();
		const wstring& pathPath = paths[i]->GetRPath();

		path->InitImageModule(paths[i]->GetRKey(), paths[i]->GetRPath());

		pseudoUI->AddChild(path);

		if (paths[i]->IsBattleNode()) {

			CBattleTrigger* trigger = new CBattleTrigger;
			trigger->SetScale(Vec2(1.f, 400.f));
			trigger->SetPos(path->GetPos() + Vec2(0.f, 500.f));
			trigger->CreateCollider();
			trigger->GetCollider()->SetScale(trigger->GetScale());

			AddObject(trigger, GROUP_TYPE::UI_OVER);
		}

		CMoveTrigger* mTrigger = new CMoveTrigger;
		mTrigger->SetScale(Vec2(1.f, 400.f));
		mTrigger->SetPos(path->GetPos() + Vec2(0.f, 500.f));
		mTrigger->CreateCollider();
		mTrigger->GetCollider()->SetScale(mTrigger->GetScale());
		mTrigger->SetId(paths[i]->GetId());

		AddObject(mTrigger, GROUP_TYPE::UI_OVER);
	}

#pragma endregion

#pragma region Hero

	// 스케일은 인원수 비례해서 커지고
	// 포지션은 인원수 반비례해서 작아져야함
	squad = UIFactory::CreateSquadDiv();
	squad->SetPos(squad->GetPos() + Vec2(350.f, 0.f));

	CSquadCol* heroCol = new CSquadCol;
	heroCol->SetSquad(squad);
	heroCol->SetScale(squad->GetScale());
	heroCol->SetPos(squad->GetPos() + (squad->GetScale() / 2.f));
	heroCol->CreateCollider();
	heroCol->GetCollider()->SetScale(heroCol->GetScale());
	heroCol->SetName(L"heroCol");
		
	AddObject(heroCol, GROUP_TYPE::UI_OVER);

	pseudoUI->AddChild(squad);

#pragma endregion

#pragma region Monster

	CMonSquad* monSquadDiv = UIFactory::CreateMonSquadDiv();
	monSquadDiv->CanTarget(false);
	monSquadDiv->SetCanRend(false);

	pseudoUI->AddChild(monSquadDiv);

#pragma endregion

#pragma region DungeonPanel

	DivUI* panel = UIFactory::CreateDungeonPanel();

	pseudoUI->AddChild(panel);

#pragma endregion

#pragma region SkillTitle

	// 비네트 효과
	DivUI* vignBg = UIFactory::CreateVignBg();

	pseudoUI->AddChild(vignBg);

	DivUI* skilTitle = UIFactory::CreateSkilTitle();

	pseudoUI->AddChild(skilTitle);

	DivUI* bStartAnim = UIFactory::CreateBStartDiv();

	pseudoUI->AddChild(bStartAnim);

	DivUI* bloodSplatLeftFx = UIFactory::CreateLeftBlood();

	pseudoUI->AddChild(bloodSplatLeftFx);

	DivUI* bloodSplatRightFx = UIFactory::CreateRightBlood();

	pseudoUI->AddChild(bloodSplatRightFx);

	DamageDiv* damageLeftUI = new DamageDiv;
	damageLeftUI->SetScale(Vec2(100.f, 50.f));
	damageLeftUI->InitTextModule(11, 55);
	damageLeftUI->SetPos(Vec2(600.f, 420.f));
	damageLeftUI->SetCamAffected(false);
	damageLeftUI->SetViewAffected(false);
	damageLeftUI->SetTextColor(249, 29, 0);
	damageLeftUI->SetBold(900);
	damageLeftUI->SetCanRend(false);
	damageLeftUI->SetOriginPos(Vec2(600.f, 370.f));
	//damageLeftUI->StartMove();
	
	CCutScene* cutSt = (CCutScene*)GameMgr::GetInst()->GetMachine()->GetState(L"CCutScene");
	cutSt->SetHeroDmgUI(damageLeftUI);

	AddObject(damageLeftUI, GROUP_TYPE::UI_OVER);

	vector<DamageDiv*>& ddivs = cutSt->GetDamageDivs();
	ddivs.clear();

	if (ddivs.size() < 4) {
		for (int i = 0; i < 4; i++) {
			DamageDiv* damageRightUI = new DamageDiv;
			damageRightUI->SetScale(Vec2(100.f, 50.f));
			damageRightUI->InitTextModule(11, 55);
			damageRightUI->SetPos(Vec2(1100.f + (i * 150.f), 420.f));
			damageRightUI->SetCamAffected(false);
			damageRightUI->SetViewAffected(false);
			damageRightUI->SetTextColor(249, 29, 0);
			damageRightUI->SetBold(900);
			damageRightUI->SetCanRend(false);
			damageRightUI->SetOriginPos(Vec2(1100.f + (i * 150.f), 420.f));
			//damageLeftUI->StartMove();

			cutSt->AddMonDmgUIs(damageRightUI);
			AddObject(damageRightUI, GROUP_TYPE::UI_OVER);
		}
	}

	vector<DamageDiv*>& hddivs = cutSt->GetHeroDamageDivs();
	hddivs.clear();

	if (hddivs.size() < 3) {
		for (int i = 0; i < 3; i++) {
			DamageDiv* damageRightUI = new DamageDiv;
			damageRightUI->SetScale(Vec2(100.f, 50.f));
			damageRightUI->InitTextModule(11, 55);
			damageRightUI->SetPos(Vec2(1100.f + (i * 150.f), 420.f));
			damageRightUI->SetCamAffected(false);
			damageRightUI->SetViewAffected(false);
			damageRightUI->SetTextColor(249, 29, 0);
			damageRightUI->SetBold(900);
			damageRightUI->SetCanRend(false);
			damageRightUI->SetOriginPos(Vec2(600.f - (i * 150.f), 420.f));
			//damageLeftUI->StartMove();

			cutSt->AddHeroDmgUIs(damageRightUI);
			AddObject(damageRightUI, GROUP_TYPE::UI_OVER);
		}
	}

	DivUI* torchSystem = UIFactory::CreateTorchSystem();
	

	pseudoUI->AddChild(torchSystem);

#pragma endregion

	pseudoUI->AddChild(itemDragger);
	AddObject(pseudoUI, GROUP_TYPE::UI);

	CMap* map = GameMgr::GetInst()->GetMap();
	int curNodeIdx = GameMgr::GetInst()->GetCurNodeIdx();
	CRoom* curRoom2 = (CRoom*)map->FindNodeById(GameMgr::GetInst()->GetCurNodeIdx());
	map->SetCurNode(curRoom2);

	DMapUI* mapPanel = (DMapUI*)FindUIByName(pseudoUI, L"mapPanel");

	mapPanel->EnableAllIndicator(false);
	int curNodeId = GameMgr::GetInst()->GetMap()->GetCurNode()->GetId();
	mapPanel->EnableIndibyIdx(curNodeId);

	// 씬에 처음 들어왔을때 아무 클릭도 안된상태면 계속 포커싱이 안되므로 임의의 포커싱을 강제로 줌
	UIMgr::GetInst()->SetFocusedUI(pseudoUI);

	// 효과
	Camera::GetInst()->FadeIn(0.5f);

	// 충돌 처리
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::UI_OVER, GROUP_TYPE::UI_OVER);
}

void Scene_Path::update()
{
	cameraCoord = Camera::GetInst()->GetLookAt();
	camCoordText = "Camera Coord : (" + std::to_string(cameraCoord.x) + ", " + std::to_string(cameraCoord.y) + ")";

	playerCoord = squad->GetFinalPos();
	playerCoordText = "Player Coord : (" + std::to_string(playerCoord.x) + ", " + std::to_string(playerCoord.y) + ")";

	Scene::update();

	if (KEY_TAP(KEY::ESC)) {
		ChangeScene(SCENE_TYPE::SHOP);
	}

	Vec2 mPos = MOUSE_POS;
	Vec2 iScale = itemDragger->GetScale();

	itemDragger->SetPos(mPos - iScale / 2.f);

	if (KEY_AWAY(KEY::LBTN)) {
		itemDragger->SetCanRend(false);
	}
}

void Scene_Path::Exit()
{
	CollisionMgr::GetInst()->Reset();

	Scene::Exit();
}
