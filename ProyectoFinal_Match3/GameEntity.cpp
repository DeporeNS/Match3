// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=DI6q73p3rEI&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=3
#include "GameEntity.h"

// constructor
GameEntity::GameEntity(float x, float y) {
	mPos.x = x;
	mPos.y = y;

	mRotation = 0.0f;

	mActive = true;

	mParent = NULL;

	mScale = VEC2_ONE;
}

// destructor
GameEntity::~GameEntity() {
	mParent = NULL;
}

// GameEntity Position
void GameEntity::Pos(Vector2 pos) {
	mPos = pos;
}

// returns our position
Vector2 GameEntity::Pos(SPACE space)
{
	if (space == local || mParent == NULL)
	{
		return mPos;
	}

	Vector2 parentScale = mParent->Scale(world);
	Vector2 rotPos = RotateVector(mPos, mParent->Rotation(local));

	return mParent->Pos(world) + Vector2(rotPos.x * parentScale.x, rotPos.y * parentScale.y);
}

// returns our position
//Vector2 GameEntity::Pos(SPACE space) {
//	if (space == local || mParent == NULL)
//		return mPos;
//
//	Vector2 parentScale = mParent->Scale(world);
//	Vector2 rotPos = RotateVector(Vector2(mPos.x * parentScale.x, mPos.y * parentScale.y), mParent->Rotation(local));
//
//	return mParent->Pos(world) + Vector2(rotPos.x * parentScale.x, rotPos.y * parentScale.y);
//}
 
// va a ver como rota
void GameEntity::Rotation(float r) {
	mRotation = r;
	if (mRotation > 360.0f) {
		int mul = mRotation / 360;
		mRotation -= 360.0f * mul;

	}
	else if (mRotation < 0.0f) {
		int mul = (mRotation / 360) - 1;
		mRotation -= 360.0f * mul;
	}
}

// Regresa la rotacion para ser usada por hijos
float GameEntity::Rotation(SPACE space) {
	if (space == local || mParent == NULL)
		return mRotation;

	return mParent->Rotation(world) + mRotation;
}

// Cambia la escala de la entidad si tiene padre con respecto al padre sino con el mundo
void GameEntity::Scale(Vector2 scale) {
	mScale = scale;
}

// Regresa la escala del objeto si tiene padre con respecto al padre sino con el mundo
Vector2 GameEntity::Scale(SPACE space) {
	if (space == local || mParent == NULL) {
		return mScale;
	}

	Vector2 scale = mParent->Scale(world);
	scale.x *= mScale.x;
	scale.y *= mScale.y;

	return scale;
}

// Ver si el juego esta activo
void GameEntity::Active(bool active) {
	active = active;
}

// regresa si el juego esta activo
bool GameEntity::Active() {
	return mActive;
}

// Hacer que los hijos del objeto tomen al papa como referencia para las cosas
void GameEntity::Parent(GameEntity* parent)
{
	mPos = Pos(world) - parent->Pos(world);

	mParent = parent;
}

//// Hacer que los hijos del objeto tomen al papa como referencia para las cosas
//void GameEntity::Parent(GameEntity* parent) {
//	 //If the parent is removed, The Position/Rotation/Scale are the GameEntity's world values, to keep the object looking the same after the removal of the parent;
//	 if (parent == NULL) {
//
//		 mPos = Pos(world);
//		 mScale = Scale(world);
//		 mRotation = Rotation(world);
//
//	 }
//	 else {
//
//		 //If the object already has a parent, remove the current parent to get it ready to be the child for the new parent
//		 if (mParent != NULL)
//			 Parent(NULL);
//
//		 Vector2 parentScale = parent->Scale(world);
//
//		 //Setting the local position to be relative to the new parent (while maintaining the same world position as before)
//		 mPos = RotateVector(Pos(world) - parent->Pos(world), -parent->Rotation(world));
//		 mPos.x /= parentScale.x;
//		 mPos.y /= parentScale.y;
//
//		 //Setting the local rotation to be relative to the new parent (while maintaining the same world rotation as before)
//		 mRotation = mRotation - parent->Rotation(world);
//
//		 //Setting the new scale to be relative to the new parent (while maintaining the same world scale as before)
//		 mScale = Vector2(mScale.x / parentScale.x, mScale.y / parentScale.y);
//	 }
//
//	 mParent = parent;
//}

// asigna un padre a la entidad
GameEntity* GameEntity::Parent() {
	return mParent;
}

// mueve la entidad en un espacio local
void GameEntity::Translate(Vector2 vec) {
	mPos += vec;
}

// rota la entidad en un espacio local
void GameEntity::Rotate(float amount) {
	mRotation += amount;
}

// update que va a quedar overload en el hijo
void GameEntity::Update() {

}

// render que va a quedar overload en el hijo
void GameEntity::Render() {

}


// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=DI6q73p3rEI&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=3