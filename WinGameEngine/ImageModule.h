#pragma once

class Texture;

// UI������ ����ϴ� �̹��� �ε��� ����̶�� ����
class ImageModule
{

private :

	Texture* m_pTex;
	wstring resourceKey;
	wstring relativePath;

	// vLT, �̹� �θ�κ��� ����� GetFinalPos�� ���´ٰ� ����
	// ���� ������, ����Ʈ ������ ���� �̹� �����ִٰ� �����Ѵ�
	D3DXVECTOR3 vPos;

	// ũ��
	D3DXVECTOR3 vScale;

	int sourceAlpha;

public :

	ImageModule(const wstring& _resourceKey, const wstring& _relativePath);
	~ImageModule();

	void SetResourceKey(const wstring& _rKey) { resourceKey = _rKey; }

	// Local, World, Camera, Viewport ���� ���� Pos������
	void SetPos(D3DXVECTOR3 _vPos) { vPos = _vPos; }
	// Local, World, Camera, Viewport ���� ���� Scale������
	void SetScale(D3DXVECTOR3 _vScale) { vScale = _vScale; }
	void SetAlpha(int _alpha) { sourceAlpha = _alpha; }

	const wstring& GetResourceKey() const { return resourceKey; }
	const wstring& GetRelativePath() const { return relativePath; }

	void Load(const wstring& _resourceKey, const wstring& _relativePath);

	void render(HDC _dc);
};

