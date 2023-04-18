#pragma once

class Object;
class Texture;

enum class CAM_EFFECT {
	FADE_IN,
	FADE_OUT,
	NONE,
};

struct tCamEffect {
	CAM_EFFECT eEffect;   // ī�޶� ȿ��
	float fDuration;    // ȿ�� �ִ� ���� �ð�
	float fCurTime;     // ī�޶� ȿ�� ���� ����� �ð�
};

class Camera
{
private :
	D3DXVECTOR3 m_vLookAt; // ī�޶� ���� ��ġ
	D3DXVECTOR3 m_vCurLookAt; // ������ġ�� ������ġ ���� ��ġ
	D3DXVECTOR3 m_vPrevLookAt; // ī�޶� ���� ���������� ��ġ
	Object* m_pTargetObj; // ī�޶� Ÿ�� ������Ʈ

	D3DXVECTOR3 m_vDiff; // �ػ� �߽���ġ�� ī�޶� LookAt ���� ���� ��

	float m_fTime; // Ÿ���� ���󰡴µ� �ɸ��� �ð�
	float m_fSpeed; // Ÿ���� ���󰡴� �ӵ�
	float m_fAccTime; // ���� �ð�

	list<tCamEffect> m_listCamEffect;
	Texture* m_pVeilTex; // ī�޶� ������ �ؽ���

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

