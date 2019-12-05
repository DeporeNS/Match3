// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=ATa_joa6Gzg&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7
#include "GameManager.h"

// La instancia se inicializa como NULL
GameManager* GameManager::sInstance = NULL;

// Regresa un apuntador a la instancia del juego
GameManager* GameManager::Instance() {
	if (sInstance == NULL) {
		sInstance = new GameManager();
	}

	return sInstance;
}

// Sirve para liberar de la memoria 
void GameManager::Release() {
	delete sInstance;
	sInstance = NULL;
}

// constructor
GameManager::GameManager() {
	mQuit = false;
	//Inicializa SDL
	mGraphics = Graphics::Instance();

	// Sale de SDL si el juego falla al inicializarse
	if (!Graphics::Initialized())
		mQuit = true;

	//Inicializa AssetManager
	mAssetMgr = AssetManager::Instance();

	//Inicializa InputManager
	mInputMgr = InputManager::Instance();

	//Inicializa Audio Manager
	mAudioMgr = AudioManager::Instance();

	//Inicializa Timer Manager	
	mTimer = Timer::Instance();

	mTex = new Texture("MenuFondo.png");
	//mTex = new Texture("MenuFondo.png", 182, 54, 90, 90);
	//Texture* tex2 = new Texture("MenuFondo.png", 182, 54, 90, 90);
	//Texture* tex2 = new Texture("MenuFondo.png");
	mTex->Pos(Vector2(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f));

	Text = new Texture("Play", "ARCADE.TTF", 72, { 0,0,0 });
	Text->Pos(Vector2(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f));

	
	//mTexAnim = new AnimatedTexture("Nubes.png", 0, 0, 1720, 320, 2, 1.0f, AnimatedTexture::horizontal);
	//mTexAnim->Pos(Vector2(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f));
}

// destructor
GameManager::~GameManager() {
	AudioManager::Release();
	mAudioMgr = NULL;

	AssetManager::Release();
	mAssetMgr = NULL;

	Graphics::Release();
	mGraphics = NULL;

	InputManager::Release();
	mInputMgr = NULL;

	Timer::Release();
	mTimer = NULL;

	delete mTex;
	mTex = NULL;
}

//  Se usa para cosas que se updatean primero (Input)
void GameManager::EarlyUpdate() {
	// Primero se actualizan los Inputs para  saber que lo demas esta bien
	mInputMgr->Update();
}

// se usa para update (transforms)
void GameManager::Update() {
	// GameEntity Updates van aqui
	if (mInputMgr->KeyDown(SDL_SCANCODE_1)) {
		mAudioMgr->PlaySFX("ExplosionGlass.wav");
	}

	if (mInputMgr->KeyDown(SDL_SCANCODE_W)) {
		mTex->Translate(Vector2(0.0f, -40.0f) * mTimer->DeltaTime());
	}
	else if (mInputMgr->KeyDown(SDL_SCANCODE_S)) {
		mTexAnim->Translate(Vector2(0.0f, 40.0f) * mTimer->DeltaTime());
	}

	if (mInputMgr->MouseButtonPressed(InputManager::left)) {
		printf("left mouse button pressed\n");
	}
}

// Se usa para hacer el ultimo update a cosas que van al final (resetear el timer)
void GameManager::LateUpdate() {
	// deteccion de colisiones deben de ir aqui
	mInputMgr->UpdatePrevInput();
	mTimer->Reset();
}

// hace update a los renders	
void GameManager::Render() {
	// Limpia el Ultimo Render del BackBuffer 
	mGraphics->ClearBackBuffer();
	//Todos los demas Renders pasan aqui
	mTex->Render();
	Text->Render();
	//mTexAnim->Render();
	// Se hace el render de la frame
	mGraphics->Render();
}

// Run GameManager
void GameManager::Run() {
	while (!mQuit) {
		mTimer->Update();

		while (SDL_PollEvent(&mEvents) != 0) {
			// Checa si el jugador quito el juego
			if (mEvents.type == SDL_QUIT) {
				mQuit = true;
			}
		}

		// Limita el Frame rate a FRAME_RATE
		if (mTimer->DeltaTime() >= 1.0f / FRAME_RATE) {
			//printf("DeltaTime: %f\n", mTimer->DeltaTime());

			EarlyUpdate();
			Update();
			LateUpdate();
			Render();
			//mTex->Rotate(10 * mTimer->DeltaTime());

			//mTexAnim->Update();

		}
	}
}

// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=ATa_joa6Gzg&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7