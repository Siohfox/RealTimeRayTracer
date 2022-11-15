#include <cmath>
#include "MCG_GFX_Lib.h"
#include <iostream>
#include "GLM/ext.hpp"
#include "Camera.h"



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

	glm::vec3 X (1, 0, 0), Y (0, 1, 0), Z(0, 0, 1);

	glm::vec3 camPos(3, 1.5, -4);

	glm::vec3 lookAt(0, 0, 0);

	glm::vec3 diffBetweenCamAndTarget(camPos.x - lookAt.x, camPos.y - lookAt.y, camPos.z - lookAt.z);

	glm::vec3 cameraDirection = glm::normalize(-diffBetweenCamAndTarget);
	glm::vec3 cameraRight = glm::normalize(glm::cross(X, cameraDirection));
	glm::vec3 cameraDown = glm::cross(cameraRight, cameraDirection);

	Camera sceneCam(camPos, cameraDirection, cameraRight, cameraDown);



	// This is our game loop
	// It will run until the user presses 'escape' or closes the window
	while( MCG::ProcessFrame() )
	{
		

		// Set every pixel to the same colour
		MCG::SetBackground( glm::vec3(0,0,0) );

		//// Change our pixel's X coordinate according to time
		//pixelPosition.x = (windowSize.x / 2) + (int)(sin(timer) * 100.0f);
		//// Update our time variable
		//timer += 1.0f / 60.0f;

		// Draw the pixel to the screen
		MCG::DrawPixel( pixelPosition, pixelColour );

	}

	return 0;

}
