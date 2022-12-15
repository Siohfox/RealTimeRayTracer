#pragma once

#include "GLM/glm.hpp"

class Colour
{
public:
	/**
	 * @brief Default colour constructor
	*/
	Colour();

	/**
	 * @brief Colour constructor
	 * @param colour the colour to be set to
	*/
	Colour(glm::vec3 colour);

	glm::vec3 m_colour; ///< Colour to be held as a vec 3
	
};

