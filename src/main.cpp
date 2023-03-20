#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <glm/ext.hpp>
#include <iostream>

#include "render/Renderer.h"
#include "render/ResourceManager.h"
#include "render/Texture.h"

static Vertex quadVertices[] = {
    { 0.0f, 0.0f, 0.0f, 255, 255, 255, 255, 0, 0 },
    { 1.0f, 0.0f, 0.0f, 255, 255, 255, 255, 65535, 0 },
    { 0.0f, 1.0f, 0.0f, 255, 255, 255, 255, 0, 65535 },
    { 0.0f, 1.0f, 0.0f, 255, 255, 255, 255, 0, 65535 },
    { 1.0f, 0.0f, 0.0f, 255, 255, 255, 255, 65535, 0 },
    { 1.0f, 1.0f, 0.0f, 255, 255, 255, 255, 65535, 65535 }
};

void GLAPIENTRY openGLMessageCallback(GLenum source, GLenum type, GLuint id,  GLenum severity,
    GLsizei length, const GLchar* message, const void* userParam) {
    fprintf(stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
        (type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""),
        type, severity, message);
}

void errorCallback(int error, const char* description) {
    std::cerr << "GLFW error: " << description << "\n";
}

static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
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

    Renderer* rend = Renderer::getInstance();

    Texture testTexture = ResourceManager::createTexture("test", "res/textures/terrain.png");
    Shader testShader = ResourceManager::createShaderProgram("basic", "res/shaders/basicvertex.glsl", "res/shaders/basicfrag.glsl");

    Mesh testMesh;
    for (int i = 0; i < 6; i++) {
        testMesh.addVertex(quadVertices[i]);
    }
    testMesh.build();

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        rend->render(testMesh, testShader, testTexture);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    ResourceManager::clear();

    glfwTerminate();
    return 0;
}