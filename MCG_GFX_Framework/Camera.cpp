#include "Camera.h"

Camera::Camera()
{
	
}

Ray Camera::CreateRay(glm::ivec2 pixelCoord)
{
	/*Ray myRay(glm::vec3(0), glm::vec3(0));
	myRay.m_origin = glm::vec3(pixelCoord.x, pixelCoord.y, 0);
	myRay.m_direction = glm::vec3(0, 0, -1);*/

	Ray myRay(glm::vec3(pixelCoord.x, pixelCoord.y, 0), glm::vec3(0, 0, -1));

	return myRay;
}
