#pragma once

class UI;

class UIMgr
{

private :

	UI* m_pFocusedUI;

	UI* GetFocusedUI();
	UI* GetTargetedUI(UI* _pParentUI); // �θ� UI ������ ������ Ÿ���� �� UI�� ã�Ƽ� ��ȯ�Ѵ�

public :
	void update();

	void SetFocusedUI(UI* _pUI);
public :

	SINGLE(UIMgr);

};

