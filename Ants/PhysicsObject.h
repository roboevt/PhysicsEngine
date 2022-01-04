#pragma once
class PhysicsObject
{
public:
	float x, y, xV, yV;
	unsigned char r, g, b;
	virtual void update(double timestep) = 0;
};

