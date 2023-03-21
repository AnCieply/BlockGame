#include "render/Camera.h"

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>

#include <iostream>

Camera::Camera(float fovd, float near, float far, float aspect)
	: m_FOVd(fovd), m_Near(near), m_Far(far), m_AspectRatio(aspect),
	  m_Position(glm::vec3(0, 0, 0)), m_Direction(glm::vec3(0, 0, -1)),
	  m_Up(glm::vec3(0, 1, 0)), m_Viewproj(glm::mat4(1)) {  }

glm::vec3& Camera::getPosition() {
	return m_Position;
}

glm::vec3& Camera::getDirection() {
	return m_Direction;
}

void Camera::rotate(float x, float y, float z) {
	// Around x-axis
	glm::vec3 normal = glm::normalize(glm::cross(m_Direction, m_Up));
	m_Direction = glm::rotate(m_Direction, glm::radians(x), normal);
	// Around y-axis
	m_Direction = glm::rotate(m_Direction, glm::radians(y), m_Up);
	// Around z-axis
}

void Camera::setPosition(float x, float y, float z) {
	m_Position = glm::vec3(x, y, z);
}

void Camera::setOrientation(float x, float y, float z) {
	m_Direction = glm::vec3(x, y, z);
}

glm::mat4& Camera::updateMatrix() {
	glm::mat4 view = glm::lookAt(m_Position, m_Position + m_Direction, m_Up);
	glm::mat4 proj = glm::perspective(glm::radians(m_FOVd), m_AspectRatio, m_Near, m_Far);

	m_Viewproj = proj * view;
	return m_Viewproj;
}
