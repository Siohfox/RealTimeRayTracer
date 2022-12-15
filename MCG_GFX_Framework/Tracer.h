#ifndef _TRACER_H
#define _TRACER_H

#include "Ray.h"
#include "MCG_GFX_Lib.h"
#include "Sphere.h"
#include "Colour.h"
#include "Camera.h"
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

	/**
	 * @brief A mathematic function to get the closest point
	 * @param _ray 
	 * @param _point 
	 * @return 
	*/
	glm::vec3 GetClosestPointToLine(Ray _ray, glm::vec3 _point);

	/**
	 * @brief A function to test for an intersection between a ray and a sphere
	 * @param _ray The ray to test for intersection
	 * @param _sphere The sphere the ray will intersect with
	 * @return An intersection with information on if it hit and at what point
	*/
	Intersect RaySphereIntersect(Ray _ray, Sphere _sphere);

	/**
	 * @brief Adds a sphere to the vector of spheres
	 * @param sphere The sphere to pass in
	*/
	void AddSphere(Sphere sphere);

private:
	Sphere m_sphere;
	std::vector<Sphere> m_spheres;
	glm::vec3 m_closestPoint;
	glm::vec3 m_origin;
	glm::vec3 m_a;
};

#endif // !_TRACER_H