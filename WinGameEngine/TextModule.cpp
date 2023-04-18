#include "stdafx.h"
#include "TextModule.h"

TextModule::TextModule()
	: lf{}
	, r{255}
	, g{255}
	, b{255}
	, fontSize{10}
	, text{L""}
{
	ZeroMemory(&lf, sizeof(lf));
	lf.lfHeight = fontSize;

	// 기본 폰트 설정
	wcscpy_s(lf.lfFaceName, L"이순신 Bold");

	format = DT_CENTER | DT_VCENTER | DT_SINGLELINE;
}

TextModule::~TextModule()
{
}

void TextModule::render(HDC _dc)
{
	RECT rt = { vLt.x, vLt.y, vLt.x + vScale.x, vLt.y + vScale.y };
	SetBkMode(_dc, TRANSPARENT);
	SetTextColor(_dc, RGB(r, g, b));

	HFONT hFont = CreateFontIndirect(&lf);
	SelectObject(_dc, hFont);

	DrawText(_dc, text.c_str(), -1, &rt, format);

	DeleteObject(hFont);
}

void TextModule::SetBold(UINT _bold)
{
	lf.lfWeight = _bold;
}

void TextModule::SetFont(const wstring& _fontName)
{
	wcscpy_s(lf.lfFaceName, _fontName.c_str());
}

void TextModule::SetSecondFont()
{
	wcscpy_s(lf.lfFaceName, L"이순신 돋움체 M");
}
