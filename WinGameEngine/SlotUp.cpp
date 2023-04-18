#include "stdafx.h"
#include "SlotUp.h"
#include "DivUI.h"
#include "ImageModule.h"
#include "GameMgr.h"
#include "CHero.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "ResMgr.h"
#include "Sound.h"

SlotUp::SlotUp(DivUI* _mySlot ,DivUI* _dragUI, int _slotIndex, DivUI* _slotContainer)
	: dragUI{_dragUI}, mySlot{_mySlot}, slotIndex{_slotIndex}, slotContainer{_slotContainer}
{
}

void SlotUp::Execute()
{
	// ����
	ResMgr::GetInst()->LoadSound(L"slowUpSound", L"resource\\sound\\UI\\ui_shared\\ui_shr_button_click_enemy {ee5e5f86-bb29-469b-bc14-674765c230b8}.wav");
	Sound* downSound = ResMgr::GetInst()->FindSound(L"slowUpSound");

	downSound->SetVolume(10.f);
	downSound->Play(false);

	DivUI* pseudoUI = SceneMgr::GetInst()->GetCurScene()->GetPseudoUI();
	DivUI* sideNavUI = (DivUI*)FindUIByName((UI*)pseudoUI, L"heroSideNav");

	wstring key = L"";
	wstring path = L"";
	wstring hName = L"";
	GameMgr* mgr = GameMgr::GetInst();
	const array<CHero*, 4> squad = mgr->GetSquad();

	if (nullptr != dragUI->GetIModule()) {
		key = dragUI->GetIModule()->GetResourceKey();
		path = dragUI->GetIModule()->GetRelativePath();
		hName = dragUI->GetName();
	}

	if (key != L"" && path != L"" && hName != L"") {

		if (mgr->isSlotEmpty(slotIndex)) {

			// ���⼭ �����忡�� �ߺ��� ���ؼ� ó�����ִ� ���ۿ� ���ڴ�...
			// �������ʹ� �巡���Ҷ� ���¸� �����ؼ� ���±������ ����...

			// �̸� ������� ������ ã�Ƽ� �ش� ������ �̹� �����忡 �ִٸ� �����߰� ���� ����
			CHero* hero = mgr->FindHeroByName(hName);

			for (int i = 0; i < 4; i++) {

				if (nullptr == squad[i]) continue;

				if (squad[i]->GetPKey() == hero->GetPKey()) return;
			}

			mgr->AddSquad(slotIndex, hName);
			mySlot->InitImageModule(key, path);
			mySlot->SetName(hName);
			mySlot->SetCanRendImg(true);
			
			// ���Ⱑ �������� �����忡 ��� �� ���Կ� �߰��ߴٴ� ���̱� ������
			// SideNav�� ������Ʈ ���༭ ��Ȱ��ȭ �۾� ���ָ� �ȴ�
			// Ȱ��ȭ �۾��� ���� �ٿ�� ó���������
			sideNavUI->updateValue();

		}
		else {
			
			int prevIndex = dragUI->GetId();
			//CHero* draggingHero = mgr->FindHeroByName(hName);
			mgr->AddSquad(prevIndex, hName);

			if (prevIndex == slotIndex) return;

			mgr->SwapSquad(prevIndex, slotIndex);

			// ���� �����̳ʸ� ��ȸ�ؼ� �ڽ��� �����̳� �̸����� hero�� ã�Ƽ� �ش� ����η� 
			// �̸� �� �̹��� �ʱ�ȭ �׸��� �̹��� ������ ������

			// ������� �Դٸ� ���ӸŴ������� �����ϴ� ������ ���� �ε����� ������ ���� ����
			for (int i = 0; i < slotContainer->GetChildUI().size(); i++) {

				DivUI* slotPortrait = (DivUI*)(slotContainer->GetChildUI()[i]->GetChildUI()[0]);
				
				if (prevIndex == i) {
					
					CHero* prevHero = mgr->GetHeroBySquad(prevIndex);
					slotPortrait->InitImageModule(prevHero->GetKey(), prevHero->GetPath());
					slotPortrait->SetName(prevHero->GetName());
					slotPortrait->SetCanRend(true);
					slotPortrait->SetCanRendImg(true);
				}
				else if (slotIndex == i) {
					CHero* curHero = mgr->GetHeroBySquad(slotIndex);
					slotPortrait->InitImageModule(curHero->GetKey(), curHero->GetPath());
					slotPortrait->SetName(curHero->GetName());
					slotPortrait->SetCanRend(true);
					slotPortrait->SetCanRendImg(true);
				}
			}
		}
	}

}
