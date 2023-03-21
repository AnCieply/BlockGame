#pragma once

#include <glm/glm.hpp>

#include "render/Camera.h"

class Player {
private:
	glm::vec3 m_Position;
	glm::vec3 m_Direction;
public:
	Player();

	void setPosition(float x, float y, float z);
	glm::vec3 getPosition();
	void move(float dX, float dY, float dZ);
};
