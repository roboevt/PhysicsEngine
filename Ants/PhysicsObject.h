#pragma once
#include "Vec.h"

class PhysicsObject
{
public:
	Vec2 position, velocity, netForce;
	Color color;
	virtual void update(double timestep) = 0;
};
