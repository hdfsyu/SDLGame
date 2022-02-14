#include "Game.h"
Game* game = nullptr;
int main(int argc, char* argv[]) {
	// FPS cap
	const int FPS = 60; // you might wanna change this to 120 if you have a faster monitor
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;
	// our game loop
	game = new Game();
	game->init("SDLGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
	while (game->running()){
		frameStart = SDL_GetTicks();
		game->handleEvents();
		game->update();
		game->render();
		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}// if you comment out this if statement it will remove the cap, like i said in Game.cpp
	}
	game->clean();
	return 0;
}