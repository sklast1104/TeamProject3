#include "stdafx.h"
#include "Animator.h"

#include "Animation.h"

Animator::Animator()
	: m_pOwner{ nullptr }
	, m_pCurAnim{ nullptr }
	, m_bRepeat{ false }
{
}

Animator::~Animator()
{
	Safe_Delete_Map(m_mapAnim);
}

void Animator::CreateAnimation(const wstring& _strName, Texture* _pTex, D3DXVECTOR3 _vLT, D3DXVECTOR3 _vSliceSize, D3DXVECTOR3 _vStep, float _fDuration, UINT _iFrameCount)
{
	Animation* pAnim = FindAnimation(_strName);
	assert(nullptr == pAnim);

	pAnim = new Animation;

	pAnim->SetName(_strName);
	pAnim->SetAnimator(this);
	pAnim->Create(_pTex, _vLT, _vSliceSize, _vStep, _fDuration, _iFrameCount);

	m_mapAnim.insert(make_pair(_strName, pAnim));
}

void Animator::LoadAnimation(const wstring& _strRelativePath)
{
	Animation* pAnim = new Animation;
	pAnim->Load(_strRelativePath);
	pAnim->SetAnimator(this);
	m_mapAnim.insert(make_pair(pAnim->GetName(), pAnim));
}

void Animator::LoadAnimation(const wstring& _strRelativePath, const wstring& _animName)
{
}

void Animator::LoadAnimation(const wstring& _strRelativePath, bool _isHorizontalFlip)
{
}

void Animator::LoadAnimation(const wstring& _strRelativePath, bool _isHorizontalFlip, const wstring& _animName)
{
}

void Animator::LoadAnimation(const wstring& _strRelativePath, float fDuration)
{
}

void Animator::LoadAnimation(const wstring& _strRelativePath, float fDuration, D3DXVECTOR3 fOffset)
{
}

void Animator::LoadAnimation(const wstring& _strRelativePath, float fDuration, D3DXVECTOR3 fOffset, bool _isHorizontalFlip)
{
}

Animation* Animator::FindAnimation(const wstring& _strName)
{
	map<wstring, Animation*>::iterator iter = m_mapAnim.find(_strName);

	if (iter == m_mapAnim.end())
		return nullptr;

	return iter->second;
}

void Animator::Play(const wstring& _strName, bool _bRepeat)
{
	m_pCurAnim = FindAnimation(_strName);
	m_bRepeat = _bRepeat;
}

void Animator::update()
{
}

void Animator::finalupdate()
{
	if (nullptr != m_pCurAnim)
	{
		m_pCurAnim->update();

		if (m_bRepeat && m_pCurAnim->IsFinish()) {
			m_pCurAnim->SetFrame(0);
		}
	}
}

void Animator::render(HDC _dc)
{
	if (nullptr != m_pCurAnim)
		m_pCurAnim->render(_dc);
}
