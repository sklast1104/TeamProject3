#pragma once

class UI;

class UIMgr
{

private :

	UI* m_pFocusedUI;

	UI* GetFocusedUI();
	UI* GetTargetedUI(UI* _pParentUI); // 부모 UI 내에서 실제로 타겟팅 된 UI를 찾아서 반환한다

public :
	void update();

	void SetFocusedUI(UI* _pUI);
public :

	SINGLE(UIMgr);

};

