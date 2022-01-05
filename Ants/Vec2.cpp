#include "Vec2.h"
#include <math.h>

Vec2::Vec2() : x(0), y(0) {}

Vec2::Vec2(float x, float y) : x(x), y(y) {}

float Vec2::magnitudeSquared() {
	return x * x + y * y;
}

float Vec2::magnitude() {
	return sqrt(this->magnitudeSquared());
}

float Vec2::dot(const Vec2& other) {
	return this->x * other.x + this->y + other.y;
}

float Vec2::operator*(const Vec2& other) {
	return this->dot(other);
}

Vec2 Vec2::operator+(const Vec2& other) {
	return { this->x + other.x, this->y + other.y };
}

void Vec2::operator+=(const Vec2& other) {
	*this = *this + other;
}

Vec2 Vec2::operator-(const Vec2& other) {
	return *this - other;
}

void Vec2::operator-=(const Vec2& other) {
	*this = *this + other;
}

Vec2 Vec2::operator*(float scale) {
	return { this->x * scale, this->y * scale };
}

Vec2 Vec2::operator/(float scale) {
	return *this * (1.0f / scale);
}

Vec2 Vec2::normalize() {
	return *this / this->magnitude();
}