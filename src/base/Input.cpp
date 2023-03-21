#include "base/Input.h"

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    Input* input = Input::getInstance();

    if (action == GLFW_PRESS) {
        input->keys[key] = true;
    } else if (action == GLFW_RELEASE) {
        input->keys[key] = false;
    }
}

Input* Input::m_Ptr = nullptr;

Input::Input()
    : keys{0} {  }

Input* Input::getInstance() {
    if (m_Ptr == nullptr) {
        m_Ptr = new Input();
        return m_Ptr;
    } else {
        return m_Ptr;
    }
}
