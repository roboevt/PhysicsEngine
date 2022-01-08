#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "PhysicsObject.h"
#include "Particle.h"
#include <vector>
#include <memory>

class PhysicsEngine
{
public:
	std::vector<Particle> objects;
	double currentTime, timestep, speed;
	bool paused;
	PhysicsEngine();
	void render();
	void update();
	void generateRandomParticles(unsigned int numParticles);
	void generateCirclingParticles(unsigned int numParticles);
	void clear();
	void increaseSpeed();
	void decreaseSpeed();
	void pause();
};