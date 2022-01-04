#include "PhysicsEngine.h"
#include "Particle.h"
#include <stdlib.h>

PhysicsEngine::PhysicsEngine() : timestep(0), currentTime(0) {
    glEnable(GL_POINT_SMOOTH);
    glPointSize(10.0);
}

void PhysicsEngine::render() {
    glBegin(GL_POINTS);
    for (std::shared_ptr<PhysicsObject> object : objects) {
        glColor3ub(object->r, object->g, object->b);
        glVertex2f(object->x, object->y);
    }
    glEnd();
}

void PhysicsEngine::update() {
    double oldTime = currentTime;
    currentTime = glfwGetTime();
    timestep = currentTime - oldTime;
    for (std::shared_ptr<PhysicsObject> object : objects) {
        object->update(timestep);
    }
}

void PhysicsEngine::generateParticles(unsigned int numParticles) {
    for (int i = 0; i < numParticles; i++) {
        std::shared_ptr<PhysicsObject> a = std::make_shared<Particle>();
        a->x = (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) * 2 - 1;
        a->y = (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) * 2 - 1;
        a->xV = (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) * 2 - 1;
        a->yV = (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) * 2 - 1;
        a->r = rand() % 255;
        a->g = rand() % 255;
        a->b = rand() % 255;
        objects.push_back(a);
    }
}