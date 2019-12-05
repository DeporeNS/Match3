// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=z9U-Jif4RVU&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=2
#include "Timer.h"

// Se Inicializa la instancia en NULL
Timer* Timer::sInstance = NULL;

// instance timer
Timer* Timer::Instance() {
	// Crea instancia de timer si no existia una antes
	if (sInstance == NULL)
		sInstance = new Timer();

	return sInstance;
}

// releases timer memory allocation
void Timer::Release() {
	delete sInstance;
	sInstance = NULL;
}

// constructor
Timer::Timer() {
	// Se usa reset para reiniciar todos los valores excepto mTimeScale
	Reset();
	mTimeScale = 1.0f;
}

// destructor
Timer::~Timer() {

}

// Reset GameTime
void Timer::Reset() {
	mStartTicks = SDL_GetTicks();
	mElapsedTicks = 0;
	mDeltaTime = 0.0f;
}

// Return Time Elapsed
float Timer::DeltaTime() {
	return mDeltaTime;
}

void Timer::TimeScale(float t) {
	mTimeScale = t;
}

float Timer::TimeScale() {
	return mTimeScale;
}

// calculates elapsed ticks 
void Timer::Update() {
	mElapsedTicks = SDL_GetTicks() - mStartTicks;
	// Convirtiendo millisegundos a segundos 
	mDeltaTime = mElapsedTicks * 0.001f;
}

// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=z9U-Jif4RVU&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=2