#ifndef _RAY_H
#define _RAY_H

#include "glm/glm.hpp"

class Ray
{
public:

	Ray(glm::vec3, glm::vec3);

	glm::vec3 m_origin, m_direction;

private:
	
};

#endif
