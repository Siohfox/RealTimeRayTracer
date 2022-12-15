#pragma once

#include "Colour.h"
#include "GLM/glm.hpp"
#include "Ray.h"
#include "Camera.h"

class Sphere
{
public:
	Sphere();

	/**
	 * @brief Sphere construcotr
	 * @param _centre The centre of the sphere
	 * @param _radius The radius of the sphere
	*/
	Sphere(glm::vec3 _centre, int _radius, Colour col);

	/**
	 * @brief A function that shades a pixel from a ray
	 * @param _ray The ray to use for the pixel to be shaded
	 * @param _intersection The intersection point between the ray and the sphere
	 * @return The colour of the pixel at the intersection point
	*/
	Colour ShadePixel(Ray _ray, glm::vec3 _intersection);

	/**
	 * @brief A function to get the sphere's normal
	 * @param samplePoint The point on the sphere to sample from
	 * @param cam The camera of the scene
	 * @return The sphere's vector normal
	*/
	glm::vec3 GetSphereNormal(glm::vec3 samplePoint, Camera cam);

	// Functions
	glm::vec3 m_centre; //< The centre of the sphere
	int m_radius; //< The radius of the sphere
	Colour m_sphereColour; //< The colour the sphere will be
};

