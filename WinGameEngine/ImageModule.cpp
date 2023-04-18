#include "stdafx.h"
#include "ImageModule.h"

#include "ResMgr.h"
#include "Texture.h"

ImageModule::ImageModule(const wstring& _resourceKey, const wstring& _relativePath)
	: resourceKey{ _resourceKey }
	, relativePath{ _relativePath }
	, m_pTex{ ResMgr::GetInst()->LoadTexture(_resourceKey, _relativePath) }
	, sourceAlpha{255}
{
}

ImageModule::~ImageModule()
{
}

void ImageModule::Load(const wstring& _resourceKey, const wstring& _relativePath)
{
	resourceKey = _resourceKey;
	relativePath = _relativePath;
	m_pTex = ResMgr::GetInst()->LoadTexture(_resourceKey, _relativePath);
}

void ImageModule::render(HDC _dc)
{
	int texWidth = m_pTex->Width();
	int texHeight = m_pTex->Height();

	// 성능 이슈가 있을수도 있다고 하는데 일단 알파 텍스쳐를 처리하기 위해서
	// 알파블렌드로 렌더링 한다고 가정
	BLENDFUNCTION bf = {};

	bf.BlendOp = AC_SRC_OVER;
	bf.BlendFlags = 0;
	bf.AlphaFormat = AC_SRC_ALPHA;
	bf.SourceConstantAlpha = sourceAlpha;

	AlphaBlend(_dc
		, int(vPos.x)
		, int(vPos.y)
		, int(vScale.x)
		, int(vScale.y)
		, m_pTex->GetDC()
		, 0, 0, texWidth, texHeight
		, bf);
}
