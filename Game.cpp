//INCLUDES & START OF CODE
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "ECS/Components.h"
Map* map;
Manager manager;
SDL_Renderer* Game::renderer = nullptr;
auto& player(manager.addEntity());
// Handling the stuff i added in game.h, like Game() constructors and deconstructors
Game::Game()
{}
Game::~Game()
{}
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0; // this is the Uint32 flags
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}
	//if (SDL_WINDOW_RESIZABLE) {
		//flags = SDL_WINDOW_RESIZABLE;
	//}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "SDL Initialised!" << std::endl; // ultimate semicolon
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) {
			std::cout << "Window Created!" << std::endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer Created!" << std::endl;
		}
		isRunning = true;
	}
	else {
		isRunning = false;
	}
	map = new Map();
	player.addComponent<PositionComponent>(100,500); // this sets the player start pos
	player.addComponent<SpriteComponent>("assets/player.png"); // for now this is the only thing you can play around with, the next version (v2.5) will be the complete release
}
void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type){
		case SDL_QUIT:
			isRunning = false;
			break;
	default:
		break;
	}
}
void Game::update() {
	manager.refresh();
	manager.update();
}
void Game::render() {
	SDL_RenderClear(renderer);
	map->DrawMap();
	manager.draw();
	SDL_RenderPresent(renderer);
}
void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Bye! (Everything is destroyed (like renderers))" << std::endl;
}
