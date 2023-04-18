#include "stdafx.h"
#include "CSkill.h"

CSkill::CSkill()
	: skillName{ L"" }
	, skillPath{ L"" }
	, skillRange{}
	, skillPos{}
	, hitRate{ 0 }
	, multiAttack{false}
	, isAlive{false}
	, skilRealAnimName{L""}
	, skilRealAnimPath{L""}
{
}

CSkill::~CSkill()
{
}
