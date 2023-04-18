#pragma once

class Object;
class Texture;

enum class CAM_EFFECT {
	FADE_IN,
	FADE_OUT,
	NONE,
};

struct tCamEffect {
	CAM_EFFECT eEffect;   // 카메라 효과
	float fDuration;    // 효과 최대 진행 시간
	float fCurTime;     // 카메라 효과 현재 진행된 시간
};

class Camera
{
private :
	D3DXVECTOR3 m_vLookAt; // 카메라가 보는 위치
	D3DXVECTOR3 m_vCurLookAt; // 이전위치와 현재위치 보정 위치
	D3DXVECTOR3 m_vPrevLookAt; // 카메라가 보는 이전프레임 위치
	Object* m_pTargetObj; // 카메라 타겟 오브젝트

	D3DXVECTOR3 m_vDiff; // 해상도 중심위치와 카메라 LookAt 간의 차이 값

	float m_fTime; // 타겟을 따라가는데 걸리는 시간
	float m_fSpeed; // 타겟을 따라가는 속도
	float m_fAccTime; // 누적 시간

	list<tCamEffect> m_listCamEffect;
	Texture* m_pVeilTex; // 카메라 가림막 텍스쳐

	bool isShake;

	void CalDiff();
public :

	void init();
	void update();
	void render(HDC _dc);
	void Shake();

	void EnableShake(bool _isEnable) {
		isShake = _isEnable;
	}

	void SetLookAt(D3DXVECTOR3 _vLook) {
		m_vLookAt = _vLook;

		auto diffVec = m_vLookAt - m_vPrevLookAt;
		D3DXVec3Length(&diffVec);
		float fMoveDist = D3DXVec3Length(&diffVec);
		m_fSpeed = fMoveDist / m_fTime;
		m_fAccTime = 0.f;
	}

	void SetCurLookAt(D3DXVECTOR3 _vLook) {
		m_vCurLookAt = _vLook;
		m_vLookAt = _vLook;
	}

	void SetTarget(Object* _pTarget) { m_pTargetObj = _pTarget; }
	D3DXVECTOR3 GetLookAt() { return m_vCurLookAt; }
	D3DXVECTOR3 GetRenderPos(D3DXVECTOR3 _vObjPos) { return _vObjPos - m_vDiff; }
	D3DXVECTOR3 GetRealPos(D3DXVECTOR3 _vRenderPos) { return _vRenderPos + m_vDiff; }

	void FadeIn(float _fDuration) {

		tCamEffect ef = {};
		ef.eEffect = CAM_EFFECT::FADE_IN;
		ef.fDuration = _fDuration;
		ef.fCurTime = 0.f;

		m_listCamEffect.push_back(ef);

		if (0.f == _fDuration) {
			assert(nullptr);
		}
	}
	void FadeOut(float _fDuration) {

		tCamEffect ef = {};
		ef.eEffect = CAM_EFFECT::FADE_OUT;
		ef.fDuration = _fDuration;
		ef.fCurTime = 0.f;

		m_listCamEffect.push_back(ef);

		if (0.f == _fDuration) {
			assert(nullptr);
		};
	}

public :
	SINGLE(Camera)
};

