#pragma once
#include "PhysicsObject.h"
class Particle : public PhysicsObject
{
public:
	void update(double timestep);
	void integrate(double timestep);
	void calculateForces();
	static float smoothingFactor;
};

