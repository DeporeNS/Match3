// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=ATa_joa6Gzg&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7
#ifndef _GAMEMANAGER_H
#define _GAMEMANAGER_H
#include "AnimatedTexture.h"
#include "InputManager.h"
#include "AudioManager.h"

// Usa para controlar todos los demas managers
// Contiene el GameLoop y la funcion de render
// Se usa para asegurarse de que todas las funciones se llaman en e orden correcto
class GameManager {
private:
	static GameManager* sInstance; // Necesario para crear la clase porque es singleton

	const int FRAME_RATE = 120; // el frame rate del juego

	bool mQuit; // Se usa para salir del GameLoop
	
	//Lista de managers que se van a usar
	Graphics* mGraphics; 
	AssetManager* mAssetMgr;
	InputManager* mInputMgr;
	AudioManager* mAudioMgr;

	Timer* mTimer; //Se usa para limitar los frames

	SDL_Event mEvents; // Se usa para agarrar los eventos cuando el usuario sale del juego

	Texture* mTex; // Fondo
	Texture* Text; // Texto
	AnimatedTexture* mTexAnim; // Animacion explosion

public:
	static GameManager* Instance(); // Regresa un apuntador a la instancia del juego
	static void Release(); // Sirve para liberar de la memoria 

	void Run(); // Run GameManager

private:
	GameManager();  // constructor
	~GameManager(); // destructor

	void EarlyUpdate(); //  Se usa para cosas que se updatean primero (Input)
	void Update(); // se usa para update (transforms)
	void LateUpdate(); // Se usa para hacer el ultimo update a cosas que van al final (resetear el timer)

	void Render(); // hace update a los renders
};

#endif
// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=ATa_joa6Gzg&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7