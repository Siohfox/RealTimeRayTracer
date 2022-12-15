#pragma once
#include "GLM/glm.hpp"
#include "Ray.h"

class Camera
{
public:
	/** Camera default constructor
   */
	Camera();

	/**
	 * @brief Creates a ray at a given coordinate, fired in the -Z direction
	 * @param pixelCoord The pixel coordinate to fire a ray from
	 * @return The ray created
	*/
	Ray CreateRay(glm::ivec2 pixelCoord);

	/**
	 * @brief Sets the projection of the camera
	 * @param the projection to be set to
	*/
	void SetProjection(glm::mat4 projection) { m_identity = projection; }

	/**
	 * @brief Getter for the projection
	 * @return The matrix projection of the camera
	*/
	glm::mat4 GetProjection() { return m_identity; }

	glm::vec3 m_position;
	glm::vec3 m_orientation;
	glm::vec3 m_scale;

	glm::mat4 m_identity = glm::mat4(1.0f); ///< The projection matrix
	glm::mat4 m_view = glm::mat4(1.0f); ///< The viewing matrix
};