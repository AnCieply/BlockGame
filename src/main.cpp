#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <iostream>

#include "render/Camera.h"
#include "render/Renderer.h"
#include "render/Texture.h"

#include "base/ResourceManager.h"
#include "base/Time.h"
#include "base/Input.h"

#include "game/Chunk.h"
#include "game/Player.h"
#include "game/Block.h"

void GLAPIENTRY openGLMessageCallback(GLenum source, GLenum type, GLuint id,  GLenum severity,
    GLsizei length, const GLchar* message, const void* userParam) {
    fprintf(stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
        (type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""),
        type, severity, message);
}

void errorCallback(int error, const char* description) {
    std::cerr << "GLFW error: " << description << "\n";
}

static void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
    GLFWwindow* window;

    glfwSetErrorCallback(errorCallback);

    if (!glfwInit()) {
        std::cerr << "GLFW Error: Failed to initialize GLFW.\n";
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    window = glfwCreateWindow(640, 480, "Block Game", nullptr, nullptr);
    if (!window) {
        std::cerr << "GLFW Error: Failed to create window.\n";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, keyCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    // glfwSetCursorPosCallback(window, mousePositionCallback);

    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "GLAD error: Failed to load OpenGL functions.\n";
        glfwTerminate();
        return -1;
    }

    glfwSwapInterval(1);

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    glClearColor(float(26.0f / 255), float(133.0f / 255), float(255.0f / 255), 1.0f);

    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(openGLMessageCallback, 0);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

    Renderer* rend = Renderer::getInstance();
    Input* inp = Input::getInstance();
    Time* tm = Time::getInstance();

    Texture chunkMapTexture = ResourceManager::createTexture("ChunkMap", "res/textures/terrain.png");
    Shader basicShader = ResourceManager::createShaderProgram("Basic", "res/shaders/basicvertex.glsl", "res/shaders/basicfrag.glsl");

    Player plyr;
    plyr.setPosition(0, 0, 3);

    Chunk testChunk;
    testChunk.generate();
     
    while (!glfwWindowShouldClose(window)) {
        tm->calcDeltaTime();
        // Update input.
        double xPos, yPos;
        glfwGetCursorPos(window, &xPos, &yPos);
        inp->updateMouseDeltas(xPos, yPos);

        if (inp->isMouseButtonPressed(GLFW_MOUSE_BUTTON_1)) {
            plyr.rotate(-inp->getMouseDeltaY() * 0.25f, -inp->getMouseDeltaX() * 0.25f);
        }
          
        if (inp->isKeyPressed(GLFW_KEY_ESCAPE)) {
            glfwSetWindowShouldClose(window, true);
        }

        // Temporary input.
        if (inp->isKeyPressed(GLFW_KEY_W))
            plyr.move(0.0f, 0.0f, -1.0f);
        if (inp->isKeyPressed(GLFW_KEY_S))
            plyr.move(0.0f, 0.0f, +1.0f);
        if (inp->isKeyPressed(GLFW_KEY_A))
            plyr.move(-1.0f, 0.0f, 0.0f);
        if (inp->isKeyPressed(GLFW_KEY_D))
            plyr.move(+1.0f, 0.0f, 0.0f);
        if (inp->isKeyPressed(GLFW_KEY_SPACE))
            plyr.move(0.0f, +1.0f, 0.0f);
        if (inp->isKeyPressed(GLFW_KEY_LEFT_CONTROL))
            plyr.move(0.0f, -1.0f, 0.0f);

        basicShader.setMat4("viewproj", plyr.getCamMatrix());

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // rend->render(testMesh, basicShader, chunkMapTexture);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    ResourceManager::clear();

    glfwTerminate();
    return 0;
}
