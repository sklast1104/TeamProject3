#include "stdafx.h"
#include "CDungeon.h"
#include "CQuest.h"

CDungeon::CDungeon(const wstring& _name)
	: name{_name}
{

}

CDungeon::~CDungeon()
{
	for (int i = 0; i < questVec.size(); i++) {
		delete questVec[i];
		questVec[i] = nullptr;
	}
}

void CDungeon::InitRuin()
{
	CQuest* ruinReconQ = new CQuest(QuestType::RECON);
	ruinReconQ->SetQDisc(L"스러진 선조의 광기 어린 영지를\n탐헙합시다. 괴물들이 어디까지 영역을\n넓혔는지 보되 너무 멀리 들어서진\n마시길.");
	ruinReconQ->SetDPath(L"짧음");
	ruinReconQ->SetQLevel(L"견습 (1레벨)");
	ruinReconQ->SetQGoal(L"전체 방의 100%를 탐험하기");

	questVec.push_back(ruinReconQ);

	CQuest* ruinBattleQ = new CQuest(QuestType::BATTLE);
	ruinBattleQ->SetQDisc(L"전략적으로 움직여야 할 때도 있지만,\n힘으로 밀어붙여야 할 때도 있는\n법입니다. 되살아난 망자들을 지옥으로\n돌려보내십시오. 모조리 말입니다.");
	ruinBattleQ->SetDPath(L"중간");
	ruinBattleQ->SetQLevel(L"베테랑 (3레벨)");
	ruinBattleQ->SetQGoal(L"방 전투의 100%를 끝마치기");

	questVec.push_back(ruinBattleQ);

	CQuest* ruinBossQ = new CQuest(QuestType::BOSS);
	ruinBossQ->SetQDisc(L"날뛰는 미치광이, 파멸의 기수, 종말의\n사도. 그의 역할이 무엇이든, 격렬한\n 설교를 내뱉는 그 더러운 혀는\n잘라버려야 합니다. 이 자칭 \"예언자\"를\n처치하세요.");
	ruinBossQ->SetDPath(L"긺");
	ruinBossQ->SetQLevel(L"챔피언 (5레벨)");
	ruinBossQ->SetQGoal(L"1마리의 예언자를 처치하기");

	questVec.push_back(ruinBossQ);
}

void CDungeon::InitCourt()
{
	CQuest* courtBossQ = new CQuest(QuestType::BOSS);
	courtBossQ->SetQDisc(L"여백작이 청중에게 명령합니다... 아마\n마지막 춤을 원하는게 아닐까요?");
	courtBossQ->SetDPath(L"대서사시");
	courtBossQ->SetQLevel(L"가장 어두움 (6레벨)");
	courtBossQ->SetQGoal(L"1마리의 여백작 처치하기");

	questVec.push_back(courtBossQ);
}

void CDungeon::InitBay()
{
	CQuest* bayReconQ = new CQuest(QuestType::RECON);
	bayReconQ->SetQDisc(L"저택 아래의 기분 나쁜 바위투성이\n절벽에서 살아있는 존재를 찾아 나서십시오.");
	bayReconQ->SetDPath(L"짧음");
	bayReconQ->SetQLevel(L"견습 (1레벨)");
	bayReconQ->SetQGoal(L"전체 방의 100%를 탐험하기");

	questVec.push_back(bayReconQ);


	CQuest* bayBattleQ = new CQuest(QuestType::BATTLE);
	bayBattleQ->SetQDisc(L"두 발 달린 생선? 새로 나타난 적들의\n전력을 시험해 보십시오.");
	bayBattleQ->SetDPath(L"중간");
	bayBattleQ->SetQLevel(L"베테랑 (3레벨)");
	bayBattleQ->SetQGoal(L"방 전투의 100%를 끝마치기");

	questVec.push_back(bayBattleQ);


	CQuest* bayBossQ = new CQuest(QuestType::BOSS);
	bayBossQ->SetQDisc(L"잊히지 않는 선율과 이 세상의 것이 아닌\n듯한 저음의 소리가 저택 밑의 절벽에서\n메아리치고 있습니다. 그 근원을\n찾아서... 침묵시키십시오.");
	bayBossQ->SetDPath(L"긺");
	bayBossQ->SetQLevel(L"챔피언 (5레벨)");
	bayBossQ->SetQGoal(L"1마리의 세이렌 처치하기");

	questVec.push_back(bayBossQ);
}
