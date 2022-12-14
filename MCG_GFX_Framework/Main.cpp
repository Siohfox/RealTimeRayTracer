#include <cmath>
#include "MCG_GFX_Lib.h"
#include <iostream>
#include "GLM/ext.hpp"
#include "Camera.h"
#include "Tracer.h"
#include "Colour.h"
#include <chrono>
#include <list>
#include <vector>
#include <thread>
#include <mutex>


void DoThing(glm::ivec2 windowSize, Camera _cam, Tracer tracer, std::mutex* mutex, int threadCount)
{
	// Set every pixel to the same colour
	MCG::SetBackground(glm::vec3(0, 0, 0));
	for (size_t j = 0; j < threadCount; j++)
	{
		for (size_t i = 0; i < threadCount; i++)
			{
			for (size_t x = 0; x < windowSize.x / threadCount; x++)
				{
					for (size_t y = 0; y < windowSize.y / threadCount; y++)
					{
						glm::ivec2 pos(x + (windowSize.x / threadCount) * i, y + (windowSize.y / threadCount) * j);

						Ray r = _cam.CreateRay(pos);

						Colour colour = tracer.Trace(r);

						mutex->lock();
						MCG::DrawPixel(pos, colour.m_colour);
						mutex->unlock();
					}
				}
		}
	}
	
		
}

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

	std::mutex* mtx = new std::mutex;



	/***********************************************************
	*  MY STUFF
	************************************************************/

	//Camera m_cam(glm::vec3(0.0f, -10.0f, -7.0f), glm::vec3(10.0f, 0.0f, 0.0f), 40.0f, glm::vec3(1, 0, 0), true);

	//std::vector< glm::ivec2> pixelCoords;
	Camera cam;
	Tracer tracer;

	// get time at point
	std::chrono::steady_clock::time_point time1 = std::chrono::high_resolution_clock::now();

	// Spawn threads, do stuff
	std::vector<std::thread> threads;

	int threadCount = 20;

	for (int i = 0; i < threadCount; i++)
	{
		threads.emplace_back(DoThing, windowSize, cam, tracer, mtx, threadCount);
	}

	// Join all threads at end
	for (int i = 0; i < threads.size(); i++)
	{
		threads[i].join();
	}

	std::chrono::steady_clock::time_point time2 = std::chrono::high_resolution_clock::now();
	std::chrono::milliseconds milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(time2 - time1);

	std::cout << "Time taken: " << milliseconds.count() << std::endl;
	// This is our game loop
	// It will run until the user presses 'escape' or closes the window
	while( MCG::ProcessFrame() )
	{
		
	}

	return 0;

}