// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=E13yeArUHN0&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=7
#ifndef _INPUTMANAGER_H
#define _INPUTMANAGER_H

#include <SDL.h>
#include <string.h>
#include "MathHelper.h"

// Se encarga de todos los inputa de teclado y mouse
class InputManager {
public:
	enum MOUSE_BUTTON { left = 0, right, middle, back, forward }; // enum con los botones del mouse

private:
	static InputManager* sInstance; // Se necesita para crear la clase porque es singleton
	Uint8* mPrevKeyboardState; // Mantiene el anterior estado del Keyboard para Key release y key press
	const Uint8* mKeyboardState; // Mantiene el actual estado del KeyBoard
	int mKeyLength; // numero de teclas presente en el mKeyBoardState sirve para pasarseloa l Prev

	Uint32 mPrevMouseState; // Mantiene el anterior estado del mouse
	Uint32 mMouseState; // Mantiene el actual estado del mouse

	int mMouseXPos; // Posicion del Mouse en X
	int mMouseYPos; // Posicion del Mouse en Y


public:
	static InputManager* Instance(); // Regresa un apuntador a la instancia de la clase
	static void Release(); // libera de la memoria la instancia de la clase

	bool KeyDown(SDL_Scancode scanCode); // Regresa verdadero si oprimes una tecla
	bool KeyPressed(SDL_Scancode scanCode); // Regresa verdadero una tecla esta presionada
	bool KeyReleased(SDL_Scancode scanCode); // Regresa verdadero si suetas una tecla

	bool MouseButtonDown(MOUSE_BUTTON button); // Regresa verdadero si oprimes un boton
	bool MouseButtonPressed(MOUSE_BUTTON button); // Regresa verdadero y un boton se queda presiondado
	bool MouseButtonReleased(MOUSE_BUTTON button); // Regresa verdadero si sueltas un boton

	Vector2 MousePos(); // regresa un vector con la posicion del mouse

	void Update(); // Actualiza el estado de los inputs
	void UpdatePrevInput(); // Actualiza el estado de los inputs anteriores

private:
	InputManager(); // constructor
	~InputManager(); // destructor
};

#endif
// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=E13yeArUHN0&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=7