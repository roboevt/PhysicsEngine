#include "PhysicsEngine.h"
#include "Particle.h"
#include <stdlib.h>
#include <iostream>
#include <algorithm> 

PhysicsEngine::PhysicsEngine() : timestep(0), currentTime(0), speed(1), paused(false) {
    srand(time(0));
}

void PhysicsEngine::render() {
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(2, GL_FLOAT, sizeof(Particle), &objects[0].position);
    glColorPointer(3, GL_UNSIGNED_BYTE, sizeof(Particle), &objects[0].color);
    glDrawArrays(GL_POINTS, 0, objects.size());

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    
    /*glBegin(GL_POINTS);
    for (int i = 0; i < objects.size(); i++) {
        glColor3ub(objects[i].color.r, objects[i].color.g, objects[i].color.b);
        glVertex2f(objects[i].position.x, objects[i].position.y);
    }
    glEnd();*/
}

void PhysicsEngine::update() {
    if (!paused) {
        double oldTime = currentTime;
        currentTime = glfwGetTime();
        timestep = currentTime - oldTime;
        timestep *= speed / 10;
        if (timestep > 0.001) {
            timestep = 0.001;
        }
        for (int i = 0; i < objects.size(); i++) {
            objects[i].update(timestep);
        }
    }
}

// Generates a random float between 1 and -1
float random() {
    return (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) * 2 - 1;
}

void PhysicsEngine::generateRandomParticles(unsigned int numParticles) {
    for (int i = 0; i < numParticles; i++) {
        Particle particle;
        particle.position.x = random();
        particle.position.y = random();
        particle.velocity.x = random();
        particle.velocity.y = random();
        particle.color = Color(rand() % 255, rand() & 255, rand() % 255);
        particle.others = &objects;
        objects.push_back(particle);
    }
}

void PhysicsEngine::generateCirclingParticles(unsigned int numParticles) {
    for (int i = 0; i < numParticles / 2; i++) {
        Particle particle;
        float x = random() / 4 + .25f;
        float y = random() / 2;
        particle.position.x = x;
        particle.position.y = y;
        float distance = sqrt(x * x + y * y);
        float angle = atan(y / x);
        particle.velocity.x = sin(angle) * 2;
        particle.velocity.y = -cos(angle) * 2;
        particle.velocity.x *= random() + 1;
        particle.velocity.y *= random() + 1;
        particle.color = Color(rand() % 255, rand() & 255, rand() % 255);
        particle.others = &objects;
        objects.push_back(particle);
    }

    for (int i = 0; i < numParticles / 2; i++) {
        Particle particle;
        float x = random() / 4 - .25f;
        float y = random() / 2;
        particle.position.x = x;
        particle.position.y = y;
        float distance = sqrt(x * x + y * y);
        float angle = atan(y / x);
        particle.velocity.x = -sin(angle) * 2;
        particle.velocity.y = cos(angle) * 2;
        particle.velocity.x *= random() + 1;
        particle.velocity.y *= random() + 1;
        particle.color = Color(rand() % 255, rand() & 255, rand() % 255);
        particle.others = &objects;
        objects.push_back(particle);
    }
}

void PhysicsEngine::generateParticle(float x, float y) {
    Particle particle;
    particle.position = { x, y };
    particle.others = &objects;
    particle.color = Color(rand() % 255, rand() & 255, rand() % 255);
    particle.mass = (rand() + 1) * 5;
    objects.push_back(particle);
}

void PhysicsEngine::clear() {
    objects.clear();
    std::cout << "Cleared" << std::endl;
}

void PhysicsEngine::increaseSpeed() {
    if(speed < 10)
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