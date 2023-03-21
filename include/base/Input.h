#pragma once

#include <GLFW/glfw3.h>

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
void mousePositionCallback(GLFWwindow* window, double xpos, double ypos);

class Input {
private:
	static Input* m_Ptr;

	bool m_Keys[1024];
	bool m_MouseButtons[1024];

	float m_MouseDeltaX;
	float m_PrevMouseX;
	float m_MouseDeltaY;
	float m_PrevMouseY;

	Input();
public:
	Input(const Input& obj) = delete;

	static Input* getInstance();

	void setKeyStatus(int key, bool status);
	void setMouseButtonStatus(int button, bool status);
	
	bool isKeyPressed(int key);
	bool isMouseButtonPressed(int button);

	void updateMouseDeltas(float dX, float dY);
	float getMouseDeltaX();
	float getMouseDeltaY();
};
