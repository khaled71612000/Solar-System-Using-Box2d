#pragma once
#include <SFML/Graphics.hpp>
class Vector2d
{
public:
	float x;
	float y;

	Vector2d() {
		x = y = 0;
	}
	Vector2d(float x, float y);
	Vector2d operator+(Vector2d other);
	Vector2d operator-(Vector2d other);
	Vector2d operator+=(Vector2d other);
	Vector2d operator-=(Vector2d other);
	Vector2d operator=(Vector2d other);
	bool operator==(Vector2d other);
	Vector2d operator*(float a);
	Vector2d operator*=(float a);
	Vector2d operator=(float a);
	friend Vector2d operator*(float a, Vector2d vector);
	friend Vector2d operator*=(float a, Vector2d vector);
	float Dot(Vector2d other);
	float getMagnitude();
	Vector2d getNormalized();
	void normalize();
	operator sf::Vector2f();
	Vector2d getNormal();

	void print();
};

Vector2d::Vector2d(float x, float y) {
	this->x = x;
	this->y = y;
}

Vector2d Vector2d::operator+(Vector2d other) {
	return Vector2d(x + other.x, y + other.y);
}

Vector2d Vector2d::operator-(Vector2d other) {
	return Vector2d(x - other.x, y - other.y);
}

Vector2d Vector2d::operator+=(Vector2d other) {
	return Vector2d(x += other.x, y += other.y);
}

Vector2d Vector2d::operator-=(Vector2d other) {
	return Vector2d(x -= other.x, y -= other.y);
}

Vector2d Vector2d::operator=(Vector2d other) {
	return Vector2d(x = other.x, y = other.y);
}

bool Vector2d::operator==(Vector2d other) {
	return x == other.x && y == other.y;
}

Vector2d Vector2d::operator*(float a) {
	return Vector2d(a * x, a * y);
}

Vector2d Vector2d::operator*=(float a) {
	return Vector2d(a *= x, a *= y);
}

float Vector2d::Dot(Vector2d other) {
	return x * other.x + y * other.y;
}

float Vector2d::getMagnitude() {
	return sqrt(x*x + y*y);
}

Vector2d Vector2d::getNormalized() {
	float mag = getMagnitude();
	return Vector2d(x / mag, y / mag);
}

Vector2d::operator sf::Vector2f() {
	return sf::Vector2f(x, y);
}

Vector2d Vector2d::getNormal() {
	return Vector2d(-y, x);
}

Vector2d operator*(float a, Vector2d vector)
{
	return vector * a;
}
Vector2d operator*=(float a, Vector2d vector)
{
	return vector *= a;
}
