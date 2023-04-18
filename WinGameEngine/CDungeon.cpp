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
	ruinReconQ->SetQDisc(L"������ ������ ���� � ������\nŽ���սô�. �������� ������ ������\n�������� ���� �ʹ� �ָ� ����\n���ñ�.");
	ruinReconQ->SetDPath(L"ª��");
	ruinReconQ->SetQLevel(L"�߽� (1����)");
	ruinReconQ->SetQGoal(L"��ü ���� 100%�� Ž���ϱ�");

	questVec.push_back(ruinReconQ);

	CQuest* ruinBattleQ = new CQuest(QuestType::BATTLE);
	ruinBattleQ->SetQDisc(L"���������� �������� �� ���� ������,\n������ �о�ٿ��� �� ���� �ִ�\n���Դϴ�. �ǻ�Ƴ� ���ڵ��� ��������\n���������ʽÿ�. ������ ���Դϴ�.");
	ruinBattleQ->SetDPath(L"�߰�");
	ruinBattleQ->SetQLevel(L"���׶� (3����)");
	ruinBattleQ->SetQGoal(L"�� ������ 100%�� ����ġ��");

	questVec.push_back(ruinBattleQ);

	CQuest* ruinBossQ = new CQuest(QuestType::BOSS);
	ruinBossQ->SetQDisc(L"���ٴ� ��ġ����, �ĸ��� ���, ������\n�絵. ���� ������ �����̵�, �ݷ���\n ������ ����� �� ������ ����\n�߶������ �մϴ�. �� ��Ī \"������\"��\nóġ�ϼ���.");
	ruinBossQ->SetDPath(L"��");
	ruinBossQ->SetQLevel(L"è�Ǿ� (5����)");
	ruinBossQ->SetQGoal(L"1������ �����ڸ� óġ�ϱ�");

	questVec.push_back(ruinBossQ);
}

void CDungeon::InitCourt()
{
	CQuest* courtBossQ = new CQuest(QuestType::BOSS);
	courtBossQ->SetQDisc(L"�������� û�߿��� ����մϴ�... �Ƹ�\n������ ���� ���ϴ°� �ƴұ��?");
	courtBossQ->SetDPath(L"�뼭���");
	courtBossQ->SetQLevel(L"���� ��ο� (6����)");
	courtBossQ->SetQGoal(L"1������ ������ óġ�ϱ�");

	questVec.push_back(courtBossQ);
}

void CDungeon::InitBay()
{
	CQuest* bayReconQ = new CQuest(QuestType::RECON);
	bayReconQ->SetQDisc(L"���� �Ʒ��� ��� ���� ����������\n�������� ����ִ� ���縦 ã�� �����ʽÿ�.");
	bayReconQ->SetDPath(L"ª��");
	bayReconQ->SetQLevel(L"�߽� (1����)");
	bayReconQ->SetQGoal(L"��ü ���� 100%�� Ž���ϱ�");

	questVec.push_back(bayReconQ);


	CQuest* bayBattleQ = new CQuest(QuestType::BATTLE);
	bayBattleQ->SetQDisc(L"�� �� �޸� ����? ���� ��Ÿ�� ������\n������ ������ ���ʽÿ�.");
	bayBattleQ->SetDPath(L"�߰�");
	bayBattleQ->SetQLevel(L"���׶� (3����)");
	bayBattleQ->SetQGoal(L"�� ������ 100%�� ����ġ��");

	questVec.push_back(bayBattleQ);


	CQuest* bayBossQ = new CQuest(QuestType::BOSS);
	bayBossQ->SetQDisc(L"������ �ʴ� ������ �� ������ ���� �ƴ�\n���� ������ �Ҹ��� ���� ���� ��������\n�޾Ƹ�ġ�� �ֽ��ϴ�. �� �ٿ���\nã�Ƽ�... ħ����Ű�ʽÿ�.");
	bayBossQ->SetDPath(L"��");
	bayBossQ->SetQLevel(L"è�Ǿ� (5����)");
	bayBossQ->SetQGoal(L"1������ ���̷� óġ�ϱ�");

	questVec.push_back(bayBossQ);
}
