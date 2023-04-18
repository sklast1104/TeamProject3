#include "stdafx.h"
#include "Texture.h"

#include "Core.h"

Texture::Texture()
	: m_hBit(0)
	, m_dc(0)
	, m_bitInfo{}
{
}

Texture::~Texture()
{
	DeleteDC(m_dc);
	DeleteObject(m_hBit);
}

HBITMAP Texture::LoadPNG(const wstring& _filename)
{
	using namespace Gdiplus;

	ULONG_PTR gdiplusToken;

	GdiplusStartupInput gdiplusStartupInput;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	Image* image = Image::FromFile(_filename.c_str());

	assert(image);

	Bitmap* pBitmap = static_cast<Bitmap*>(image->Clone());
	HBITMAP hBitmap = NULL;
	Status status = pBitmap->GetHBITMAP(Color(0, 0, 0), &hBitmap);

	GdiplusShutdown(gdiplusToken);

	return hBitmap;
}

HRESULT CreateHBITMAPFromWICBitmap(IWICImagingFactory* pFactory, IWICBitmapSource* pBitmapSource, HBITMAP* phBitmap)
{
	UINT width = 0, height = 0;
	pBitmapSource->GetSize(&width, &height);

	BITMAPINFO bmi = { 0 };
	bmi.bmiHeader.biSize = sizeof(bmi.bmiHeader);
	bmi.bmiHeader.biWidth = width;
	bmi.bmiHeader.biHeight = (LONG)height;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biCompression = BI_RGB;

	BYTE* pBits = NULL;
	HDC hDC = GetDC(NULL);
	*phBitmap = CreateDIBSection(hDC, &bmi, DIB_RGB_COLORS, (void**)&pBits, NULL, 0);
	ReleaseDC(NULL, hDC);
	if (*phBitmap == NULL) {
		return E_FAIL;
	}

	const UINT cbStride = width * 4;
	const UINT cbBufferSize = cbStride * height;
	BYTE* pBuffer = new BYTE[cbBufferSize];
	if (pBuffer == NULL) {
		DeleteObject(*phBitmap);
		*phBitmap = NULL;
		return E_OUTOFMEMORY;
	}

	HRESULT hr = pBitmapSource->CopyPixels(NULL, cbStride, cbBufferSize, pBuffer);
	if (FAILED(hr)) {
		DeleteObject(*phBitmap);
		*phBitmap = NULL;
		delete[] pBuffer;
		return hr;
	}

	BYTE* pDest = pBits;
	BYTE* pSrc = pBuffer + (height - 1) * cbStride;
	for (UINT y = 0; y < height; ++y) {
		memcpy(pDest, pSrc, cbStride);
		pDest += cbStride;
		pSrc -= cbStride;
	}

	delete[] pBuffer;
	return S_OK;
}

HBITMAP Texture::InvertBitmapHorizontally(HBITMAP hBitmap)
{
	// 이미지를 읽어들이기 위한 WIC 인코더 및 비트맵 개체 생성
	IWICImagingFactory* pFactory = NULL;
	HRESULT hr = CoCreateInstance(CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER, IID_IWICImagingFactory, (LPVOID*)&pFactory);
	if (FAILED(hr)) {
		return NULL;
	}

	IWICBitmap* pWicBitmap = NULL;
	hr = pFactory->CreateBitmapFromHBITMAP(hBitmap, NULL, WICBitmapUseAlpha, &pWicBitmap);
	if (FAILED(hr)) {
		pFactory->Release();
		return NULL;
	}

	// 좌우 반전을 수행하기 위한 IWICBitmapFlipRotator 인터페이스 개체 생성
	IWICBitmapFlipRotator* pFlipRotator = NULL;
	hr = pFactory->CreateBitmapFlipRotator(&pFlipRotator);
	if (FAILED(hr)) {
		pWicBitmap->Release();
		pFactory->Release();
		return NULL;
	}

	// 좌우 반전을 수행합니다.
	hr = pFlipRotator->Initialize(pWicBitmap, WICBitmapTransformFlipHorizontal);
	if (FAILED(hr)) {
		pFlipRotator->Release();
		pWicBitmap->Release();
		pFactory->Release();
		return NULL;
	}

	// 좌우 반전된 비트맵을 HBITMAP으로 변환합니다.
	HBITMAP hFlippedBitmap = NULL;
	hr = CreateHBITMAPFromWICBitmap(pFactory, pFlipRotator, &hFlippedBitmap);
	if (FAILED(hr)) {
		pFlipRotator->Release();
		pWicBitmap->Release();
		pFactory->Release();
		return NULL;
	}

	// 인터페이스 객체들 해제
	pFlipRotator->Release();
	pWicBitmap->Release();
	pFactory->Release();

	return hFlippedBitmap;
}

void Texture::Load(const wstring& _strFilePath)
{
	std::string fn(_strFilePath.begin(), _strFilePath.end());
	std::string ext = fn.substr(fn.find_last_of(".") + 1);

	if (ext == "bmp") {
		m_hBit = (HBITMAP)LoadImage(nullptr, _strFilePath.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
	}
	else if (ext == "png") {
		m_hBit = LoadPNG(_strFilePath);
	}

	assert(m_hBit);

	m_dc = CreateCompatibleDC(Core::GetInst()->GetMainDC());

	HBITMAP hPrevBit = (HBITMAP)SelectObject(m_dc, m_hBit);
	DeleteObject(hPrevBit);

	GetObject(m_hBit, sizeof(BITMAP), &m_bitInfo);
}

void Texture::LoadHorizonTalFlipped(const wstring& _strFilePath)
{
	std::string fn(_strFilePath.begin(), _strFilePath.end());
	std::string ext = fn.substr(fn.find_last_of(".") + 1);

	if (ext == "bmp") {
		m_hBit = (HBITMAP)LoadImage(nullptr, _strFilePath.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
	}
	else if (ext == "png") {
		m_hBit = LoadPNG(_strFilePath);
	}

	//m_hBit = (HBITMAP) LoadImage(nullptr, _strFilePath.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	assert(m_hBit);

	m_hBit = InvertBitmapHorizontally(m_hBit);

	m_dc = CreateCompatibleDC(Core::GetInst()->GetMainDC());

	HBITMAP hPrevBit = (HBITMAP)SelectObject(m_dc, m_hBit);
	DeleteObject(hPrevBit);

	GetObject(m_hBit, sizeof(BITMAP), &m_bitInfo);
}

void Texture::Create(UINT _iWidth, UINT _iHeight)
{
	HDC maindc = Core::GetInst()->GetMainDC();

	m_hBit = CreateCompatibleBitmap(maindc, _iWidth, _iHeight);
	m_dc = CreateCompatibleDC(maindc);

	HBITMAP hOldBit = (HBITMAP)SelectObject(m_dc, m_hBit);
	DeleteObject(hOldBit);

	//비트맵 정보
	GetObject(m_hBit, sizeof(BITMAP), &m_bitInfo);
}
