#include "Colour.h"

/**
 * @brief A colour constructor, defaulted to white
*/
Colour::Colour()
{
	m_colour = glm::vec3(1.0f, 1.0f, 1.0f);
}

/**
 * @brief A colour constructor
 * @param colour The colour which it will be set to
*/
Colour::Colour(glm::vec3 colour)
{
	m_colour = glm::vec3(colour);
}
