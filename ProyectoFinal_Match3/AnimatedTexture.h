// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=hiLAx_YsPy0&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=8
#ifndef _ANIMATEDTEXTURE_H
#define _ANIMATEDTEXTURE_H
#include "Timer.h"
#include "Texture.h"

// Usa de base la clase de Texture pero se usa para agregar hacer uso de "animaciones" mediante spritesheets
class AnimatedTexture : public Texture {

public:
	enum WRAP_MODE { once = 0, loop = 1 }; // tipo de corte de la animacion, si va a pasar 1 vez o si se va a loopear
	enum ANIM_DIR { horizontal = 0, vertical = 1}; // La manera en la que los sprites estan en la spritesheet

private:
	Timer* mTimer; // saca deltaTime para actualizar la animacion
	int mStartX; // donde empieza el sprite en el spritesheet
	int mStartY; // donde empieza el sprite en el spritesheet

	float mAnimationTimer; // cuanto tiempo la animacion ha estado en pantalla
	float mAnimationSpeed; // para determinar la velocidad de las animaciones
	float mTimePerFrame; // Cuanto tiempo deberia de estar cada frame en la pantalla

	int mFrameCount; // guarda el numero de frames de la animacion

	WRAP_MODE mWrapMode; // guarda el tipo de corte de la animacion
	ANIM_DIR mAnimationDirection; // guarda la direccion de la animacion

	bool mAnimationDone; // para saber si ya termino la animacion en el tipo de corte once

public:
	// Carga la animacion de su archivo en la computadora/constructor
	AnimatedTexture(std::string filename, int x, int y, int w, int h, int frameCount, float animationSpeed, ANIM_DIR animationDir);
	~AnimatedTexture(); // destructor

	void WrapMode(WRAP_MODE mode); // decide el tipo de corte de la animacion

	void Update(); // para actualizar las frames de la animacion
};

#endif

// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=hiLAx_YsPy0&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=8
