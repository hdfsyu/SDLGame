#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
class Game {
public:
	// contructers and deconstructers for Game();
	Game();
	~Game();
	// Init, makes title, xpos, ypos and width and height (basically doing flags for window)
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	// handling events and more stuff (like isRunning and rendering)
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running() { return isRunning; };
	static SDL_Renderer* renderer;
private:
	int cnt;
	bool isRunning;
	SDL_Window* window;
};