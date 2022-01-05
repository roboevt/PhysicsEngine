#include "PhysicsEngine.h"
#include "Particle.h"
#include <stdlib.h>

PhysicsEngine::PhysicsEngine() : timestep(0), currentTime(0) {
    glEnable(GL_POINT_SMOOTH);
    glPointSize(5.0);
}

void PhysicsEngine::render() {
    glBegin(GL_POINTS);
    for (std::shared_ptr<PhysicsObject> object : objects) {
        glColor3ub(object->r, object->g, object->b);
        glVertex2f(object->position.x, object->position.y);
    }
    glEnd();
}

void PhysicsEngine::update() {
    double oldTime = currentTime;
    currentTime = glfwGetTime();
    timestep = currentTime - oldTime;
    timestep /= 10;
    for (std::shared_ptr<PhysicsObject> object : objects) {
        object->update(timestep);
    }
}

void PhysicsEngine::generateRandomParticles(unsigned int numParticles) {
    for (int i = 0; i < numParticles; i++) {
        std::shared_ptr<PhysicsObject> particle = std::make_shared<Particle>();
        particle->position.x = (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) * 2 - 1;
        particle->position.y = (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) * 2 - 1;
        particle->velocity.x = (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) * 2 - 1;
        particle->velocity.y = (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) * 2 - 1;
        particle->r = rand() % 255;
        particle->g = rand() % 255;
        particle->b = rand() % 255;
        objects.push_back(particle);
    }
}

void PhysicsEngine::generateCirclingParticles(unsigned int numParticles) {
    for (int i = 0; i < numParticles; i++) {
        std::shared_ptr<PhysicsObject> particle = std::make_shared<Particle>();
        float x = (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) / 2;
        float y = ((static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) * 2 - 1) / 2;
        particle->position.x = x;
        particle->position.y = y;
        float distance = sqrt(x * x + y * y);
        float angle = atan(y / x);
        particle->velocity.x = sin(angle);
        particle->velocity.y = -cos(angle);
        particle->r = rand() % 255;
        particle->g = rand() % 255;
        particle->b = rand() % 255;
        objects.push_back(particle);
    }
}