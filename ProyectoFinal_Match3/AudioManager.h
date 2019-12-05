// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=x77Rbny5iBA&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=10
#ifndef _AUDIOMANAGER_H
#define _AUDIOMANAGER_H

#include "AssetManager.h"

// Clase para instanciar el audio, usa archivos WAV
class AudioManager {
private:
	static AudioManager* sInstance; // Se necesita para hacer la clase porque es singleton
	AssetManager* mAssetMgr; // Se usa para cargar archivos de audio

public:
	static AudioManager* Instance(); // Regresa un apuntador a la instancia de la clase
	static void Release(); // Libera la instancia de la clase de la memoria

	void PlayMusic(std::string filename, int loops = -1); // Pone una musica con los loops 1 = infinito, 0 = 1 vez
	void PauseMusic(); // Pausa la musica
	void ResumeMusic(); // Reunuda la musica

	void PlaySFX(std::string filename, int loops = 0, int channel = 0); // Pone los efectos de sonido, para poner varios hay que ponerlos en diferentes canales

private:
	AudioManager(); // constructor
	~AudioManager(); // destructor

};

#endif
// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=x77Rbny5iBA&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=10