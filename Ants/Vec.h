#pragma once
class Vec2
{
public:
	float x, y;
	Vec2();
	Vec2(float x, float y);
	Vec2 operator+(const Vec2& other);
	void operator+=(const Vec2& other);
	Vec2 operator-(const Vec2& other);
	void operator-=(const Vec2& other);
	float operator*(const Vec2& other);
	Vec2 operator*(float scale);
	Vec2 operator/(float scale);
	float magnitudeSquared();
	float magnitude();
	float dot(const Vec2& other);
	Vec2 normalize();
};

class Color {
public:
	unsigned char r; 
	unsigned char g;
	unsigned char b;
	Color(unsigned char r, unsigned char g, unsigned char b);
	Color();
};