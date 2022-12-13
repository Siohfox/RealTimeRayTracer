#include <cmath>
#include "MCG_GFX_Lib.h"
#include <iostream>
#include "GLM/ext.hpp"
#include "Camera.h"
#include "Tracer.h"
#include <list>
#include <vector>



int main( int argc, char *argv[] )
{
	// Variable for storing window dimensions
	glm::ivec2 windowSize( 640, 480 );

	// Call MCG::Init to initialise and create your window
	// Tell it what size you want the window to be
	if( !MCG::Init( windowSize ) )
	{
		// Check if not good
		return -1;
	}

	// Sets every pixel to the same colour
	// parameters are RGB, numbers are from 0 to 1
	MCG::SetBackground( glm::vec3(0,0,0) );

	// Preparing a position to draw a pixel
	glm::ivec2 pixelPosition = windowSize / 2;

	// Preparing a colour to draw
	// Colours are RGB, each value ranges between 0 and 1
	glm::vec3 pixelColour( 1, 0, 0 );

	// Advanced access - comment out the above DrawPixel and MCG::ShowAndHold lines, then uncomment the following:
	
	// Variable to keep track of time
	float timer = 0.0f;



	/***********************************************************
	*  MY STUFF
	************************************************************/

	//Camera m_cam(glm::vec3(0.0f, -10.0f, -7.0f), glm::vec3(10.0f, 0.0f, 0.0f), 40.0f, glm::vec3(1, 0, 0), true);

	//std::vector< glm::ivec2> pixelCoords;
	Camera cam;
	Tracer tracer;

	Sphere sphere();

	

	// This is our game loop
	// It will run until the user presses 'escape' or closes the window
	while( MCG::ProcessFrame() )
	{
		// Set every pixel to the same colour
		MCG::SetBackground(glm::vec3(0, 0, 0));

		for (size_t x = 0; x < windowSize.x; x++)
		{
			for (size_t y = 0; y < windowSize.y; y++)
			{
				glm::ivec2 pos(x, y);

				Ray r = cam.CreateRay(pos);
			
				glm::vec3 colour = tracer.Trace(r);

				MCG::DrawPixel(pos, colour);
			}
		}

		

		//// Change our pixel's X coordinate according to time
		//pixelPosition.x = (windowSize.x / 2) + (int)(sin(timer) * 100.0f);
		//// Update our time variable
		timer += 1.0f / 60.0f;
		std::cout << timer << "\n";

		// Draw the pixel to the screen
		//MCG::DrawPixel( pixelPosition, pixelColour );

	}

	return 0;

}
