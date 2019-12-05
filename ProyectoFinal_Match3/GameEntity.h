// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=DI6q73p3rEI&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=3
#ifndef _GAMEENTITY_H
#define _GAMEENTITY_H
#include "MathHelper.h"

// clase base para las entidades del juego
class GameEntity {
public:
	enum SPACE { local = 0, world = 1 }; // enum para descubrir si la entidad esta en el mundo o en un espacio local, asocia posicion, escala y rotacion con el espacio

private:
	Vector2 mPos; // posicion
	float mRotation; // rotacion
	Vector2 mScale; //escala

	bool mActive; // Se activa al objeto para renderear y actualizar
	GameEntity* mParent; // la entidades solo pueden tener 1 padre pero pueden tener muchos hijos

public:
	GameEntity(float x = 0.0f, float y = 0.0f); // constructor que da la posicion inicial de la entidad
	~GameEntity(); //destructor

	void Pos(Vector2 pos); // Cambia la posicion de la entidad si tiene padre con respecto al padre sino con el mundo
	Vector2 Pos(SPACE space = world); // Regresa la poscion del objeto si tiene padre con respecto al padre sino con el mundo

	void Rotation(float rotation); // Cambia la rotacion de la entidad si tiene padre con respecto al padre sino con el mundo
	float Rotation(SPACE space = world); // Regresa la rotacion del objeto si tiene padre con respecto al padre sino con el mundo

	void Scale(Vector2 scale); // Cambia la escala de la entidad si tiene padre con respecto al padre sino con el mundo
	Vector2 Scale(SPACE space = world); // Regresa la escala del objeto si tiene padre con respecto al padre sino con el mundo

	void Active(bool active); // Cambia el estado activo de la entidad
	bool Active(); // Regresa el estado de la entidad

	void Parent(GameEntity* parent); // asigna un padre a la entidad
	GameEntity* Parent(); // Regresa el padre de la entidad si lo tiene

	void Translate(Vector2 vec); // mueve la entidad en un espacio local
	void Rotate(float amout); // rota la entidad en un espacio local

	virtual void Update(); // update que va a quedar overload en el hijo
	virtual void Render(); // render que va a quedar overload en el hijo
};

#endif

// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=DI6q73p3rEI&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=3
