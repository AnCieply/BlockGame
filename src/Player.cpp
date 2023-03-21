#include "Player.h"

#include "base/Time.h"

Player::Player()
	: m_Position(glm::vec3(0)), m_Direction(glm::vec3(0, 1, 0)) {  }

void Player::setPosition(float x, float y, float z) {
	m_Position = glm::vec3(x, y, z);
}

glm::vec3 Player::getPosition() {
	return m_Position;
}

void Player::move(float dX, float dY, float dZ) {
	Time* tm = Time::getInstance();
	glm::vec3 deltaPos(dX, dY, dZ);

	m_Position += (-dZ * tm->getDeltaTime() * m_Direction);
	m_Position += (dX * tm->getDeltaTime() * glm::normalize(glm::cross(m_Direction, glm::vec3(0, 1, 0))));

	m_Position.y += (dY * tm->getDeltaTime());
}
