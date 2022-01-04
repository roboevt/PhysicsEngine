#include "Particle.h"
#include <cstdlib>

void Particle::update(double timestep) {
	if (x > 1) {
		xV = -abs(xV);
	}
	if (x < -1) {
		xV = abs(xV);
	}
	if (y > 1) {
		yV = -abs(yV);
	}
	if (y < -1) {
		yV = abs(yV);
	}
	x += xV * timestep;
	y += yV * timestep;
	yV -= .5f * timestep;
}