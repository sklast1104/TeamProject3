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

		return L"����";

	}else if (qType == QuestType::BATTLE) {

		return L"����";

	}
	else if (qType == QuestType::BOSS) {
		
		return L"���� ó��";

	}

	// TODO: ���⿡ return ���� �����մϴ�.
}
