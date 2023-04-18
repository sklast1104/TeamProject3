#pragma once

#include "Res.h"

class Texture :
	public Res
{
private :

    HDC m_dc;
    HBITMAP m_hBit;
    BITMAP m_bitInfo;

    HBITMAP LoadPNG(const wstring& _filename);
    HBITMAP InvertBitmapHorizontally(HBITMAP hBitmap);

public :
    Texture();
    virtual ~Texture();

    void Load(const wstring& _strFilePath);
    void LoadHorizonTalFlipped(const wstring& _strFilePath);
    void Create(UINT _iWidth, UINT _iHeight);

    UINT Width() { return m_bitInfo.bmWidth; }
    UINT Height() { return m_bitInfo.bmHeight; }
    HDC GetDC() { return m_dc; }
};

