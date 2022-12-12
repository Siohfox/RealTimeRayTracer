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

	void SetProjection(glm::mat4 projection) { m_identity = projection; }

	glm::mat4 GetProjection() { return m_identity; }

private:
	glm::vec3 m_position;
	glm::vec3 m_orientation;
	glm::vec3 m_scale;

	glm::mat4 m_identity = glm::mat4(1.0f); ///< The projection matrix
	glm::mat4 m_view = glm::mat4(1.0f); ///< The viewing matrix
};