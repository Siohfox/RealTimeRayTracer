#ifndef _RAY_H
#define _RAY_H

#include "glm/glm.hpp"

class Ray
{
public:

	/**
	 * @brief Constructs a ray
	 * @param  The origin of the ray
	 * @param  The direction of the ray
	*/
	Ray(glm::vec3 _origin, glm::vec3 _direction);

	glm::vec3 m_origin, m_direction;	
};

#endif
