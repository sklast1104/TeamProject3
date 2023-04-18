#include "stdafx.h"
#include "CInvItem.h"

CInvItem::CInvItem(const wstring& _name)
	: cost{ 0 }
{
	if (_name == L"food") {
		name = L"food";
		path = L"resource\\items\\provision\\food.png";
		curCount = 1;
		maxCount = 12;
		cost = 75;
		title = L"음식";
		disc = L"음식을 먹으면 허기가\n가시고 체력이\n 회복됩니다. 각\n원정대원은 일반적으로\n식량마다 1의 체력을\n회복합니다.";
		rowNum = 6;
	}
	else if (_name == L"shovel") {
		name = L"shovel";
		path = L"resource\\items\\supply\\shovel.png";
		curCount = 1;
		maxCount = 4;
		cost = 250;
		title = L"삽";
		disc = L"장애물을 치우거나 상자\n등을 억지로 여는 데\n사용됩니다.";
		rowNum = 3;
	}
	else if (_name == L"antidote") {
		name = L"antidote";
		path = L"resource\\items\\supply\\antidote.png";
		curCount = 1;
		maxCount = 6;
		cost = 150;
		title = L"해독제";
		disc = L"역병과 중독, 그리고\n맹독을 치료합니다.";
		rowNum = 2;
	}
	else if (_name == L"band") {
		name = L"band";
		path = L"resource\\items\\supply\\band.png";
		curCount = 1;
		maxCount = 6;
		cost = 150;
		title = L"붕대";
		disc = L"출혈을 막는 데 씁니다.";
		rowNum = 1;
	}
	else if (_name == L"herb") {
		name = L"herb";
		path = L"resource\\items\\supply\\herb.png";
		curCount = 1;
		maxCount = 6;
		cost = 200;
		title = L"약초";
		disc = L"물품을 정화해 각종\n병균을 막는 데\n사용합니다. 영웅에게\n써서 전투 약화 효과를\n제거할 수도 있습니다.";
		rowNum = 5;
	}
	else if (_name == L"key") {
		name = L"key";
		path = L"resource\\items\\supply\\key.png";
		curCount = 1;
		maxCount = 6;
		cost = 200;
		title = L"만능 열쇠";
		disc = L"금고나 문을 열 수\n있습니다.";
		rowNum = 2;
	}
	else if (_name == L"holyWater") {
		name = L"holyWater";
		path = L"resource\\items\\supply\\holyWater.png";
		curCount = 1;
		maxCount = 6;
		cost = 150;
		title = L"성수";
		disc = L"약을 정화하여 정결을\n되찾는 성수입니다.\n영웅에게 사용할 경우\n저항력이 증가합니다.";
		rowNum = 4;
	}
	else if (_name == L"anum") {
		name = L"anum";
		path = L"resource\\items\\supply\\anum.png";
		curCount = 1;
		maxCount = 6;
		cost = 100;
		title = L"아편";
		disc = L"어둠의 공포에 맞서,\n자신의 마음을\n누그려뜨려 바로\n잡아주는 약물입니다.";
		rowNum = 4;
	}
	else if (_name == L"torch") {
		name = L"torch";
		path = L"resource\\items\\supply\\torch.png";
		curCount = 1;
		maxCount = 8;
		cost = 75;
		title = L"횃불";
		disc = L"주위를 밝힙니다.";
		rowNum = 1;
	}
}

CInvItem::~CInvItem()
{
}
