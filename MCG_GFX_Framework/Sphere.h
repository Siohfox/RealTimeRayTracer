#pragma once

#include "Colour.h"
#include "GLM/glm.hpp"
#include "Ray.h"

class Sphere
{
public:
	
	Colour ShadePixel(Ray _ray, glm::vec3 _intersection);

};

