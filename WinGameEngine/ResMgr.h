#pragma once

class Res;
class Texture;

class ResMgr
{
private :

	map<wstring, Res*> m_mapTex;

public :
	Texture* LoadTexture(const wstring& _strKey, const wstring& _strRelativePath);
	Texture* LoadTexture(const wstring& _strKey, const wstring& _strRelativePath, bool _horizontalFlipped);
	Texture* CreateTexutre(const wstring& _strKey, UINT _iWidth, UINT _iHeight);
	Texture* FindTexture(const wstring& _strKey);

public :
	SINGLE(ResMgr);
};

