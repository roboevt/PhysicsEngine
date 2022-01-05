#include "PhysicsEngine.h"
#include "Particle.h"
#include <stdlib.h>
#include <iostream>

PhysicsEngine::PhysicsEngine() : timestep(0), currentTime(0), speed(1) {
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
    if (!paused) {
        double oldTime = currentTime;
        currentTime = glfwGetTime();
        timestep = currentTime - oldTime;
        timestep *= speed / 10;
        for (std::shared_ptr<PhysicsObject> object : objects) {
            object->update(timestep);
        }
    }
}

// Generates a random float between 1 and -1
float random() {
    return (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) * 2 - 1;
}

void PhysicsEngine::generateRandomParticles(unsigned int numParticles) {
    for (int i = 0; i < numParticles; i++) {
        std::shared_ptr<PhysicsObject> particle = std::make_shared<Particle>();
        particle->position.x = random();
        particle->position.y = random();
        particle->velocity.x = random();
        particle->velocity.y = random();
        particle->r = rand() % 255;
        particle->g = rand() % 255;
        particle->b = rand() % 255;
        objects.push_back(particle);
    }
}

void PhysicsEngine::generateCirclingParticles(unsigned int numParticles) {
    for (int i = 0; i < numParticles / 2; i++) {
        std::shared_ptr<PhysicsObject> particle = std::make_shared<Particle>();
        float x = random() / 4 + .25f;
        float y = random() / 2;
        particle->position.x = x;
        particle->position.y = y;
        float distance = sqrt(x * x + y * y);
        float angle = atan(y / x);
        particle->velocity.x = sin(angle) * 2;
        particle->velocity.y = -cos(angle) * 2;
        particle->velocity.x *= random() + 1;
        particle->velocity.y *= random() + 1;
        particle->r = rand() % 255;
        particle->g = rand() % 255;
        particle->b = rand() % 255;
        objects.push_back(particle);
    }

    for (int i = 0; i < numParticles / 2; i++) {
        std::shared_ptr<PhysicsObject> particle = std::make_shared<Particle>();
        float x = random() / 4 - .25f;
        float y = random() / 2;
        particle->position.x = x;
        particle->position.y = y;
        float distance = sqrt(x * x + y * y);
        float angle = atan(y / x);
        particle->velocity.x = -sin(angle) * 2;
        particle->velocity.y = cos(angle) * 2;
        particle->velocity.x *= random() + 1;
        particle->velocity.y *= random() + 1;
        particle->r = rand() % 255;
        particle->g = rand() % 255;
        particle->b = rand() % 255;
        objects.push_back(particle);
    }
}

void PhysicsEngine::clear() {
    objects.clear();
    std::cout << "Cleared" << std::endl;
}

void PhysicsEngine::increaseSpeed() {
    speed *= 1.2f;
}

void PhysicsEngine::decreaseSpeed() {
    speed *= 0.8f;
}

void PhysicsEngine::pause() {
    if (paused) {
        paused = false;
        currentTime = glfwGetTime();
    }
    else {
        paused = true;
    }
}