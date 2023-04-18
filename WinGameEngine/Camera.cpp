#include "stdafx.h"
#include "Camera.h"

#include "Core.h"
#include "ResMgr.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "ViewMgr.h"

#include "Object.h"
#include "Texture.h"

Camera::Camera()
	: m_pTargetObj{ nullptr }
	, m_fTime{0.3f }
	, m_fSpeed(0.f)
	, m_fAccTime(0.5f)
	, m_pVeilTex(nullptr)
	, isShake{false}
{

}

Camera::~Camera() {

}

void Camera::init()
{
	Vec2 vResolution = Core::GetInst()->GetResolution();

	m_vLookAt = D3DXVECTOR3(960.f, 540.f, 0.f);

	m_pVeilTex = ResMgr::GetInst()->CreateTexutre(L"CameraVeil", (UINT)vResolution.x, (UINT)vResolution.y);
}

void Camera::update()
{
	if (m_pTargetObj) {

		if (m_pTargetObj->isDead()) {
			m_pTargetObj = nullptr;
		}
		else {
			m_vLookAt = m_pTargetObj->GetPos();
		}
	}

	if (KEY_HOLD(KEY::UP))
		m_vLookAt.y -= 500.f * fDT;
	if (KEY_HOLD(KEY::DOWN))
		m_vLookAt.y += 500.f * fDT;
	if (KEY_HOLD(KEY::LEFT))
		m_vLookAt.x -= 500.f * fDT;
	if (KEY_HOLD(KEY::RIGHT))
		m_vLookAt.x += 500.f * fDT;

	// 화면 중앙좌표와 카메라 LookAt 좌표간의 차이값 계산
	if (isShake) {
		Shake();
	}
	
	CalDiff();
}

void Camera::render(HDC _dc)
{
	if (m_listCamEffect.empty())
		return;

	// 시간 누적값을 체크해서
	tCamEffect& effect = m_listCamEffect.front();
	effect.fCurTime += fDT;

	float fRatio = 0.f;
	fRatio = effect.fCurTime / effect.fDuration;

	if (fRatio < 0.f)
		fRatio = 0.f;
	if (fRatio > 1.f)
		fRatio = 1.f;

	int iAlpha = 0;

	if (CAM_EFFECT::FADE_OUT == effect.eEffect) {

		iAlpha = (int)(255.f * fRatio);

	}
	else if (CAM_EFFECT::FADE_IN == effect.eEffect) {
		iAlpha = (int)(255.f * (1.f - fRatio));
	}

	BLENDFUNCTION bf = {};

	bf.BlendOp = AC_SRC_OVER;
	bf.BlendFlags = 0;
	bf.AlphaFormat = 0;
	bf.SourceConstantAlpha = iAlpha;

	AlphaBlend(_dc
		, 0
		, 0
		, (int)m_pVeilTex->Width(), (int)m_pVeilTex->Height()
		, m_pVeilTex->GetDC()
		, 0, 0, int(m_pVeilTex->Width()), int(m_pVeilTex->Height())
		, bf);

	// 진행 시간이 이펙트 최대 지정시간을 넘어선 경우
	if (effect.fDuration < effect.fCurTime) {
		m_listCamEffect.pop_front();
	}
}

void Camera::Shake()
{
	int shakeAmount = 3;
	int shakeX = rand() % (2 * shakeAmount + 1) - shakeAmount;
	//int shakeY = rand() % (2 * shakeAmount + 1) - shakeAmount;

	m_vCurLookAt = m_vCurLookAt + D3DXVECTOR3(shakeX, 0, 0);
	m_vLookAt = m_vCurLookAt + D3DXVECTOR3(shakeX, 0 , 0);

}

void Camera::CalDiff()
{
	// 이전 LookAt과 현재 Look의 차이값을 보정해서 현재의 LookAt 을 구한다

	m_fAccTime += fDT;

	if (m_fTime <= m_fAccTime) {
		//m_vCurLookAt = ViewMgr::GetInst()->GetViewPortPos( m_vLookAt );
		m_vCurLookAt = m_vLookAt;
	}
	else {
		D3DXVECTOR3 vLookDir = m_vLookAt - m_vPrevLookAt;

		//if (!vLookDir.IsZero()) {
		//	m_vCurLookAt = m_vPrevLookAt + vLookDir.Normalize() * m_fSpeed * fDT;
		//}
	}

	Vec2 vResolution = Core::GetInst()->GetResolution();

	//Vec2 vCenter = ViewMgr::GetInst()->GetViewPortPos(vResolution / 2);
	D3DXVECTOR3 vCenter = D3DXVECTOR3(vResolution.x / 2.f, vResolution.y / 2.f, 0.f);

	m_vDiff = m_vCurLookAt - vCenter;
	m_vPrevLookAt = m_vCurLookAt;
}
