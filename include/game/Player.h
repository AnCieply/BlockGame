#pragma once

#include <glm/glm.hpp>

#include "render/Camera.h"

class Player {
private:
	glm::vec3 m_Position;
	glm::vec3 m_Direction;
	glm::vec3 m_Up;

	Camera m_Cam;
public:
	Player();

	void setPosition(float x, float y, float z);
	glm::vec3& getPosition();
	glm::vec3& getDirection();
	void move(float dX, float dY, float dZ);
	void rotate(float dX, float dY);

	glm::mat4& getCamMatrix();
};
