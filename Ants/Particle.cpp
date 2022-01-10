#include "Particle.h"
#include <cstdlib>
#include <algorithm>

float Particle::smoothingFactor = 0.001f;
const float Particle::gravitationalConstant = 10.0f;

void Particle::integrate(double timestep) {
	velocity += netForce * timestep;
	position += velocity * timestep;
}

void Particle::calculateForces() {
	netForce = { 0, 0 };
	for (Particle other : *others) {
		Vec2 distance = other.position - this->position;
		float gravity = (.000000001f * this->mass * other.mass) / (distance.magnitudeSquared() + smoothingFactor);
		netForce += distance * gravity;

	}
	//float gravity = -10.0f / (position.magnitudeSquared() + smoothingFactor);
	//netForce = position * gravity;
}

void Particle::update(double timestep) {
	if (position.x > 1) {
		velocity.x = -abs(velocity.x);
	}
	if (position.x < -1) {
		velocity.x = abs(velocity.x);
	}
	if (position.y > 1) {
		velocity.y = -abs(velocity.y);
	}
	if (position.y < -1) {
		velocity.y = abs(velocity.y);
	}
	calculateForces();
	integrate(timestep);
}