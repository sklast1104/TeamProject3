#pragma once
class SoundMgr
{
private :

	unordered_map<wstring, FMOD_SOUND*> m_mapSound;

	FMOD_CHANNEL* m_pChannelArr[CHANNEL::END];

	FMOD_SYSTEM* m_pSystem;

	void LoadSoundFile(const std::wstring& filePath);
	void LoadSoundsInFolder(const std::wstring& folderPath);

	string ConvertToString(wstring _wstr);

public :

	void Init();
	void PlaySound(wstring pSoundKey, CHANNEL eID, float fVolume);
	void PlayBGM(wstring pSoundKey, float fVolume);
	void StopSound(CHANNEL eID);
	void StopAll();
	void SetChannelVolume(CHANNEL eID, float fVolume);
	

public :
	SINGLE(SoundMgr);
};

