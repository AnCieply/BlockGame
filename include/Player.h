#pragma once

#include <glm/glm.hpp>

class Player {
private:
	glm::vec3 m_Position;
public:
	Player();

	void setPosition(float x, float y, float z);
	void move(float dX, float dY, float dZ);
};
