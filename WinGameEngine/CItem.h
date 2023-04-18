#pragma once
class CItem
{
protected:

	// �̸�, ���ҽ� Ű
	wstring name;
	// �ؽ��� ���
	wstring path;
	// ���� ����
	int curCount;
	// �κ��丮 �� ĭ�� ���� �� �ִ� �ִ� ī��Ʈ
	int maxCount;
	// ������ �ѱ� �̸�
	wstring title;
	// ������ ����
	wstring disc;
	// �� ����
	int rowNum;


public:
	CItem();
	virtual ~CItem();

	void SetName(const wstring& name) { this->name = name; }
	const wstring& GetName() { return name; }

	void SetPath(const wstring& path) { this->path = path; }
	const wstring& GetPath() { return path; }

	int GetCurCount() { return curCount; }
	void SetCurCount(int curCount) { this->curCount = curCount; }

	int GetMaxCount() { return maxCount; }
	void SetMaxCount(int maxCount) { this->maxCount = maxCount; }

	void SetTitle(const wstring& _title) { title = _title; }
	const wstring& GetTitle() { return title; }

	void SetDisc(const wstring& _disc) { disc = _disc; }
	const wstring& GetDisc() { return disc; }

	int GetRowNum() { return rowNum; }
};

