#include "Player.h"

#include "base/Time.h"

Player::Player()
	: m_Position(glm::vec3(0)) {  }

void Player::setPosition(float x, float y, float z) {
	m_Position = glm::vec3(x, y, z);
}

void Player::move(float dX, float dY, float dZ) {
	Time* tm = Time::getInstance();
	m_Position.x += (dX * tm->getDeltaTime());
	m_Position.y += (dY * tm->getDeltaTime());
	m_Position.z += (dZ * tm->getDeltaTime());
}
