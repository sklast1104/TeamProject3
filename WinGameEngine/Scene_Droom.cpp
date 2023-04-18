#include "stdafx.h"
#include "Scene_Droom.h"
#include "Core.h"
#include "DivUI.h"
#include "UIMgr.h"
#include "Camera.h"
#include "ShopInvUpdateVal.h"
#include "UIFactory.h"
#include "GameMgr.h"
#include "CSquadDiv.h"
#include "CHeroDiv.h"
#include "CSelectedOverlay.h"
#include "KeyMgr.h"
#include "CHero.h"
#include "CSkill.h"
#include "MapBtnClick.h"
#include "InvBtnClick.h"
#include "MainLeftUpdateCom.h"
#include "HeroDivClick.h"
#include "CMonSquad.h"
#include "CMonDiv.h"
#include "TimeMgr.h"
#include "SoundMgr.h"
#include "Sound.h"
#include "ResMgr.h"
#include "SkillContainerUpdate.h"
#include "SkillOnclick.h"
#include "MonDivOnClick.h"
#include "ViewMgr.h"
#include "CDarkMonster.h"
#include "DarkestMachine.h"
#include "CMap.h"
#include "CRoom.h"
#include "DMapUI.h"
#include "AnimatorDK.h"
#include "TorchGazeUI.h"
#include "DamageDiv.h"
#include "CCutScene.h"
#include "Animation.h"

Scene_Droom::Scene_Droom()
	: firstVisit{true}
{
	elapseTime = 0.f;
	debug = true;
	battleFlag = true;
}

Scene_Droom::~Scene_Droom()
{
}

void Scene_Droom::render(HDC _dc)
{
	Scene::render(_dc);

	/*TextOutA(_dc, 20, 20, camCoordText.c_str(), camCoordText.length());

	TextOutA(_dc, 20, 40, playerCoordText.c_str(), playerCoordText.length());

	wstring stateName = GameMgr::GetInst()->GetMachine()->GetCurStateName();
	std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
	std::string str = conv.to_bytes(stateName);

	TextOutA(_dc, 20, 80, str.c_str(), str.length());*/
}

void Scene_Droom::Enter()
{
	if (GameMgr::GetInst()->GetMap()->GetCurNode()->IsBattleNode()) {
		GameMgr::GetInst()->SetBossSquad();
	}
	else {
		GameMgr::GetInst()->SetRandomSquad();
	}

	
	elapseTime = 0.f;
	battleFlag = true;
	// 맵 초기화
	dMap = GameMgr::GetInst()->GetMap();
	CRoom* curRoom = (CRoom*)dMap->GetCurNode();

	Camera::GetInst()->SetCurLookAt(Vec2(960.f, 540.f));

	// 드래그 되는 인벤토리용 오브젝트
	itemDragger = new DivUI;
	itemDragger->SetScale(Vec2(72.f, 144.f));
	itemDragger->SetPos(Vec2(960.f, 540.f));
	itemDragger->SetName(L"itemDragger");
	itemDragger->CanTarget(false);
	itemDragger->SetCanRend(false);

	Vec2 vResolution = Core::GetInst()->GetResolution();

	pseudoUI = new DivUI;
	pseudoUI->SetScale(vResolution);
	pseudoUI->SetPos(Vec2(0.f, 0.f));
	pseudoUI->CanTarget(false);



	DivUI* bg = new DivUI;
	bg->SetPos(Vec2(0.f, 0.f));
	bg->SetScale(Vec2(1920.f, 720.f));
	bg->InitImageModule(curRoom->GetRKey() , curRoom->GetRPath());
	bg->CanTarget(false);
	bg->SetCamAffected(true);

	pseudoUI->AddChild(bg);

	AddObject(pseudoUI, GROUP_TYPE::UI);

#pragma region Hero

	// 스케일은 인원수 비례해서 커지고
	// 포지션은 인원수 반비례해서 작아져야함
	squad = UIFactory::CreateSquadDiv();
	
	pseudoUI->AddChild(squad);
	
#pragma endregion

#pragma region Monster

	CMonSquad* monSquadDiv = UIFactory::CreateMonSquadDiv();
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

	if (firstVisit) {
		firstVisit = false;
		CMap* map = GameMgr::GetInst()->GetMap();
		map->SetCurNode(map->getStartRoom());
	}
	else {
		CMap* map = GameMgr::GetInst()->GetMap();
		CRoom* curRoom2 = (CRoom*)map->FindNodeById(GameMgr::GetInst()->GetCurNodeIdx());
		map->SetCurNode(curRoom2);
	}

	DMapUI* mapPanel = (DMapUI*)FindUIByName(pseudoUI, L"mapPanel");

	mapPanel->EnableAllIndicator(false);
	int curNodeId = GameMgr::GetInst()->GetMap()->GetCurNode()->GetId();
	mapPanel->EnableIndibyIdx(curNodeId);

	questContainer = new DivUI;
	questContainer->CanTarget(false);
	questContainer->SetPos(Vec2(0.f, 0.f));
	questContainer->SetScale(Vec2(1920.f, 1080.f));
	questContainer->SetCanRend(false);

	AddObject(questContainer, GROUP_TYPE::FINAL);

	DivUI* questCompleteTxt = new DivUI;
	questCompleteTxt->SetPos(Vec2(960.f - 310.f, 100.f));
	questCompleteTxt->SetScale(Vec2(619.f, 136.f));
	questCompleteTxt->InitImageModule(L"skill_title_ui", L"resource\\panels\\quest_complete_choice_shared_frame.png");
	questCompleteTxt->InitTextModule(L"API 원정 완료!", 40);
	questCompleteTxt->SetTextColor(202, 186, 122);

	questContainer->AddChild(questCompleteTxt);

	DivUI* questComplete = new DivUI;
	questComplete->SetPos(Vec2(960.f - (873.f / 2.f), 0.f));
	questComplete->SetScale(Vec2(873.f, 873.f));
	questComplete->CreateAnimator(new AnimatorDK);
	questComplete->LoadAnimation(L"ending_Animation", L"resource\\animations\\quest\\quest_complete_crest.sprite-idle.atlas", true);
	questComplete->GetAnimator()->FindAnimation(L"ending_Animation")->SetAllFrameDuration(199.f);

	questContainer->AddChild(questComplete);

	/*DivUI* questBack = new DivUI;
	questBack->SetPos(Vec2(960.f - 310.f, 650.f));
	questBack->SetScale(Vec2(619.f, 136.f));
	questBack->InitImageModule(L"skill_title_ui", L"resource\\panels\\quest_complete_choice_shared_frame.png");

	questContainer->AddChild(questBack);*/

	// 씬에 처음 들어왔을때 아무 클릭도 안된상태면 계속 포커싱이 안되므로 임의의 포커싱을 강제로 줌
	UIMgr::GetInst()->SetFocusedUI(pseudoUI);

	// 효과
	Camera::GetInst()->FadeIn(0.5f);

	
		// 사운드
		ResMgr::GetInst()->LoadSound(L"RuinsLevel1Bgm", L"resource\\sound\\Music\\Explore_Vaults_Level_4_Loop {c2d13f7b-ed1b-4b6a-ae0f-92809d15b7c7}.wav");
		Sound* pTitleSound = ResMgr::GetInst()->FindSound(L"RuinsLevel1Bgm");

		pTitleSound->SetVolume(20.f);
		pTitleSound->PlayToBGM(true);
	

	
}

void Scene_Droom::update()
{
	elapseTime += fDT;

	if (GameMgr::GetInst()->GetMap()->GetCurNode()->IsBattleNode() && elapseTime >= 2.f && battleFlag) {
		battleFlag = false;

		ChangeState(GameMgr::GetInst()->GetMachine(), L"CBStartState");

	}

	//if (elapseTime >= 1.f && debug) {
	//	debug = false;
	//	ChangeState((CStMachine*)GameMgr::GetInst()->GetMachine(), L"CBStartState");
	//}

	cameraCoord = Camera::GetInst()->GetLookAt();
	camCoordText = "Camera Coord : (" + std::to_string(cameraCoord.x) + ", " + std::to_string(cameraCoord.y) + ")";

	playerCoord = squad->GetFinalPos();
	playerCoordText = "Player Coord : (" + std::to_string(playerCoord.x) + ", " + std::to_string(playerCoord.y) + ")";

	//if (KEY_TAP(KEY::LBTN)) {

	//	Vec2 mousePos = Camera::GetInst()->GetRealPos(MOUSE_POS);
	//	//mousePos = ViewMgr::GetInst()->GetViewPortPos(mousePos);
	//	Camera::GetInst()->SetLookAt(mousePos);
	//}

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
