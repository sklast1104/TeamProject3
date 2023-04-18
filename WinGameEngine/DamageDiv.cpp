#include "stdafx.h"
#include "DamageDiv.h"
#include "TimeMgr.h"

DamageDiv::DamageDiv()
{
    
}

void DamageDiv::update()
{
	DivUI::update();

    if (isMoving)
    {
        elapsedTime += fDT;

        if (elapsedTime >= lerpTime) {
            elapsedTime = lerpTime;
        }

        SetPos(GetPos() + Vec2(0.f, -1.f));

        if (elapsedTime == lerpTime)
        {
            isMoving = false;
            SetCanRend(false);
            elapsedTime = 0.f;
        }
    }
}

void DamageDiv::StartMove()
{
    SetCanRend(true);

    SetPos(originPos);

    if (!isMoving)
    {
        isMoving = true;
        elapsedTime = 0.f;
    }
}
