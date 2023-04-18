#pragma once

#include "UI.h"

class ImageModule;
class TextModule;
class CCommand;

class DivUI :
	public UI
{
private :
	
	ImageModule* iModule;
	TextModule* tModule;

	bool canRendImg;
	bool canRendTxt;
	bool canRend;
	bool wasMouseOver;

protected :

	CCommand* onMouseOver;
	CCommand* onMouseOut;
	CCommand* onMouseUp;
	CCommand* onMouseDown;
	CCommand* onMouseClick;
	CCommand* onMouseEnter;
	CCommand* onMouseExit;

	CCommand* onUpdateValue;

	int id;

public :

	DivUI();
	~DivUI();

	void SetId(int _id) { id = _id; }
	int GetId() { return id; }

	void SetCanRendImg(bool _canRendImg) { canRendImg = _canRendImg; }
	void SetCanRendTxt(bool _canRendTxt) { canRendTxt = _canRendTxt; }
	void SetCanRend(bool _canRend) { canRend = _canRend; }

	bool GetCanRend() { return canRend; }
	bool GetCanRendImg() { return canRendImg; }
	bool GetCanRendTxt() { return canRendTxt; }

	void SetSrcAlpha(int _alpha);
	void SetTextColor(UINT r, UINT g, UINT b);
	void SetSecondFont();
	void SetFont(const wstring& _fontName);
	void SetFormat(UINT _format);
	void SetBold(UINT _bold);
	void SetText(const wstring& _text);

	void InitImageModule(const wstring& _resourceKey, const wstring& _relativePath);
	void InitTextModule(const wstring& _text, const UINT _textSize);
	void InitTextModule(int _text, const UINT _textSize);

	ImageModule* GetIModule() { return iModule; }
	TextModule* GetTModule() { return tModule; }

	void InitOnMouseOver(CCommand* _onMouseOver) { onMouseOver = _onMouseOver; }
	void InitOnMouseOut(CCommand* _onMouseOut) { onMouseOut = _onMouseOut; }
	void InitOnMouseUp(CCommand* _onMouseUp) { onMouseUp = _onMouseUp; }
	void InitOneMouseDown(CCommand* _onMouseDown) { onMouseDown = _onMouseDown; }
	void InitOnMouseClick(CCommand* _onMouseClick) { onMouseClick = _onMouseClick; }
	void InitOnMouseEnter(CCommand* _onMouseEnter) { onMouseEnter = _onMouseEnter; }
	void InitOnMouseExit(CCommand* _onMouseExit) { onMouseExit = _onMouseExit; }

	void InitUpdateValue(CCommand* _onUpdateValue) { onUpdateValue = _onUpdateValue; }

	virtual void render(HDC _dc) override;

	void LoadAnimation(const wstring& _animName, const wstring& _atlasPath);
	void LoadAnimation(const wstring& _animName, const wstring& _atlasPath, bool _isLoop);

	virtual void update() override;
	virtual void MouseOn() override;
	virtual void MouseLbtnUp() override;
	virtual void MouseLbtnDown() override;
	virtual void MouseLbtnClicked() override;

	virtual void updateValue();

	void SendToBack(const wstring& _name);

	CLONE(DivUI);
};

