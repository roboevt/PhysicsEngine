#pragma once
#include "PhysicsObject.h"
#include <vector>

class Particle : public PhysicsObject
{
public:
	void update(double timestep);
	void integrate(double timestep);
	void calculateForces();
	static float smoothingFactor;
	//static std::vector<Particle>* others;
	std::vector<Particle>* others;
};

//std::vector<Particle>* others;