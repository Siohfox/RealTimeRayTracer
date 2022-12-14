#ifndef _LIGHT_H
#define _LIGHT_H

#include "GLM/glm.hpp"
#include "Colour.h"
#include "SceneObject.h"

class Colour;

class Light : SceneObject
{
public:
	Light();

	Light(glm::vec3, Colour);

	// Methods
	glm::vec3 getLightPosition() { return m_position; }
	Colour getLightColour() { return m_colour; }

private:
	glm::vec3 m_position;
	Colour m_colour;
};

#endif
