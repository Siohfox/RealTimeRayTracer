#ifndef _TRACER_H
#define _TRACER_H

#include "Ray.h"
#include "MCG_GFX_Lib.h"

class Tracer
{
public:
	glm::vec3 Trace(Ray _ray);

	glm::vec3 GetClosestPointToLine(Ray _ray, glm::vec3 _point);

	bool RaySphereIntersect(Ray _ray, glm::vec3 _centre, int _radius);
};

#endif // !_TRACER_H