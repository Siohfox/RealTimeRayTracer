#include "Ray.h"

Ray::Ray()
{
	m_origin = glm::vec3(0, 0, 0);
	m_direction = glm::vec3(1, 0, 0);
}

Ray::Ray(glm::vec3 _origin, glm::vec3 _direction)
{
	m_origin = _origin;
	m_direction = _direction;
}