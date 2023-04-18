#pragma once
class CItem
{
protected:

	// 이름, 리소스 키
	wstring name;
	// 텍스쳐 경로
	wstring path;
	// 현재 개수
	int curCount;
	// 인벤토리 한 칸에 들어올 수 있는 최대 카운트
	int maxCount;
	// 아이템 한글 이름
	wstring title;
	// 아이템 설명
	wstring disc;
	// 행 개수
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

