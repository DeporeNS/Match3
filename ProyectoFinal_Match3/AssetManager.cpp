// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=UPZol-0fn08&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=5
#include "AssetManager.h"

// Se inicializa como NULL
AssetManager* AssetManager::sInstance = NULL;

// regresa un apuntador a instancia de la clase
AssetManager* AssetManager::Instance() {
	// Crea una instancia no existia una ya antes
	if (sInstance == NULL)
		sInstance = new AssetManager();

	return sInstance;
}

// Libera la instancia de la memoria de la computadora
void AssetManager::Release() {
	delete sInstance;
	sInstance = NULL;
}

// constructor
AssetManager::AssetManager() {

}

// destructor
AssetManager::~AssetManager() {
	// Libera todas las texturas guardadas
	for (auto tex : mTextures) {
		if (tex.second != NULL) {
			SDL_DestroyTexture(tex.second);
		}
	}

	mTextures.clear();

	//Libera todo el texo guardado
	for (auto text : mText) {
		if (text.second != NULL) {
			SDL_DestroyTexture(text.second);
		 }
	}

	mText.clear();

	// Libera todas las fuentes guardadas
	for(auto font : mFonts) {
		if (font.second != NULL) {
			TTF_CloseFont(font.second);
		}
	}

	mFonts.clear();

	//Libera toda la musica guardada
	for (auto music : mMusic) {
		if (music.second != NULL) {
			Mix_FreeMusic(music.second);
		}
	}
	mMusic.clear();

	//Libera todos los efectos de sonido guardados
	for (auto sfx : mSFX) {
		if (sfx.second != NULL) {
			Mix_FreeChunk(sfx.second);
		}
	}
	mSFX.clear();
}

// Se usa cada vez que se carga una imagen de un archivo, si ya se habia guardado se regresa el cache guardado
SDL_Texture* AssetManager::GetTexture(std::string filename) {
	// Obtiene toda la direccion del archivo
	std::string fullPath = SDL_GetBasePath();
	fullPath.append("Assets/" + filename);

	// Si la direccion no se habia cargado antes la carga
	if (mTextures[fullPath] == nullptr)
		mTextures[fullPath] = Graphics::Instance()->LoadTexture(fullPath);

	// Regresa el archivo guardado en el cache
	return mTextures[fullPath];
}

// Se usa cada vez que se carga una font, si ya se habia guardado se regresa el cache guardado
TTF_Font* AssetManager::GetFont(std::string filename, int size) {
	// Obtiene toda la direccion del archivo
	std::string fullPath = SDL_GetBasePath();
	fullPath.append("Assets/" + filename);

	// La llave toma en cuenta el tamano de la fuente 
	std::string key = fullPath + (char)size;

	// Si la fuente no se habia cargado antes la carga
	if (mFonts[key] == nullptr) {
		mFonts[key] = TTF_OpenFont(fullPath.c_str(), size);
		// Manejo de error si no se carga la fuente
		if (mFonts[key] == nullptr) {
			printf("Font Loading Error: Font-%s Error-%s", filename.c_str(), TTF_GetError());
		}
	}
	// Regresa la fuente guardada
	return mFonts[key];
}

// Se usa cada vez que haces un texto a textura
SDL_Texture* AssetManager::GetText(std::string text, std::string filename, int size, SDL_Color color) {
	// Regresa la fuente del cache
	TTF_Font* font = GetFont(filename, size);

	//La llave toma en cuenta la fuente, el texto, el tamano y el color para diferenciar entre texturas
	std::string key = text + filename + (char)size + (char)color.r + (char)color.b + (char)color.g;

	//Si el  mismo texto no se habia rendereado antes lo guarda
	if (mText[key] == nullptr) {
		mText[key] = Graphics::Instance()->CreatTextTexture(font, text, color);
	}

	// regresa el cache que contiene el texto
	return mText[key];
}

// Se usa cada vez que se carga una musica de un archivo, si ya se habia guardado se regresa el cache guardado
Mix_Music* AssetManager::GetMusic(std::string filename) {
	//Obten la direccion completa del archivo WAV
	std::string fullPath = SDL_GetBasePath();
	fullPath.append("Assets/" + filename);

	//Si la direccion no habia sido guardada antes se guarda
	if (mMusic[fullPath] == nullptr) {
		mMusic[fullPath] = Mix_LoadMUS(fullPath.c_str());
		// Manejo de error en fallo de cargar el archivo
		if (mMusic[fullPath] == NULL) {
			printf("Music Loading Error: File-%s Error-%s", filename.c_str(), Mix_GetError());
		}
	}

	return mMusic[fullPath];
}

// Se usa cada vez que se carga un efecto de sonido de un archivo, si ya se habia guardado se regresa el cache guardado
Mix_Chunk* AssetManager::GetSFX(std::string filename) {
	//Obten la direccion completa del archivo WAV
	std::string fullPath = SDL_GetBasePath();
	fullPath.append("Assets/" + filename);

	//Si la direccion no habia sido guardada antes se guarda
	if (mSFX[fullPath] == nullptr) {
		mSFX[fullPath] = Mix_LoadWAV(fullPath.c_str());
		// Manejo de error en fallo de cargar el archivo
		if (mSFX[fullPath] == NULL) {
			printf("SFX Loading Error: File-%s Error-%s", filename.c_str(), Mix_GetError());
		}
	}

	return mSFX[fullPath];
}
// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=UPZol-0fn08&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=5