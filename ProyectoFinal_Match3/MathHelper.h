// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=DI6q73p3rEI&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=3
#ifndef _MATHHELPER_H
#define _MATHHELPER_H
#include <math.h>

#define PI 3.14159265
#define DEG_TO_RAD PI / 180.0f


//Contiene todas las funciones matematicas que se van a usar en el framework
struct Vector2 {
	float x;
	float y;

	// Como es un Vector2
	Vector2(float _x = 0.0f, float _y = 0.0f)
		: x(_x), y(_y) {}

	// Calcula la raiz de la magnitud
	float MagnitudeSqr() {
		return ((x * x) + (y * y));
	}
	 //Calcula la magnitud
	float Magnitude() {
		return (float)sqrt((x * x) + (y * y));
	}

	//Regresa la normal del vector
	Vector2 Normalized() {
		float mag = Magnitude();

		return Vector2(x / mag, y / mag);
	}

	// Suma simple vector
	Vector2& operator +=(const Vector2& rhs) {
		x += rhs.x;
		y += rhs.y;

		return *this;
	}

	//Resta simple vecotr
	Vector2& operator -=(const Vector2& rhs) {
		x -= rhs.x;
		y -= rhs.y;

		return *this;
	}
};

// Suma 2 vectores
inline Vector2 operator +(const Vector2& lhs, const Vector2& rhs) {
	return Vector2(lhs.x + rhs.x, lhs.y + rhs.y);
}

// Resta 2 vectores
inline Vector2 operator -(const Vector2& lhs, const Vector2& rhs) {
	return Vector2(lhs.x - rhs.x, lhs.y - rhs.y);
}

// Multiplica un vector 
inline Vector2 operator *(const Vector2& lhs, const float& rhs) {
	return Vector2(lhs.x * rhs, lhs.y * rhs);
}
 
//Rota un vector
inline Vector2 RotateVector(Vector2& vec, float angle) {
	float radAngle = (float)(angle * DEG_TO_RAD);

	return Vector2((float)(vec.x * cos(radAngle) - vec.y * sin(radAngle)), (float)(vec.x * sin(radAngle) + vec.y * cos(radAngle)));
}

//Lista de vectores comunmente utilizados
const Vector2 VEC2_ZERO = { 0.0f, 0.0f };
const Vector2 VEC2_ONE = { 1.0f, 1.0f };
const Vector2 VEC2_UP = { 0.0f, 1.0f };
const Vector2 VEC2_RIGHT = { 1.0f, 0.0f };

#endif
// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=DI6q73p3rEI&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=3