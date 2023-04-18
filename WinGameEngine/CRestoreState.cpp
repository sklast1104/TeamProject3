#include "stdafx.h"
#include "CRestoreState.h"

#include "ViewMgr.h"
#include "Camera.h"
#include "TimeMgr.h"

#include "CHeroDiv.h"
#include "CMonDiv.h"
#include "Animator.h"
#include "Animation.h"
#include "GameMgr.h"

#include "SceneMgr.h"
#include "Scene.h"
#include "CSquadDiv.h"
#include "CMonSquad.h"

#include "CHero.h"
#include "CDarkMonster.h"
#include "CSkill.h"

CRestoreState::CRestoreState()
	: CState(L"CRestoreState")
	, curTime{0.f}
	, lerpTime{0.3f}
	, canCg{true}
{
}

CRestoreState::~CRestoreState()
{
}

void CRestoreState::Enter()
{
	monDead = false;

	GameMgr* mgr = GameMgr::GetInst();

	int heroIdx = mgr->GetFocusIndex() - (4 - mgr->GetSquadNum());
	int skillIdx = mgr->GetSIndex();

	CHero* chero = mgr->GetFocusedHero();
	//CSkill* hSkill = chero->GetCurSkills()[skillIdx];

	int monIdx = mgr->GetMonFocusIdx();
	int realIdx = mgr->GetMonFocusIdx();
	vector<int>& mulMonIdxes = mgr->GetMulMonIdx();

	if (!curSkill->GetMulti()) {
		monIdx = mgr->GetMonFocusIdx();
		realIdx = mgr->GetMonFocusIdx();
	}
	else {

	}

	
	
	

	ViewMgr::GetInst()->animateZoom(1.0f, 0.3f);
	Vec2 curLookAt = mgr->GetRLook();
	curLookAt -= Vec2(300.f, 160.f);
	Camera::GetInst()->SetLookAt(curLookAt);

	//pSPos = player->GetPos();
	// �÷��̾� ���� ����ε����� 150�� ���Ѱ�
	//pEPos = Vec2(150.f * heroIdx, 0.f);

	for (int i = 0; i < players.size(); i++) {
		pSPoses.push_back(players[i]->GetPos());
	}

	for (int i = 0; i < monsters.size(); i++) {
		//mSPos = monsters[i]->GetPos();
		mSPoses.push_back(monsters[i]->GetPos());
	}

	// �� ������ ��ü���ݱ⸸ ����ٰ� �����ϰ� ¥��
	if (!curSkill->GetMulti() || isPlayer) {
		pEPoses.push_back(Vec2(150.f * heroIdx, 0.f));
	}
	else {
		// �� �����϶� �ߵ��Ǵ� �����̹Ƿ� �÷��̾� �����϶��� �����ؼ� ¥��
		for (int i = 0; i < players.size(); i++) {
			pEPoses.push_back(Vec2(150.f * i, 0.f));
		}
	}


	

	//mSPos = monster->GetPos();

	if (!curSkill->GetMulti()) {
		for (int i = 0; i < monsters.size(); i++) {
			const array<CDarkMonster*, 4>& monSquad = mgr->GetMonSquad();



			for (int i = 0; i < monIdx; i++) {
				if (nullptr != monSquad[i]) {
					if (monSquad[i]->IsDead()) {
						realIdx -= 1;
					}
				}
			}

			mEPos = Vec2(150.f * realIdx, 0.f);
			mEPoses.push_back(mEPos);
		}
	}
	else {

		/*for (int i = 0; i < monsters.size(); i++) {
			const array<CDarkMonster*, 4>& monSquad = mgr->GetMonSquad();

			int realIdx = i;

			for (int i = 0; i < monIdx; i++) {
				if (nullptr != monSquad[i]) {
					if (monSquad[i]->IsDead()) {
						realIdx -= 1;
					}
				}
			}

			mEPos = Vec2(150.f * realIdx, 0.f);
			mEPoses.push_back(mEPos);
		}*/

		/*for (int i = 0; i < monIdx; i++) {
			const array<CDarkMonster*, 4>& monSquad = mgr->GetMonSquad();
			if (nullptr != monSquad[i]) {
				if (monSquad[i]->IsDead()) {
					realIdx -= 1;
				}
			}
		}*/

		// �ĸ´� �ֵ鸸 ���Ϳ� �����µ� �߰��� ������ �ָ�����

		// ���� ���� ���� ���� �ϴ� ��ŵ
		for (int i = 0; i < monsters.size(); i++) {

			if (monsters[i]->isDead()) { monDead = true; }

			mEPos = Vec2(150.f * i, 0.f);
			mEPoses.push_back(mEPos);

		}
	}
	canCg = true;
}

void CRestoreState::Update()
{
	curTime += fDT;

	if (curTime >= lerpTime) {
		curTime = lerpTime;
		//player->PlayHeroCombatAnim();

		for (int i = 0; i < players.size(); i++) {
			players[i]->PlayHeroCombatAnim();
		}

		for (int i = 0; i < monsters.size(); i++) {
			monsters[i]->PlayCombatAnim();
		}

		//monster->PlayCombatAnim();
	}

	if (curTime == lerpTime && canCg) {
		canCg = false;
		// ���⼭ Wait���� ����

		GameMgr* mgr = GameMgr::GetInst();
		CHero* chero = mgr->GetFocusedHero();
		CDarkMonster* cMon = mgr->GetFocusedMonster();

		if (chero->IsDead()) {

		}
		else if (cMon->IsDead() || monDead) {
			ChangeState(GetStateMachine(), L"CMonDead");
		}
		else {
			ChangeState(GetStateMachine(), L"CWaitState");
		}

		//ChangeState(GetStateMachine(), L"CWaitState");
	}

	float t = curTime / lerpTime;

	// �ǵ����� �� ��ġ�� �÷��̾���ǥ, ���� ��ǥ, �ִϸ��̼� ũ�� ����
	//player->SetPos( Mathf::Lerp(pSPos, pEPos, t) );

	for (int i = 0; i < players.size(); i++) {
		players[i]->SetPos(Mathf::Lerp(pSPoses[i], pEPoses[i], t));
	}

	for (int i = 0; i < monsters.size(); i++) {
		monsters[i]->SetPos(Mathf::Lerp(mSPoses[i], mEPoses[i], t));
	}

	

}

void CRestoreState::Exit()
{
	DivUI* pseudoUI = SceneMgr::GetInst()->GetCurScene()->GetPseudoUI();
	CSquadDiv* heroSquad = (CSquadDiv*)FindUIByName(pseudoUI, L"CSquadDiv");
	CMonSquad* monSquad = (CMonSquad*)FindUIByName(pseudoUI, L"CMonSquad");

	//DivUI* vignBg = (DivUI*)FindUIByName(pseudoUI, L"vignBg");
	pseudoUI->SendToBack(L"vignBg");
	// �ƾ����� �������� ���µ� �ٽ� ����
	// �ƴϴ� ��Ŀ�� ��������, ü�¹�, ��Ʈ�����ٸ� �������
	// ü�¹�, ��Ʈ�����ٸ� �Ѻ���
	heroSquad->EnableAllDivChildUI(true);
	monSquad->EnableAllDivChildUI(true);

	heroSquad->EnableAllOnYou(false);

	//monsters.clear();
	pSPoses.clear();
	pEPoses.clear();
	mSPoses.clear();
	mEPoses.clear();
}
