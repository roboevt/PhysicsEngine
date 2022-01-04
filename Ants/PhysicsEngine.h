#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "PhysicsObject.h"
#include <vector>
#include <memory>
class PhysicsEngine
{
public:
	std::vector<std::shared_ptr<PhysicsObject>> objects;
	double currentTime, timestep;
	void render();
	void update();
	void generateParticles(unsigned int numParticles);
	PhysicsEngine();
};