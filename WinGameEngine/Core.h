#pragma once
class Texture;

class Core
{
private :

	HWND m_hWnd;
	POINT m_ptResolution;
	HDC m_hDC;

	Texture* m_pMemTex;

	HBRUSH m_arrBrush[(UINT)BRUSH_TYPE::END];
	HPEN m_arrPen[(UINT)PEN_TYPE::END];

	void CreateBrushPen();
	void Clear();

public :

	int init(HWND _hwnd, POINT _ptResolution);
	void progress();

	HWND GetMainHwnd() { return m_hWnd; }
	HDC GetMainDC() { return m_hDC; }

	POINT GetResolution() { return m_ptResolution; }
	HBRUSH GetBrush(BRUSH_TYPE _eType) { return m_arrBrush[(UINT)_eType]; }
	HPEN GetPen(PEN_TYPE _eType) { return m_arrPen[(UINT)_eType]; }

	void ChangeWindowSize(Vec2 _vResolution, bool _bMenu);

public :
	SINGLE(Core);
};

