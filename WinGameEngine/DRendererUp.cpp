#include "stdafx.h"
#include "DRendererUp.h"

#include "DivUI.h"
#include "KeyMgr.h"
#include "ImageModule.h"

DRendererUp::DRendererUp(DivUI* _myUI, DivUI* _slotConatiner)
	: slotConatiner{_slotConatiner}
	, myUI{_myUI}
{
}

void DRendererUp::Execute()
{
	Vec2 mousePos = MOUSE_POS;

	wstring key = L"";
	wstring path = L"";

	if (nullptr != myUI->GetIModule()) {
		key = myUI->GetIModule()->GetResourceKey();
		path = myUI->GetIModule()->GetRelativePath();
	}

	const vector<UI*> childs = slotConatiner->GetChildUI();

	for (int i = 0; i < childs.size(); i++) {

		Vec2 childLt = childs[i]->GetFinalPos();
		Vec2 childScale = childs[i]->GetScale();

		if (childLt.x <= mousePos.x && mousePos.x <= childLt.x + childScale.x
			&& childLt.y <= mousePos.y && mousePos.y <= childLt.y + childScale.y) {

			DivUI* slot = ((DivUI*)childs[i]);
			
			slot->InitImageModule(key, path);
		}
	}
}
