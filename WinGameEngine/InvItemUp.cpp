#include "stdafx.h"
#include "InvItemUp.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "DivUI.h"
#include "Scene_Shop.h"
#include "GameMgr.h"
#include "CItem.h"
#include "ResMgr.h"
#include "Sound.h"

InvItemUp::InvItemUp(DivUI* _myItem, int _index)
	: scene{ SceneMgr::GetInst()->GetCurScene() }
	, myItem{ _myItem }, mgr{ GameMgr::GetInst() }, index{ _index }
{
}

void InvItemUp::Execute()
{
	// ����
	ResMgr::GetInst()->LoadSound(L"slowUpSound", L"resource\\sound\\UI\\ui_shared\\ui_shr_button_click_enemy {ee5e5f86-bb29-469b-bc14-674765c230b8}.wav");
	Sound* downSound = ResMgr::GetInst()->FindSound(L"slowUpSound");

	downSound->SetVolume(10.f);
	downSound->Play(false);

	// Ŭ���̶� ���϶� �Ѵ� �̺�Ʈ ����
	DivUI* itemDragger = (DivUI*)FindUIByName((UI*)(scene->GetPseudoUI()), L"itemDragger");
	DivUI* shopInvPanel = (DivUI*)FindUIByName((UI*)(scene->GetPseudoUI()), L"shopInvPanel");

	array<CItem*, 16>& inventory = mgr->GetInventory();

	CItem* curUp = inventory[index];

	int prevIndex = itemDragger->GetId();

	// Ŭ���̶� ���������̸� �� �̺�Ʈ�� �Ұ� ����
	if (prevIndex == index) return;

	if (nullptr == curUp) {

		// �� �����̸� �������� �Ű��ָ��

		// ���� ���� �Ŵ��� ������� �Ű��ְ� 
		mgr->MoveInventory(prevIndex, index);

		// �κ��丮 �г� �����ͼ� ������Ʈ ���ش�
		shopInvPanel->updateValue();
	}
	else {

		// �׷��� �ʴٸ� ���� �������̶�� maxCount ��
		CItem* prevItem = inventory[prevIndex];
			
		// ���� �������̶��
		if (prevItem->GetName() == curUp->GetName()) {

			int prevCount = prevItem->GetCurCount();
			int curCount = curUp->GetCurCount();

			// ���� �������� ������ �ƽ�ī���ͺ��� ���� ���¶��
			if (curCount < curUp->GetMaxCount()) {

				int reserve = curUp->GetMaxCount() - curUp->GetCurCount();
				if (reserve > prevItem->GetCurCount()) reserve = prevItem->GetCurCount();
				// �ƽ�ī��Ʈ ���и�ŭ �����ְ�
				curUp->SetCurCount(curUp->GetCurCount() + reserve);
				// ���� �������� ���и�ŭ ���ָ� �ڸ��� �ű��� �ʴ´�
				prevItem->SetCurCount(prevItem->GetCurCount() - reserve);
				// �ٵ� ���࿡ prevItemCount�� 0�̶�� nullptr�� �ٲ������
				if (prevItem->GetCurCount() == 0) {
					mgr->RemoveItem(prevIndex);
				}
			}
			// �ƽ�ī��Ʈ��� �׳� �ϰ͵� ����
			else {
				return;
			}

		}
		// �ٸ� �������̶�� ��ġ �ٲٱ�
		else {

			mgr->SwapInventory(prevIndex, index);

		}
		// �ƴ϶�� ����
	}

	// �κ��丮 �г� �����ͼ� ������Ʈ ���ش�
	shopInvPanel->updateValue();
	
}
