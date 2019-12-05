// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=x77Rbny5iBA&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=10
#include "AudioManager.h"

//Inicializa la instancia en NULL
AudioManager* AudioManager::sInstance = NULL;

// Regresa un apuntador a la instancia de la clase
AudioManager* AudioManager::Instance() {
	// Crea una instancia si no existia una antes
	if (sInstance == NULL) {
		sInstance = new AudioManager();
	}

	return sInstance;
}

// Libera la instancia de la clase de la memoria
void AudioManager::Release() {
	delete sInstance;
	sInstance = NULL;
}

// Constructor
AudioManager::AudioManager() {
	mAssetMgr = AssetManager::Instance();

	// Inisializa SDL_Mixer usando 44.1 khz y 2 canales, se puede cambiar en caso de ser necesario y manejo de errores
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0) {
		printf("Mixer Initalization Error: %s\n", Mix_GetError());
	}
}

// Destructor
AudioManager::~AudioManager() {
	mAssetMgr = NULL;

	// Cierra SDL_Mixer
	Mix_Quit();
}

// Pone una musica con los loops 1 = infinito, 0 = 1 vez
void AudioManager::PlayMusic(std::string filename, int loops) {
	Mix_PlayMusic(mAssetMgr->GetMusic(filename), loops);
}

// Pausa Musica
void AudioManager::PauseMusic() {
	// Reproduce el archivo del asset manager para que no se vuelva a cargar el archivo
	if (Mix_PlayingMusic() != 0) {
		Mix_PauseMusic();
	}
}

// Raunuda Musica
void AudioManager::ResumeMusic() {
	if (Mix_PausedMusic() != 0) {
		Mix_ResumeMusic();
	}
}

// Pone los efectos de sonido, para poner varios hay que ponerlos en diferentes canales
void AudioManager::PlaySFX(std::string filename, int loops, int channel) {
	// Reproduce el archivo del asset manager para que no se vuelva a cargar el archivo
	Mix_PlayChannel(channel, mAssetMgr->GetSFX(filename), loops);
}
// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=x77Rbny5iBA&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=10