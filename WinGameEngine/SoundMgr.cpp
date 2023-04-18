#include "stdafx.h"
#include "SoundMgr.h"

SoundMgr::SoundMgr() {

}

SoundMgr::~SoundMgr() {

}

void SoundMgr::Init()
{
	// 사운드를 담당하는 대표객체를 생성하는 함수
	FMOD_System_Create(&m_pSystem, FMOD_VERSION);

	// 1. 시스템 포인터, 2. 사용할 가상채널 수 , 초기화 방식) 
	FMOD_System_Init(m_pSystem, 32, FMOD_INIT_NORMAL, NULL);

	//LoadSoundFile(L"../Sound/Success.wav");
	LoadSoundsInFolder(L"..\\Sound");
}

void SoundMgr::PlaySound(wstring pSoundKey, CHANNEL eID, float fVolume)
{
	unordered_map<wstring, FMOD_SOUND*>::iterator iter = m_mapSound.find(pSoundKey);

	if (iter == m_mapSound.end()) return;

	FMOD_BOOL bPlay = FALSE;

	if (FMOD_Channel_IsPlaying(m_pChannelArr[eID], &bPlay))
	{
		FMOD_System_PlaySound(m_pSystem, iter->second, nullptr, false, &m_pChannelArr[eID]);
	}

	FMOD_Channel_SetVolume(m_pChannelArr[eID], fVolume);

	FMOD_System_Update(m_pSystem);
}

void SoundMgr::PlayBGM(wstring pSoundKey, float fVolume)
{
	unordered_map<wstring, FMOD_SOUND*>::iterator iter = m_mapSound.find(pSoundKey);

	if (iter == m_mapSound.end()) return;

	FMOD_System_PlaySound(m_pSystem, iter->second, nullptr, false, &m_pChannelArr[SOUND_BGM]);
	FMOD_Channel_SetMode(m_pChannelArr[SOUND_BGM], FMOD_LOOP_NORMAL);
	FMOD_Channel_SetVolume(m_pChannelArr[SOUND_BGM], fVolume);
	FMOD_System_Update(m_pSystem);
}

void SoundMgr::StopSound(CHANNEL eID)
{
	FMOD_Channel_Stop(m_pChannelArr[eID]);
}

void SoundMgr::StopAll()
{
	for (int i = 0; i < CHANNEL::END; ++i)
		FMOD_Channel_Stop(m_pChannelArr[i]);
}

void SoundMgr::SetChannelVolume(CHANNEL eID, float fVolume)
{
	FMOD_Channel_SetVolume(m_pChannelArr[eID], fVolume);

	FMOD_System_Update(m_pSystem);
}

void SoundMgr::LoadSoundFile(const std::wstring& filePath)
{
	std::string path = ConvertToString(filePath);

	FMOD_SOUND* pSound = nullptr;
	FMOD_RESULT eRes = FMOD_System_CreateSound(m_pSystem, path.c_str(), FMOD_DEFAULT, 0, &pSound);

	if (eRes == FMOD_OK)
	{
		m_mapSound.emplace(filePath, pSound);
	}
}

void SoundMgr::LoadSoundsInFolder(const std::wstring& folderPath)
{
	//// 폴더 경로를 파일 시스템 경로로 변환

	string stpath = ConvertToString(folderPath);

	if (!std::filesystem::exists(stpath))
	{
		std::cerr << "Sound file not found: " << stpath << std::endl;
		return;
	}

	//string stpath = "../Sound";

	fs::path folder(stpath);

	// 폴더 안에 있는 모든 파일들의 경로를 얻는다
	for (const auto& entry : fs::directory_iterator(folder))
	{
		// 파일 경로에서 확장자를 추출하여 WAV 파일인지 검사한다
		if (entry.path().extension() == ".wav")
		{
			// WAV 파일을 로드한다
			LoadSoundFile(entry.path().wstring());
		}
	}
}

string SoundMgr::ConvertToString(wstring wstr)
{
	int length = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), static_cast<int>(wstr.length()), nullptr, 0, nullptr, nullptr);
	std::string str(length, 0);
	WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), static_cast<int>(wstr.length()), &str[0], length, nullptr, nullptr);
	return str;
}
