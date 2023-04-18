#include "stdafx.h"
#include "CMonDead.h"
#include "DivUI.h"
#include "CSquadDiv.h"
#include "CMonSquad.h"
#include "Scene.h"
#include "SceneMgr.h"
#include "GameMgr.h"
#include "CMonDiv.h"
#include "TimeMgr.h"
#include "CSkill.h"
#include "CHero.h"
#include "CDarkMonster.h"

CMonDead::CMonDead()
	: CState(L"CMonDead")
	, elapsedTime{0.f}
	, lerpTime{1.f}
{
}

CMonDead::~CMonDead()
{
}

void CMonDead::Enter()
{
	DivUI* pseudoUI = SceneMgr::GetInst()->GetCurScene()->GetPseudoUI();
	heroSquad = (CSquadDiv*)FindUIByName(pseudoUI, L"CSquadDiv");
	monSquad = (CMonSquad*)FindUIByName(pseudoUI, L"CMonSquad");

	GameMgr* mgr = GameMgr::GetInst();

	int heroIdx = mgr->GetFocusIndex();
	int skillIdx = mgr->GetSIndex();
	int monIdx = mgr->GetMonFocusIdx();

	CHero* chero = mgr->GetFocusedHero();
	CSkill* hSkill = chero->GetCurSkills()[skillIdx];

	if (!hSkill->GetMulti()) {
		for (int i = 0; i < monSquad->GetMonDivs().size(); i++) {

			if (monSquad->GetMonDivs()[i]->GetId() > monIdx) {
				//int newId = monSquad->GetMonDivs()[i]->GetId() - monIdx;
				//monSquad->GetMonDivs()[i]->SetId(newId);
				moveDiv.push_back(monSquad->GetMonDivs()[i]);
				startPos.push_back(monSquad->GetMonDivs()[i]->GetPos());
				toPos.push_back(monSquad->GetMonDivs()[i]->GetPos() + Vec2(-150.f, 0.f));
			}
		}
	}
	else {

		int checker = 0;

		for (int i = 0; i < hSkill->GetSkillRange().size(); i++) {
			if (hSkill->GetSkillRange()[i]) checker += 1;
		}

		for (int i = 0; i < monSquad->GetMonDivs().size(); i++) {

			if (monSquad->GetMonDivs()[i]->GetId() >= checker) {
				//int newId = monSquad->GetMonDivs()[i]->GetId() - monIdx;
				//monSquad->GetMonDivs()[i]->SetId(newId);
				moveDiv.push_back(monSquad->GetMonDivs()[i]);
				startPos.push_back(monSquad->GetMonDivs()[i]->GetPos());

				int deadCount = 0;

				const array<CDarkMonster*, 4>& mSquad = mgr->GetMonSquad();
				for (int j = 0; j < i; j++) {

					if (nullptr != mSquad[j]) {
						if (mSquad[j]->IsDead()) {
							deadCount += 1;
						}
					}

				}

				Vec2 toPoss = monSquad->GetMonDivs()[i]->GetPos() + Vec2(-150.f, 0.f) * (deadCount);
				toPos.push_back(monSquad->GetMonDivs()[i]->GetPos() + Vec2(-150.f, 0.f) * (deadCount));
			}
		}

		/*if (hSkill->GetSkillRange()[i]) {
			moveDiv.push_back(monSquad->GetMonDivByIdx(i));
			startPos.push_back(monSquad->GetMonDivs()[i]->GetPos());
		}

		for (int i = 0; i < moveDiv.size(); i++) {

			Vec2 monPos = moveDiv[i]->GetPos();
			int realIdx = monIdx;
			const array<CDarkMonster*, 4>& monSquad = mgr->GetMonSquad();

			for (int i = 0; i < monIdx; i++) {
				if (nullptr != monSquad[i]) {
					if (monSquad[i]->IsDead()) {
						realIdx -= 1;
					}
				}
			}
			toPos.push_back(moveDiv[i]->GetPos() + Vec2(-150.f * realIdx, 0.f));
		}*/

	}

	

	canCg = true;
}

void CMonDead::Update()
{
	elapsedTime += fDT;

	if (elapsedTime >= lerpTime) {
		elapsedTime = lerpTime;
	}

	float t = elapsedTime / lerpTime;

	for (int i = 0; i < moveDiv.size(); i++) {

		moveDiv[i]->SetPos(Mathf::Lerp(startPos[i], toPos[i], t));

	}

	if (elapsedTime == lerpTime && canCg) {
		canCg = false;

		ChangeState(GetStateMachine(), L"CWaitState");
	}

	// 남은 몬스터들 이동 로직

}

void CMonDead::Exit()
{
	moveDiv.clear();
	startPos.clear();
	toPos.clear();

	elapsedTime = 0.f;
}
