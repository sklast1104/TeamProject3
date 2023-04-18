#pragma once

class Object;
class Animation;
class Texture;

class Animator
{

protected:

	map<wstring, Animation*> m_mapAnim; // 모든 Animation
	Animation* m_pCurAnim; // 현재 Animation
	Object* m_pOwner; // Animation 소유 오브젝트
	bool m_bRepeat;

public:

	Animator();
	virtual ~Animator();

	void CreateAnimation(const wstring& _strName, Texture* _pTex, D3DXVECTOR3 _vLT, D3DXVECTOR3 _vSliceSize, D3DXVECTOR3 _vStep, float _fDuration, UINT _iFrameCount);
	virtual void LoadAnimation(const wstring& _strRelativePath);
	virtual void LoadAnimation(const wstring& _strRelativePath, const wstring& _animName);
	virtual void LoadAnimation(const wstring& _strRelativePath, bool _isHorizontalFlip);
	virtual void LoadAnimation(const wstring& _strRelativePath, bool _isHorizontalFlip, const wstring& _animName);
	virtual void LoadAnimation(const wstring& _strRelativePath, float fDuration);
	virtual void LoadAnimation(const wstring& _strRelativePath, float fDuration, D3DXVECTOR3 fOffset);
	// 좌우 반전된 텍스쳐를 사용하는지
	virtual void LoadAnimation(const wstring& _strRelativePath, float fDuration, D3DXVECTOR3 fOffset, bool _isHorizontalFlip);
	Animation* FindAnimation(const wstring& _strName);
	Animation* GetCurAnimation() { return m_pCurAnim; }
	void Play(const wstring& _strName, bool _bRepeat);

	void update();
	void finalupdate();
	void render(HDC _dc);

	void SetOwnerObject(Object* owner) {
		m_pOwner = owner;
	}

	Object* GetObj() { return m_pOwner; }

	friend class Object;
};

