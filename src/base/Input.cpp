#include "base/Input.h"

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    Input* input = Input::getInstance();

    if (action == GLFW_PRESS) {
        input->setKeyStatus(key, true);
    } else if (action == GLFW_RELEASE) {
        input->setKeyStatus(key, false);
    }
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    Input* input = Input::getInstance();

    if (action == GLFW_PRESS) {
        input->setMouseButtonStatus(button, true);
    } else if (action == GLFW_RELEASE) {
        input->setMouseButtonStatus(button, false);
    }
}

Input* Input::m_Ptr = nullptr;

Input::Input()
    : m_Keys{0} {  }

Input* Input::getInstance() {
    if (m_Ptr == nullptr) {
        m_Ptr = new Input();
        return m_Ptr;
    } else {
        return m_Ptr;
    }
}

void Input::setKeyStatus(int key, bool status) {
    m_Keys[key] = status;
}

void Input::setMouseButtonStatus(int button, bool status) {
    m_MouseButtons[button] = status;
}

bool Input::isKeyPressed(int key) {
    return m_Keys[key];
}

bool Input::isMouseButtonPressed(int button) {
    return m_MouseButtons[button];
}
