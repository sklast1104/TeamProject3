#include "stdafx.h"
#include "CQuest.h"

CQuest::CQuest(QuestType _qType)
	: qType{_qType}
{
	if (qType == QuestType::RECON) {

		fillKey = L"ReconKey";
		fillPath = L"resource\\quest_select\\quest_select_explore_1.png";
	}
	else if (qType == QuestType::BATTLE) {
		fillKey = L"Battle_fill_Key";
		fillPath = L"resource\\quest_select\\quest_select_cleanse_3.png";
	}
	else if (qType == QuestType::BOSS) {
		fillKey = L"Boss_fill_key";
		fillPath = L"resource\\quest_select\\quest_select_kill_boss_5.png";
	}
}

const wstring CQuest::GetQTypeTitle()
{
	if (qType == QuestType::RECON) {

		return L"정찰";

	}else if (qType == QuestType::BATTLE) {

		return L"전투";

	}
	else if (qType == QuestType::BOSS) {
		
		return L"보스 처단";

	}

	// TODO: 여기에 return 문을 삽입합니다.
}
