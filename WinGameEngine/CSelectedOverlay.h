#pragma once
#include "UI.h"
class Texture;

class CSelectedOverlay : 
	public UI
{
private :

	Texture* overlayTex;
	bool isGrowing;

	bool canRend;

public :

	CSelectedOverlay();
	~CSelectedOverlay() {}

	virtual void update() override;
	virtual void render(HDC _dc) override;

	void SetCanRend(bool _canRend) { canRend = _canRend; }
	bool GetCanRend() { return canRend; }

	CLONE(CSelectedOverlay);

};

