#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Utils.hpp"
// welcome to the weirdest main.cpp file u have ever seen.

// Main function
int main(int argc, char* args[])
{
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;

	if (!(IMG_Init(IMG_INIT_PNG)))
		std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;

	RenderWindow window("GAME v1.0", 1280, 720);


	SDL_Texture* grassTexture = window.loadTexture("res/gfx/grass_texture_1.png");

	// this is just some left over code so dont worry about this crap
    // Entity entities[4] = {Entity(0, 0, grassTexture),
    //                       Entity(30, 0, grassTexture),
    //                       Entity(30, 30, grassTexture),
    //                       Entity(30, 60, grassTexture)};
    std::vector<Entity> entities = {Entity(Vector2f(0, 0), grassTexture),
                         			 Entity(Vector2f(30, 0), grassTexture),
                          			 Entity(Vector2f(30, 30), grassTexture),
                          			 Entity(Vector2f(30, 60), grassTexture)};
    {
	    Entity wilson(Vector2f(100, 50), grassTexture);

	    entities.push_back(wilson);
	    
	}
	bool gameRunning = true;

	SDL_Event event;

	const float timeStep = 0.01f;
	float accumulator = 0.0f;
	float currentTime = utils::hireTimeInSeconds();
	// main loop (which just repeats and repeats)
	while (gameRunning)
	{
		int startTick = SDL_GetTicks();

		float newTime = utils::hireTimeInSeconds();
		float frameTime = newTime - currentTime;

		currentTime = newTime;

		accumulator += frameTime;

		while(accumulator >= timeStep)
		{
		// Get our controls and events
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				gameRunning = false;
		}

		accumulator -= timeStep;

	}

	const float alpha = accumulator / timeStep;


		// clear some junk because we dont need it
		window.clear();
		

		for (Entity& e : entities)
		{ // renderer to render entities
			window.render(e);
		}

		std::cout << utils::hireTimeInSeconds() << std::endl;

		window.display();


		int frameTicks = SDL_GetTicks() - startTick;

		if (frameTicks < 1000 / window.getRefreshRate())
			SDL_Delay(1000 / window.getRefreshRate() - frameTicks);

	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}
// amperstand bank
// &&&&&&&&&&&&&&&&&&
// &&&&&&&&&&&&&&&&&&
// &&&&&&&&&&&&&&&&&&
// &&&&&&&&&&&&&&&&&&
// &&&&&&&&&&&&&&&&&&
// &&&&&&&&&&&&&&&&&&