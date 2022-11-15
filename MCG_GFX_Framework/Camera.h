#pragma once
#include "GLM/glm.hpp"

class Camera
{
public:
	Camera();

	Camera(glm::vec3 _position, glm::vec3 _direction, glm::vec3 _right, glm::vec3 _down);

	glm::vec3 getCameraPosition() { return m_camPosition; }
	glm::vec3 getCameraDirection() { return m_camDirection; }
	glm::vec3 getCameraRight() { return m_camRight; }
	glm::vec3 getCameraDown() { return m_camDown; }

private:
	glm::vec3 m_camPosition, m_camDirection, m_camRight, m_camDown;
};