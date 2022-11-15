#include "Camera.h"

Camera::Camera()
{
	m_camPosition = glm::vec3(0, 0, 0);
	m_camDirection = glm::vec3(0, 0, 1);
	m_camRight = glm::vec3(0, 0, 0);
	m_camDown = glm::vec3(0, 0, 0);
}

Camera::Camera(glm::vec3 _position, glm::vec3 _direction, glm::vec3 _right, glm::vec3 _down)
{
	m_camPosition = _position;
	m_camDirection = _direction;
	m_camRight = _right;
	m_camDown = _down;
}