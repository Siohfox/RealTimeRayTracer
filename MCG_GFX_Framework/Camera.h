#pragma once
#include "GLM/glm.hpp"
#include "Ray.h"

class Camera
{
public:
	/** Camera default constructor
   */
	Camera();

	Ray CreateRay(glm::ivec2 pixelCoord);

private:

};