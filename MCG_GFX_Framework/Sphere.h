#pragma once

#include "Colour.h"
#include "GLM/glm.hpp"
#include "Ray.h"
#include "SceneObject.h"
#include "Camera.h"

class Sphere : SceneObject
{
public:
	Sphere();

	Sphere(glm::vec3 _centre, int _radius);

	Colour ShadePixel(Ray _ray, glm::vec3 _intersection);
	glm::vec3 GetSphereNormal(glm::vec3 samplePoint, Camera cam);

	glm::vec3 m_centre;
	int m_radius;
	Colour m_sphereColour;
private:
	
};

