// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=UPZol-0fn08&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=5
#ifndef _ASSETMANAGER_H
#define _ASSETMANAGER_H
#include "Graphics.h"
#include <SDL_mixer.h>
#include <map>

// Carga todos los assets que se usan en el juego y las agarra para que no se carguen 2 veces
class AssetManager {
private:
	static AssetManager* sInstance; // Se necesita para hacer la clase porque es singleton

	std::map<std::string, SDL_Texture*> mTextures; // Guarda todas las imagenes cargadas
	std::map<std::string, SDL_Texture*> mText; // Guarda todos los textos convertidos a textura
	std::map<std::string, TTF_Font*> mFonts; // Guarda todas las fonts
	std::map<std::string, Mix_Music*> mMusic; // Guarda la musica
	std::map<std::string, Mix_Chunk*> mSFX; // Guarda los efectos de sonido

public:
	static AssetManager* Instance(); // regresa un apuntador a instancia de la clase
	static void Release(); // Libera la instancia de la memoria de la computadora

	SDL_Texture* GetTexture(std::string filename); // Se usa cada vez que se carga una imagen de un archivo, si ya se habia guardado se regresa el cache guardado
	SDL_Texture* GetText(std::string text, std::string filename, int size, SDL_Color color); // Se usa cada vez que haces un texto a textura

	Mix_Music* GetMusic(std::string filename); // Se usa cada vez que se carga una musica de un archivo, si ya se habia guardado se regresa el cache guardado
	Mix_Chunk* GetSFX(std::string filename); // Se usa cada vez que se carga un efecto de sonido de un archivo, si ya se habia guardado se regresa el cache guardado

private:
	AssetManager(); // constructor
	~AssetManager(); // destuctor

	TTF_Font* GetFont(std::string filename, int size); // Se usa cada vez que se carga una font, si ya se habia guardado se regresa el cache guardado
};

#endif
// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=UPZol-0fn08&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=5