#pragma once

#include <GLFW/glfw3.h>

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

class Input {
private:
	static Input* m_Ptr;

	Input();
public:
	Input(const Input& obj) = delete;

	static Input* getInstance();

	bool keys[1024];
};
