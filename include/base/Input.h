#pragma once

#include <GLFW/glfw3.h>

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

class Input {
private:
	static Input* m_Ptr;

	bool m_Keys[1024];

	Input();
public:
	Input(const Input& obj) = delete;

	static Input* getInstance();

	void setKeyStatus(int key, bool status);
	
	bool isKeyPressed(int key);
};
