#pragma once
class Res
{
private :

	wstring strKey;
	wstring strRelativePath;

public :

	void SetKey(const wstring& _strKey) { strKey = _strKey; }
	void SetRelativePath(const wstring& _strPath) { strRelativePath = _strPath; }

	const wstring& GetKey() { return strKey; }
	const wstring& GetRelativePath() { return strRelativePath; }

	Res();
	virtual ~Res();
};

