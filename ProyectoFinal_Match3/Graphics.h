// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=ATa_joa6Gzg&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7
#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <stdio.h>

// clase singleton que maneja lo que se ve en pantalla y el backbuffer
class Graphics {
public:
	static const int SCREEN_WIDTH = 1720; // Ancho de la pantalla
	static const int SCREEN_HEIGHT = 1024; // Alto de la pantalla

private:
	static Graphics* sInstance; // instance of the game
	static bool sInitialized; // checa si la pantalla se inicializo

	SDL_Window* mWindow; // la ventada principal creada por SDL
	SDL_Surface* mBackBuffer; 

	SDL_Renderer* mRenderer; // render de todas las texturas

public:
	static Graphics* Instance(); // Regresa un apuntador a la instancia del objeto
	static void Release(); // Libera la instancia de la memoria
	static bool Initialized(); // regresa si las librerias de SDL se inicializaron correctamente

	SDL_Texture* LoadTexture(std::string path); // carga imagenes desde una direccion
	SDL_Texture* CreatTextTexture(TTF_Font* font, std::string text, SDL_Color color); // Crea texturas de un tring, fuente y color

	void ClearBackBuffer(); // Borra todas las texturas del backbuffer

	void DrawTexture(SDL_Texture* text, SDL_Rect* clip = NULL, SDL_Rect* rend = NULL, float angle = 0.0f, SDL_RendererFlip flip = SDL_FLIP_NONE); // dibuja la textura al backbuffer

	void Render(); // actualiza backbuffer

private:
	Graphics(); //constructor
	~Graphics(); // destructor

	bool Init(); // Inicializa todo

};

#endif

// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=ATa_joa6Gzg&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7