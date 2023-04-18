#pragma once
#include "Object.h"

class UI
	: public Object
{
private :
    vector<UI*> m_vecChildUI;
    UI* m_pParentUI;

    D3DXVECTOR3 m_vFinalPos;
    bool m_bCamAffected; // UI�� ī�޶� ������ �޴���
    bool m_viewAffected; // View ��ȯ�� �޴���
    bool m_bMouseOn; // UI ���� �����̽��� �ִ���
    bool m_bLbtnDown; // �ٿ�� ���� �ִ���
    bool m_canTarget; // Ÿ���� �� �� �ִ���

    void update_child();
    void finalupdate_child();
    void render_child(HDC _dc);

    void MouseOnCheck();
public:

    D3DXVECTOR3 GetFinalPos() { return m_vFinalPos; }
    UI* GetParent() { return m_pParentUI; }
    bool IsMouseOn() { return m_bMouseOn; }
    bool IsLbtnDown() { return m_bLbtnDown; }
    bool IsCamEffected() { return m_bCamAffected; }
    bool isViewEffected() { return m_viewAffected; }
    bool isCanTarget() { return m_canTarget; }

    void SetCamAffected(bool _m_bCamAffected) { m_bCamAffected  = _m_bCamAffected;}
    void SetViewAffected(bool _viewAffected) { m_viewAffected = _viewAffected; }
    void CanTarget(bool _canTarget) { m_canTarget = _canTarget; }
    void AllCanTarget(bool _canTarget);

    void AddChild(UI* _pUI) { m_vecChildUI.push_back(_pUI); _pUI->m_pParentUI = this; }
    vector<UI*>& GetChildUI() { return m_vecChildUI; }

    virtual void update() override;
    virtual void finalupdate() override;
    virtual void render(HDC _dc) override;

    virtual void MouseOn(); // ���콺�� ���� �ö�� ������
    virtual void MouseLbtnUp();
    virtual void MouseLbtnDown();
    virtual void MouseLbtnClicked();

    virtual UI* Clone() = 0;
public :
    UI(bool _bCamAff);
    UI(const UI& _origin);
    virtual ~UI();

    friend class UIMgr;
};

