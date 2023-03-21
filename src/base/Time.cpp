#include "base/Time.h"

#include <GLFW/glfw3.h>

Time* Time::m_Ptr = nullptr;

Time::Time() 
	: m_DeltaTime{0}, m_LastFrame{0} {  }

Time* Time::getInstance() {
	if (m_Ptr == nullptr) {
		m_Ptr = new Time();
		return m_Ptr;
	} else {
		return m_Ptr;
	}
}

void Time::calcDeltaTime() {
	float currentFrame = glfwGetTime();
	m_DeltaTime = currentFrame - m_LastFrame;
	m_LastFrame = currentFrame;
}

float Time::getDeltaTime() {
	return m_DeltaTime;
}
