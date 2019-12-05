// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=k70aBlef-20&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=6
#ifndef _TEXTURE_H
#define _TEXTURE_H
#include "GameEntity.h"
#include "AssetManager.h"

//clase para renderear texturas hace imagenes completas, spritesheets y string a textura
class Texture : public GameEntity {
protected:
	SDL_Texture* mTex; // La textura que se va a renderear
	Graphics* mGraphics; // para renderear la textura
	int mWidth; // Ancho de la textura
	int mHeight; // Alto de la textura 

	bool mClipped; // verdadero si la textura viene de una spritesheet
	SDL_Rect mRenderRect; // renderea la textura en la pantalla
	SDL_Rect mClipRect; // se usa para cortar la spritesheet

public:
	Texture(std::string filename); // Carga un sprite desde un archivo
	Texture(std::string filename, int x, int y, int w, int h); // Carga un aprite desde un archivo y se usa para las spritesheet
	Texture(std::string text, std::string fontpath, int size, SDL_Color color); // convierte un string a un render en la pantalla
	~Texture(); // destructor

	virtual void Render(); // se llama para hacer el render a la pantalla
};

#endif
// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=k70aBlef-20&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=6