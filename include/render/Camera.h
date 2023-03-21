#pragma once

#include <glm/glm.hpp>

class Camera {
private:
	glm::vec3 m_Position;
	glm::vec3 m_Direction;
	glm::vec3 m_Up;

	glm::vec3 m_Rotation;

	glm::mat4 m_Viewproj;

	float m_FOVd;
	float m_Near;
	float m_Far;
	float m_AspectRatio;
public:
	Camera(float fovd, float near, float far, float aspect);

	glm::vec3& getPosition();
	glm::vec3& getDirection();

	void rotate(float x, float y, float z);
	void setPosition(float x, float y, float z);
	void setOrientation(float x, float y, float z);
	glm::mat4& updateMatrix();
};
