#include "game/Player.h"

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>

#include "base/Time.h"

Player::Player()
	: m_Position(glm::vec3(0)), m_Direction(glm::vec3(0, 0, 1)),
	  m_Up(glm::vec3(0, 1, 0)),
	  m_Cam(90.0f, 0.01f, 1000.0f, 4.0f / 3.0f) {  }

void Player::setPosition(float x, float y, float z) {
	m_Position = glm::vec3(x, y, z);
	m_Cam.setPosition(x, y, z);
}

glm::vec3& Player::getPosition() {
	return m_Position;
}

glm::vec3& Player::getDirection() {
	return m_Direction;
}

void Player::move(float dX, float dY, float dZ) {
	Time* tm = Time::getInstance();
	glm::vec3 deltaPos(dX, dY, dZ);

	m_Position += (-dZ * tm->getDeltaTime() * m_Direction);
	m_Position += (dX * tm->getDeltaTime() * glm::normalize(glm::cross(m_Direction, m_Up)));

	m_Position.y += (dY * tm->getDeltaTime());

	// Sync cam with player.
	m_Cam.setPosition(m_Position.x, m_Position.y, m_Position.z);
}

void Player::rotate(float dX, float dY) {
	Time* tm = Time::getInstance();
	// Around x-axis
	glm::vec3 normal = glm::normalize(glm::cross(m_Direction, m_Up));
	m_Direction = glm::rotate(m_Direction, glm::radians(dX), normal);
	// Around y-axis
	m_Direction = glm::rotate(m_Direction, glm::radians(dY), m_Up);
	// Sync cam with player.
	m_Cam.setOrientation(m_Direction.x, m_Direction.y, m_Direction.z);
}

glm::mat4& Player::getCamMatrix() {
	return m_Cam.updateMatrix();
}
