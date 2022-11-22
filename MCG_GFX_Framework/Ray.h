#ifndef _RAY_H
#define _RAY_H

#include "glm/glm.hpp"

class Ray
{
public:
	Ray();

	Ray(glm::vec3, glm::vec3);

	// Methods
	glm::vec3 getRayOrigin() { return m_origin; }
	glm::vec3 getRayDirection() { return m_direction; }

private:
	glm::vec3 m_origin, m_direction;
};

#endif
