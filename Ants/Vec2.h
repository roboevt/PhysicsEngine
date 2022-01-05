#pragma once
class Vec2
{
public:
	float x, y;
	float magnitudeSquared();
	float magnitude();
	float dot(const Vec2& other);
	Vec2 operator+(const Vec2& other);
	void operator+=(const Vec2& other);
	Vec2 operator-(const Vec2& other);
	void operator-=(const Vec2& other);
	float operator*(const Vec2& other);
	Vec2 operator*(float scale);
	Vec2 operator/(float scale);
	Vec2 normalize();
	Vec2();
	Vec2(float x, float y);
};
