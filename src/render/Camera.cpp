#include "render/Camera.h"

#include <glm/ext.hpp>

Camera::Camera(float fovd, float near, float far, float aspect)
	: m_FOVd(fovd), m_Near(near), m_Far(far), m_AspectRatio(aspect),
	  m_Position(glm::vec3(0, 0, 0)), m_Orientation(glm::vec3(0, 0, 1)),
	  m_Up(glm::vec3(0, 1, 0)), m_Viewproj(glm::mat4(1)) {  }

void Camera::setPosition(float x, float y, float z) {
	m_Position = glm::vec3(x, y, z);
}

void Camera::setOrientation(float x, float y, float z) {
	m_Orientation = glm::vec3(x, y, z);
}

glm::mat4& Camera::updateMatrix() {
	glm::mat4 view = glm::lookAt(m_Position, m_Position + m_Orientation, m_Up);
	glm::mat4 proj = glm::perspective(glm::radians(m_FOVd), m_AspectRatio, m_Near, m_Far);

	m_Viewproj = proj * view;
	return m_Viewproj;
}
