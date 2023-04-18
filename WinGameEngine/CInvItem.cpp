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
		title = L"����";
		disc = L"������ ������ ��Ⱑ\n���ð� ü����\n ȸ���˴ϴ�. ��\n��������� �Ϲ�������\n�ķ����� 1�� ü����\nȸ���մϴ�.";
		rowNum = 6;
	}
	else if (_name == L"shovel") {
		name = L"shovel";
		path = L"resource\\items\\supply\\shovel.png";
		curCount = 1;
		maxCount = 4;
		cost = 250;
		title = L"��";
		disc = L"��ֹ��� ġ��ų� ����\n���� ������ ���� ��\n���˴ϴ�.";
		rowNum = 3;
	}
	else if (_name == L"antidote") {
		name = L"antidote";
		path = L"resource\\items\\supply\\antidote.png";
		curCount = 1;
		maxCount = 6;
		cost = 150;
		title = L"�ص���";
		disc = L"������ �ߵ�, �׸���\n�͵��� ġ���մϴ�.";
		rowNum = 2;
	}
	else if (_name == L"band") {
		name = L"band";
		path = L"resource\\items\\supply\\band.png";
		curCount = 1;
		maxCount = 6;
		cost = 150;
		title = L"�ش�";
		disc = L"������ ���� �� ���ϴ�.";
		rowNum = 1;
	}
	else if (_name == L"herb") {
		name = L"herb";
		path = L"resource\\items\\supply\\herb.png";
		curCount = 1;
		maxCount = 6;
		cost = 200;
		title = L"����";
		disc = L"��ǰ�� ��ȭ�� ����\n������ ���� ��\n����մϴ�. ��������\n�Ἥ ���� ��ȭ ȿ����\n������ ���� �ֽ��ϴ�.";
		rowNum = 5;
	}
	else if (_name == L"key") {
		name = L"key";
		path = L"resource\\items\\supply\\key.png";
		curCount = 1;
		maxCount = 6;
		cost = 200;
		title = L"���� ����";
		disc = L"�ݰ� ���� �� ��\n�ֽ��ϴ�.";
		rowNum = 2;
	}
	else if (_name == L"holyWater") {
		name = L"holyWater";
		path = L"resource\\items\\supply\\holyWater.png";
		curCount = 1;
		maxCount = 6;
		cost = 150;
		title = L"����";
		disc = L"���� ��ȭ�Ͽ� ������\n��ã�� �����Դϴ�.\n�������� ����� ���\n���׷��� �����մϴ�.";
		rowNum = 4;
	}
	else if (_name == L"anum") {
		name = L"anum";
		path = L"resource\\items\\supply\\anum.png";
		curCount = 1;
		maxCount = 6;
		cost = 100;
		title = L"����";
		disc = L"����� ������ �¼�,\n�ڽ��� ������\n���׷��߷� �ٷ�\n����ִ� �๰�Դϴ�.";
		rowNum = 4;
	}
	else if (_name == L"torch") {
		name = L"torch";
		path = L"resource\\items\\supply\\torch.png";
		curCount = 1;
		maxCount = 8;
		cost = 75;
		title = L"ȶ��";
		disc = L"������ �����ϴ�.";
		rowNum = 1;
	}
}

CInvItem::~CInvItem()
{
}
