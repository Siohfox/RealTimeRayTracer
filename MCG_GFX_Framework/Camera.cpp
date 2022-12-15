#include "Camera.h"
#include "GLM/ext.hpp"


Camera::Camera()
{
	//m_identity = glm::perspective(glm::radians(45.0f), (float)600 / (float)600, 0.1f, 100.f);
	m_position = glm::vec3{ 0.0f };
	m_orientation = glm::vec3{ 0.0f };

	//glm::perspective
}

/**
 * @brief Creates a ray at a given pixel coordinate and sends it in the negative z direction
 * @param pixelCoord The pixel to fire a ray from
 * @return The ray which was fired
*/
Ray Camera::CreateRay(glm::ivec2 pixelCoord)
{
	Ray myRay(glm::vec3(pixelCoord.x, pixelCoord.y, 0), glm::vec3(0, 0, -1));

	return myRay;
}
