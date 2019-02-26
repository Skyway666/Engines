#ifndef __ModuleAudio_H__
#define __ModuleAudio_H__

#include "Module.h"
#include <list>
#include <string>

#define DEFAULT_MUSIC_FADE_TIME 2.0f

enum AudioType { A_UNKNOWN, MUSIC, FX};

class AudioFile
{
	friend class ModuleAudio;
	friend class ModuleUI;
public:
	AudioFile(const char* name, uint id, void* data, AudioType type, float volume = 1.0f, float fade_time = DEFAULT_MUSIC_FADE_TIME)
		: name(name), data(data), type(type), volume(volume), fade_time(fade_time), id(id) {};
	~AudioFile();

	void Play(uint repeat = 0);
	void Stop();

	void setName(const char* new_name)	{ name = new_name; };
	void setVolume(uint v)				{ volume = v; };
	void setFadeTime(float f_t)			{ fade_time = f_t; };

private:

	const uint id		= 0;
	uint channel		= 0;
	AudioType type		= A_UNKNOWN;
	float volume		= 1.0f;
	float fade_time		= DEFAULT_MUSIC_FADE_TIME;

	void* data			= nullptr;
	std::string name;

};

class ModuleAudio : public Module
{
	friend class ModuleUI;
public:


	ModuleAudio(Application* app, bool start_enabled = true);
	~ModuleAudio();

	bool Init(const JSON_Object& config);
	bool CleanUp();

	AudioFile* LoadAudio(const char* path, const char* name, AudioType type);
	void Play(uint id, uint repeat = 0) const;   // music always plays in loop, regardless of the value of repeat arg.
	void Play(const char* name, uint repeat = 0) const; // music always plays in loop, regardless of the value of repeat arg.

	void setMasterVolume(uint volume);
	void setMasterMusicVolume(uint volume);
	float getMasterVolume()	const		{ return master_volume; };
	float getsetMasterMusicVolume()	const { return music_volume; };

	void HaltMusic();

private:

	float master_volume	= 1.0f;	 // _seriazible_var
	float music_volume	= 1.0f;	 // _seriazible_var

	std::list<AudioFile*> audio_files;
	uint last_audio_id = 0;
};

#endif // __ModuleAudio_H__