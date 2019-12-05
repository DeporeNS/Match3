// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=z9U-Jif4RVU&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=2
#ifndef _TIMER_H
#define _TIMER_H
#include <SDL.h>

// Clase usada para hacer guardar el tiempo entre cada reset o frame
class Timer {
private:
	static Timer* sInstance; // Necesaria para crear la clase porque es singleton

	unsigned int mStartTicks; // contiene el tiempo del ultimo reset
	unsigned int mElapsedTicks; // Guarda el tiempo desde el ultimo reset en milisegundo
	float mDeltaTime; // Guarda el tiempo desde el ultimo reset en segundos
	float mTimeScale;

public:
	static Timer* Instance(); // Instancea el Timer
	static void Release(); // Suelta la instancia de la memoria

	void Reset(); // Reinicia el GameTime
	float DeltaTime(); // Regresa el tiempo que ha pasado

	void TimeScale(float t = 1.0f); // Inicia la escala como 1
	float TimeScale(); // Se usa para cambiar en cuanto tiempo cambian las cosas 

	void Update(); // Se llama en el EarlyUpdate para actualizar el tiempo

private:
	Timer();// constructor
	~Timer();// destructor
};

#endif
// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=z9U-Jif4RVU&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=2