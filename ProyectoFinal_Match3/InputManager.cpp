// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=E13yeArUHN0&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=7
#include "InputManager.h"

// La instancia empieza siendo NULL
InputManager* InputManager::sInstance = NULL;

// Regresa un apuntador a la instancia de la clase
InputManager* InputManager::Instance() {
	if (sInstance == NULL) {
		sInstance = new InputManager();
	}

	return sInstance;
}

// libera de la memoria la instancia de la clase
void InputManager::Release() {
	delete sInstance;
	sInstance = NULL;
}

// constructor
InputManager::InputManager() {
	mKeyboardState = SDL_GetKeyboardState(&mKeyLength);
	mPrevKeyboardState = new Uint8[mKeyLength];
	memcpy(mPrevKeyboardState, mKeyboardState, mKeyLength);
}

// destructor
InputManager::~InputManager() {
	delete[] mPrevKeyboardState;
	mPrevKeyboardState = NULL;
}

// Regresa verdadero si oprimes una tecla
bool InputManager::KeyDown(SDL_Scancode scanCode) {
	return mKeyboardState[scanCode];
}

// Regresa verdadero una tecla esta presionada
bool InputManager::KeyPressed(SDL_Scancode scanCode) {
	return !mPrevKeyboardState[scanCode] && mKeyboardState[scanCode];
}

// Regresa verdadero si suetas una tecla
bool InputManager::KeyReleased(SDL_Scancode scanCode) {
	return mPrevKeyboardState[scanCode] && !mKeyboardState[scanCode];
}

// regresa un vector con la posicion del mouse
Vector2 InputManager::MousePos() {
	return Vector2((float)mMouseXPos, (float)mMouseYPos);
}

// Regresa verdadero si oprimes un boton
bool InputManager::MouseButtonDown(MOUSE_BUTTON button) {
	Uint32 mask = 0;
	switch (button) {
	case left:
		mask = SDL_BUTTON_LMASK;
		break;

	case right:
		mask = SDL_BUTTON_RMASK;
		break;

	case middle:
		mask = SDL_BUTTON_MMASK;
		break;

	case back:
		mask = SDL_BUTTON_X1MASK;
		break;

	case forward:
		mask = SDL_BUTTON_X2MASK;
		break;
	}
	return (mMouseState & mask);
}

// Regresa verdadero y un boton se queda presiondado
bool InputManager::MouseButtonPressed(MOUSE_BUTTON button) {
	Uint32 mask = 0;
	switch (button) {
	case left:
		mask = SDL_BUTTON_LMASK;
		break;

	case right:
		mask = SDL_BUTTON_RMASK;
		break;

	case middle:
		mask = SDL_BUTTON_MMASK;
		break;

	case back:
		mask = SDL_BUTTON_X1MASK;
		break;

	case forward:
		mask = SDL_BUTTON_X2MASK;
		break;
	}
	return !(mPrevMouseState & mask) && (mMouseState & mask);
}

// Regresa verdadero si sueltas un boton
bool InputManager::MouseButtonReleased(MOUSE_BUTTON button) {
	Uint32 mask = 0;
	switch (button) {
	case left:
		mask = SDL_BUTTON_LMASK;
		break;

	case right:
		mask = SDL_BUTTON_RMASK;
		break;

	case middle:
		mask = SDL_BUTTON_MMASK;
		break;

	case back:
		mask = SDL_BUTTON_X1MASK;
		break;

	case forward:
		mask = SDL_BUTTON_X2MASK;
		break;
	}
	return (mPrevMouseState & mask) && !(mMouseState & mask);
}

// Actualiza el estado de los inputs
void InputManager::Update() {
	mMouseState = SDL_GetMouseState(&mMouseXPos, &mMouseYPos);
}

// Actualiza el estado de los inputs anteriores
void InputManager::UpdatePrevInput() {
	memcpy(mPrevKeyboardState, mKeyboardState, mKeyLength);
	mPrevMouseState = mMouseState;
}
// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=E13yeArUHN0&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=7