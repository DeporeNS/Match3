// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=ATa_joa6Gzg&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7
#include "Graphics.h"

// Empieza sin haber ninguna instancia de graficos
Graphics* Graphics::sInstance = NULL;
// Initialized empieza siendo falso porque aun no inizializamos los graficos
bool Graphics::sInitialized = false;

// Si no hay una instance crea una y regresa la instance de los graficos
Graphics* Graphics::Instance() {
	//Crea una nueva instancia si no habia ya una
	if (sInstance == NULL) {
		sInstance = new Graphics();
	}

	return sInstance;
}

// borrar los graficos
void Graphics::Release() {
	delete sInstance;
	sInstance = NULL;

	sInitialized = false;
}

// return if you initialized graphics or not
bool Graphics::Initialized() {
	return sInitialized;
}

// contructor
Graphics::Graphics() {
	mBackBuffer = NULL;
	sInitialized = Init();
}

// destructor
Graphics::~Graphics() {
	SDL_DestroyWindow(mWindow);
	mWindow = NULL;

	SDL_DestroyRenderer(mRenderer);
	mRenderer = NULL;

	// Cierra todas las librerias de graficos de SDL
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

// Inicializar Graphics
bool Graphics::Init() {
	//Inicializa SDL Video y Audio y manejo de errores
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
		printf("SDL Initalization Error: %s\n", SDL_GetError());
		return false;
	}

	// Crea una ventana
	mWindow = SDL_CreateWindow("SDL_Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	// Maneja errores de crear la ventana
	if (mWindow == NULL) {
		printf("Window Creation Error: %s\n", SDL_GetError());
		return false;
	}

	// Crea un render
	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);

	// Manejo de errores de crear un render
	if (mRenderer == NULL) {
		printf("Renderer Creation Error: %s\n", SDL_GetError());
		return false;
	}

	// Poniendo el color del render sin nada a blanco
	SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

	// Inicializando la libreria SDL_Image y manejo de errores
	int flags = IMG_INIT_PNG;
	if (!(IMG_Init(flags) & flags)) {
		printf("IMG Initialization Error: %s \n", IMG_GetError());
		return false;
	}

	// Inicializando la libreria SDL_ttf y manejo de errores
	if (TTF_Init() == -1) {
		printf("TTF Initialization Error: %s\n", TTF_GetError());
		return false;
	}

	mBackBuffer = SDL_GetWindowSurface(mWindow);

	// Regresa verdadero si no hubo errores de inicializacion
	return true;
}

// carga imagenes desde una direccion
SDL_Texture* Graphics::LoadTexture(std::string path) {
	SDL_Texture* tex = NULL;

	// Carga imagenes a la superficie
	SDL_Surface* surface = IMG_Load(path.c_str());
	//Majeno de errores
	if (surface == NULL) {
		printf("Image Load Error: Path(%s) - Error(%s)\n", path.c_str(), IMG_GetError());
		return tex;
	}

	// convierte la surface en una textura que se pueda renderear
	tex = SDL_CreateTextureFromSurface(mRenderer, surface);
	// Manejo e errores
	if (tex == NULL) {
		printf("Create Texture Error: %s\n", SDL_GetError());
		return tex;
	}
	// Borra la Surface porque solo se necesita la textura
	SDL_FreeSurface(surface);
	return tex;
}

// Crea texturas de un tring, fuente y color
SDL_Texture* Graphics::CreatTextTexture(TTF_Font* font, std::string text, SDL_Color color) {
	// hace render de un texto a una surface con color y fuente
	SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
	// Manejo de errores
	if (surface == NULL) {
		printf("Text Render Error: %s\n", TTF_GetError());
		return NULL;
	}

	//Convierte surface en textura para que se pueda renderear
	SDL_Texture* tex = SDL_CreateTextureFromSurface(mRenderer, surface);
	// Manejo de errores
	if (tex == NULL) {
		printf("Text Texture Creation Error: %s\n", SDL_GetError());
		return NULL;
	}

	//Borra surface porque solo se necesita la textura
	SDL_FreeSurface(surface);

	return tex;
}

// Borra todas las texturas del backbuffer
void Graphics::ClearBackBuffer() {
	SDL_RenderClear(mRenderer);
}

// dibuja la textura al backbuffer
void Graphics::DrawTexture(SDL_Texture* tex, SDL_Rect* clip, SDL_Rect* rend, float angle, SDL_RendererFlip flip) {
	SDL_RenderCopyEx(mRenderer, tex, clip, rend, angle, NULL, flip);
}

// Refreshes the Backbuffer of the created window
void Graphics::Render() {
	SDL_RenderPresent(mRenderer);
}

// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=ATa_joa6Gzg&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7