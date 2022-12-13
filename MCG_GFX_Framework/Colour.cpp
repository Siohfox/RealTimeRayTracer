#include "Colour.h"

Colour::Colour()
{
	m_colour = glm::vec3(1.0f, 1.0f, 1.0f);
}

Colour::Colour(glm::vec3 colour)
{
	m_colour = glm::vec3(colour);
}
