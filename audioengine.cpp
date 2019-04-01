#include "stdafx.h"
#include "audioengine.h"

void SoundEffect::play(int loops)
{
  if (Mix_PlayChannel(-1, _chunk, loops) == -1)
    {
      if (Mix_PlayChannel(0, _chunk, loops) == -1)
	{
	  fatalError("Mix PlayChannel Error " + std::string(Mix_GetError()));
	}
    }
}

void Music::play(int loops)
{
  Mix_PlayMusic(_music, loops);
}

void Music::pause()
{
  Mix_PauseMusic();
}
void Music::stop()
{
  Mix_HaltMusic();
}
void Music::resume()
{
  Mix_ResumeMusic();
}

bool AudioEngine::_initialized = false;
AudioEngine::AudioEngine()
{
}

AudioEngine::~AudioEngine()
{
  destroy();
}

void AudioEngine::init()
{
  if (_initialized)
    {
      fatalError("initialized twice ");
    }

  if (Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG) == -1)
    {
      fatalError("Mix Init Error "+std::string(Mix_GetError()));
    }
  if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
    {
      fatalError("Mix Init Error " + std::string(Mix_GetError()));
    }
  _initialized = true;
}
void AudioEngine::destroy()
{
  for (std::map<std::string, Mix_Chunk*>::iterator itr = _effectMap.begin();
       itr != _effectMap.end(); itr++)
    {
      Mix_FreeChunk(itr->second);
    }
  for (std::map<std::string, Mix_Music*>::iterator itr = _musicMap.begin();
       itr != _musicMap.end(); itr++)
    {
      Mix_FreeMusic(itr->second);
    }
  if (_initialized)
    {		
      Mix_CloseAudio();
      Mix_Quit();
    }
  _initialized = false;
}

SoundEffect AudioEngine::loadSoundEffect(const std::string& filePath)
{
  SoundEffect effect;

  std::map<std::string, Mix_Chunk*>::iterator itr = _effectMap.find(filePath);
  if (itr == _effectMap.end()){
    Mix_Chunk* chunk = Mix_LoadWAV(filePath.c_str());
    if (chunk == NULL){
      fatalError("Mix LoadWAV Error " + std::string(Mix_GetError()));
    }
    _effectMap[filePath] = chunk;

    effect._chunk = chunk;
    return effect;
  }
  else{
    effect._chunk = itr->second;
    return effect;
  }
}

Music AudioEngine::loadMusic(const std::string& filePath)
{
  Music effect;

  std::map<std::string, Mix_Music*>::iterator itr = _musicMap.find(filePath);
  if (itr == _musicMap.end()){
    Mix_Music* chunk = Mix_LoadMUS(filePath.c_str());
    if (chunk == NULL){
      fatalError("Mix LoadMUS Error " + std::string(Mix_GetError()));
    }
    _musicMap[filePath] = chunk;

    effect._music = chunk;
    return effect;
  }
  else{
    effect._music = itr->second;
    return effect;
  }
}
