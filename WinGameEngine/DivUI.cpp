#include "stdafx.h"
#include "DivUI.h"
#include "Camera.h"
#include "Animator.h"
#include "ImageModule.h"
#include "TextModule.h"
#include "CCommand.h"
#include "KeyMgr.h"
#include "ViewMgr.h"

DivUI::DivUI()
	: UI(false)
	, iModule{ nullptr }
	, canRendImg{false}
	, canRendTxt{false}
	, canRend{true}
	, id{0}
	, wasMouseOver{false}
{
}

DivUI::~DivUI()
{
	Safe_Delete<ImageModule*>(iModule);
	Safe_Delete<TextModule*>(tModule);

	Safe_Delete<CCommand*>(onMouseOver);
	Safe_Delete<CCommand*>(onMouseOut);
	Safe_Delete<CCommand*>(onMouseUp);
	Safe_Delete<CCommand*>(onMouseDown);
	Safe_Delete<CCommand*>(onMouseClick);
	Safe_Delete<CCommand*>(onMouseEnter);
	Safe_Delete<CCommand*>(onMouseExit);
	
	Safe_Delete<CCommand*>(onUpdateValue);
}

void DivUI::SetSrcAlpha(int _alpha)
{
	if (nullptr != iModule) {
		iModule->SetAlpha(_alpha);
	}
}

void DivUI::SetTextColor(UINT r, UINT g, UINT b)
{
	if (nullptr != tModule) {
		tModule->SetColor(r, g, b);
	}
}

void DivUI::SetSecondFont()
{
	if (nullptr != tModule) {
		tModule->SetSecondFont();
	}
}

void DivUI::SetFont(const wstring& _fontName)
{
	if (nullptr != tModule) {
		tModule->SetFont(_fontName);
	}
}

void DivUI::SetFormat(UINT _format)
{
	if (nullptr != tModule) {
		tModule->SetFormat(_format);
	}
}

void DivUI::SetBold(UINT _bold)
{
	if (nullptr != tModule) {
		tModule->SetBold(_bold);
	}
}

void DivUI::SetText(const wstring& _text)
{
	if (nullptr != tModule) {
		tModule->SetText(_text);
	}
}

void DivUI::InitImageModule(const wstring& _resourceKey, const wstring& _relativePath)
{
	if (nullptr == iModule) {
		iModule = new ImageModule(_resourceKey, _relativePath);
		canRendImg = true;
	}
	else {
		// 이미 있을경우
		iModule->Load(_resourceKey, _relativePath);
	}
}

void DivUI::InitTextModule(const wstring& _text, const UINT _textSize)
{
	if (nullptr == tModule) {
		tModule = new TextModule;
		tModule->SetText(_text);
		tModule->SetTextSize(_textSize);
		canRendTxt = true;
	}
	else {
		tModule->SetText(_text);
		tModule->SetTextSize(_textSize);
		canRendTxt = true;
	}
}

void DivUI::InitTextModule(int _text, const UINT _textSize)
{
	if (nullptr == tModule) {
		tModule = new TextModule;
		tModule->SetText(to_wstring(_text));
		tModule->SetTextSize(_textSize);
		canRendTxt = true;
	}
	else {
		tModule->SetText(to_wstring(_text));
		tModule->SetTextSize(_textSize);
		canRendTxt = true;
	}
}

void DivUI::render(HDC _dc)
{
	if (!canRend) return;


	if (canRendImg) {

		D3DXVECTOR3 vPos = GetFinalPos();
		D3DXVECTOR3 vScale = GetScale();

		if (IsCamEffected()) {
			// View 변환 실행
			// 카메라 영향을 받지 않는다면 항상 같은위치에 렌더링된다(일반적으로 생각하는 UI이다)
			vPos = Camera::GetInst()->GetRenderPos(vPos);
		}

		iModule->SetPos(vPos);
		iModule->SetScale(vScale);
		iModule->render(_dc);
	}

	if (canRendTxt) {

		D3DXVECTOR3 vPos = GetFinalPos();
		D3DXVECTOR3 vScale = GetScale();

		if (IsCamEffected()) {
			// View 변환 실행
			// 카메라 영향을 받지 않는다면 항상 같은위치에 렌더링된다(일반적으로 생각하는 UI이다)
			vPos = Camera::GetInst()->GetRenderPos(vPos);
		}

		tModule->SetLt(vPos);
		tModule->SetScale(vScale);
		tModule->render(_dc);
	}

	ComponentRender(_dc);

	UI::render(_dc);
}

void DivUI::LoadAnimation(const wstring& _animName, const wstring& _atlasPath)
{
	if (nullptr != GetAnimator()) {
		GetAnimator()->LoadAnimation(_atlasPath, _animName);
		GetAnimator()->Play(_animName, true);
	}	
}

void DivUI::LoadAnimation(const wstring& _animName, const wstring& _atlasPath, bool _isLoop)
{
	if (nullptr != GetAnimator()) {
		GetAnimator()->LoadAnimation(_atlasPath, _animName);
		GetAnimator()->Play(_animName, _isLoop);
	}
}

void DivUI::update()
{
	UI::update();

	// 렌더좌표인데 카메라 정방향 or 카메라 영향을 받지 않는 UI면 상관없음
	D3DXVECTOR3 mousePos = MOUSE_POS;

	D3DXVECTOR3 myScale = GetScale();
	D3DXVECTOR3 finalPos = GetFinalPos();

	bool isMouseOver = (finalPos.x <= mousePos.x && mousePos.x <= finalPos.x + myScale.x
		&& finalPos.y <= mousePos.y && mousePos.y <= finalPos.y + myScale.y);

	if (isMouseOver && !wasMouseOver) {

		wasMouseOver = true;
		// 마우스 엔터 이벤트 호출!
		if (nullptr != onMouseEnter) {
			onMouseEnter->Execute();
		}
	}

	if (!isMouseOver && wasMouseOver) {
		wasMouseOver = false;
		// 마우스 익시트 이벤트 호출!
		if (nullptr != onMouseExit) {
			onMouseExit->Execute();
		}
	}

	if (isMouseOver) {
		// 마우스 오버 이벤트 호출!
		if (nullptr != onMouseOver) {
			onMouseOver->Execute();
		}
	}
	else {
		// 마우스 낫 오버 이벤트 호출!
		if (nullptr != onMouseOut) {
			onMouseOut->Execute();
		}
	}


	//if (finalPos.x <= mousePos.x && mousePos.x <= finalPos.x + myScale.x
	//	&& finalPos.y <= mousePos.y && mousePos.y <= finalPos.y + myScale.y) {
	//	
	//	if (nullptr != onMouseOver) {
	//		onMouseOver->Execute();
	//	}

	//}
	//else {

	//	if (nullptr != onMouseOut) {
	//		onMouseOut->Execute();
	//	}		
	//}
}

void DivUI::MouseOn()
{
	if (nullptr != onMouseOver) {
		onMouseOver->Execute();
	}
}

void DivUI::MouseLbtnUp()
{
	if (nullptr != onMouseUp) {
		onMouseUp->Execute();
	}
}

void DivUI::MouseLbtnDown()
{
	if (nullptr != onMouseDown) {
		onMouseDown->Execute();
	}
}

void DivUI::MouseLbtnClicked()
{
	if (nullptr != onMouseClick) {
		onMouseClick->Execute();
	}
}

void DivUI::updateValue()
{
	if (nullptr != onUpdateValue) {
		onUpdateValue->Execute();
	}
}

void DivUI::SendToBack(const wstring& _name)
{
	vector<UI*>& vec = GetChildUI();

	auto it = std::find_if(vec.begin(), vec.end(), [&](UI* obj) {
		return obj->GetName() == _name;
		});

	if (it != vec.end()) {
		std::rotate(it, it + 1, vec.end());
	}
}
