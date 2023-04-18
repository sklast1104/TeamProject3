#pragma once

class Texture;

// UI에서만 사용하는 이미지 로딩용 모듈이라고 가정
class ImageModule
{

private :

	Texture* m_pTex;
	wstring resourceKey;
	wstring relativePath;

	// vLT, 이미 부모로부터 계산한 GetFinalPos가 들어온다고 가정
	// 렌더 포지션, 뷰포트 포지션 또한 이미 계산되있다고 가정한다
	D3DXVECTOR3 vPos;

	// 크기
	D3DXVECTOR3 vScale;

	int sourceAlpha;

public :

	ImageModule(const wstring& _resourceKey, const wstring& _relativePath);
	~ImageModule();

	void SetResourceKey(const wstring& _rKey) { resourceKey = _rKey; }

	// Local, World, Camera, Viewport 전부 끝난 Pos여야함
	void SetPos(D3DXVECTOR3 _vPos) { vPos = _vPos; }
	// Local, World, Camera, Viewport 전부 끝난 Scale여야함
	void SetScale(D3DXVECTOR3 _vScale) { vScale = _vScale; }
	void SetAlpha(int _alpha) { sourceAlpha = _alpha; }

	const wstring& GetResourceKey() const { return resourceKey; }
	const wstring& GetRelativePath() const { return relativePath; }

	void Load(const wstring& _resourceKey, const wstring& _relativePath);

	void render(HDC _dc);
};

