#pragma once
#include "Vec2.h"

class PhysicsObject
{
public:
	Vec2 position, velocity, netForce;
	unsigned char r, g, b;
	virtual void update(double timestep) = 0;
};

