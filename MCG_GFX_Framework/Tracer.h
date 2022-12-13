#ifndef _TRACER_H
#define _TRACER_H

#include "Ray.h"
#include "Light.h"
#include "MCG_GFX_Lib.h"
#include "Sphere.h"
#include "Colour.h"
#include <vector>

struct Intersect
{
public:
	bool hit;
	glm::vec3 intersectPoint1, intersectPoint2;
};


class Tracer
{
public:
	Tracer();

	Colour Trace(Ray _ray);

	glm::vec3 GetClosestPointToLine(Ray _ray, glm::vec3 _point);

	Intersect RaySphereIntersect(Ray _ray, Sphere _sphere);

private:
	Sphere m_sphere;
	Light light;
	glm::vec3 m_closestPoint;
	glm::vec3 m_origin;
	glm::vec3 m_a;
};

#endif // !_TRACER_H