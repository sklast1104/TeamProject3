#include "stdafx.h"
#include "CPlayerTurn.h"
#include "GameMgr.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "CSquadDiv.h"
#include "CMonSquad.h"
#include "ResMgr.h"
#include "Sound.h"

CPlayerTurn::CPlayerTurn()
	: CState(L"CPlayerTurn")
{
}

CPlayerTurn::~CPlayerTurn()
{
}

void CPlayerTurn::Enter()
{
	DivUI* pseudoUI = SceneMgr::GetInst()->GetCurScene()->GetPseudoUI();

	heroSquad = (CSquadDiv*)FindUIByName(pseudoUI, L"CSquadDiv");
	monSquad = (CMonSquad*)FindUIByName(pseudoUI, L"CMonSquad");
	curHeroIndex = GameMgr::GetInst()->GetFocusIndex();

	// ���� ���� ĳ���͸� ��Ŀ��

	heroSquad->EnableFocus(curHeroIndex);

	// ������ġ���� ��� ������ ��ų Ȱ��ȭ �� ��Ȱ��ȭ
	heroSquad->EnableSkill(curHeroIndex);

	// ��ų ��Ŀ�� UI�� ��Ȱ��ȭ �ص���
	vector<UI*> vec = FindUIsByName(pseudoUI, L"skillSelected");
	for (int i = 0; i < vec.size(); i++) {
		((DivUI*)(vec[i]))->SetCanRend(false);
	}

	monSquad->SortChildUI();
	// �÷��̾� ���ϋ� �׻� ���� ������ ������ �ٽ� ���Ľ��������
}

void CPlayerTurn::Update()
{
}

void CPlayerTurn::Exit()
{
}


