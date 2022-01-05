#include "Particle.h"
#include <cstdlib>

float Particle::smoothingFactor = 0.001f;

void Particle::integrate(double timestep) {
	velocity += netForce * timestep;
	position += velocity * timestep;
}

void Particle::calculateForces() {
	float gravity = -10.0f / (position.magnitudeSquared() + smoothingFactor);
	netForce = position * gravity;
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