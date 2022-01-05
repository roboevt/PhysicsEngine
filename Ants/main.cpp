#include <iostream>
#include <math.h>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <Windows.h>

#include "PhysicsEngine.h"

const unsigned int WIDTH = 1920, HEIGHT = 1080;

PhysicsEngine physicsEngine = PhysicsEngine();

GLFWwindow* initWindow() {
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Physics", nullptr, nullptr);
    int screenWidth, screenHeight;
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return nullptr;
    }
    glfwMakeContextCurrent(window);
    glewExperimental = true;
    if (GLEW_OK != glewInit())
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return nullptr;
    }
    glViewport(0, 0, screenWidth, screenHeight);
    return window;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS) {
        std::cout << key << std::endl;
        switch (key) {
        case GLFW_KEY_UP:
            physicsEngine.increaseSpeed();
            break;
        case GLFW_KEY_DOWN:
            physicsEngine.decreaseSpeed();
            break;
        case GLFW_KEY_DELETE:
            physicsEngine.clear();
            break;
        case GLFW_KEY_R:
            physicsEngine.generateRandomParticles(100);
            break;
        case GLFW_KEY_C:
            physicsEngine.generateCirclingParticles(100);
            break;
        case GLFW_KEY_SPACE:
            physicsEngine.pause();
            break;
        case GLFW_KEY_ESCAPE:
            glfwSetWindowShouldClose(window, true);
            break;
        default:
            break;
        }
    }
}

int main()
{
    GLFWwindow* window = initWindow();

    glfwSetKeyCallback(window, keyCallback);
    glEnable(GL_POINT_SMOOTH);
    glPointSize(5.0);
    physicsEngine.generateCirclingParticles(1000);

    int frame = 0;
    double lastTime = 0;
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        frame++;

        double currentTime = glfwGetTime();
        double delta = currentTime - lastTime;
        if (delta >= 1.0) { // If last cout was more than 1 sec ago
            double fps = double(frame) / delta;
            std::cout << fps << std::endl;
            frame = 0;
            lastTime = currentTime;
        }

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        physicsEngine.update();
        physicsEngine.render();

        glfwSwapBuffers(window);
    }

    // Terminate GLFW, clearing any resources allocated by GLFW.
    glfwTerminate();
    return EXIT_SUCCESS;
}