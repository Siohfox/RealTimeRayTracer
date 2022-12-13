#ifndef _LIGHT_H
#define _LIGHT_H

#include "GLM/glm.hpp"
#include "Colour.h"

class Colour;

class Light
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
