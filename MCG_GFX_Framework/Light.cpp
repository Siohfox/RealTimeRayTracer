#include "Light.h"

Light::Light()
{
	m_position = glm::vec3(0, 0, 0);
	m_colour = Colour(glm::vec3(1, 1, 1));
}

Light::Light(glm::vec3 position, Colour colour)
{
	m_position = position;
	m_colour = colour;
}