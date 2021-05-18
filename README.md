# SDLGame Project
How u doin!? So I decided to make a SDLGame which just displays some grass blocks and no controls. Remember im gonna have to wait until codergopher updates his SDL2 tutorial
So to install the game ~~(only on linux sorry windows users)~~
NOT TRUE I FOUND OUT MY CODE WORKS ON WINDOWS JUST USE WINDOWS 7 IF U DONT HAVE WINDOWS 7 AND UR USING WINDOWS 10 USE WSL AND FOLLOW LINUX STEPS WINDOWS 7 WILL BE LINKED [HERE](https://github.com/hdfsyu/SDLGame-windows)
Install libsdl2-dev, libsdl2-2.0-0, libsdl2-image-dev, libsdl2-mixer-dev, libsdl2-ttf-dev.
And type this command (in the root of SDLGame):
`make`
That will compile everything and run the game when u close the game copy the res folder to /bin/debug/ NOT RELEASE!
# Running
just go to the bin/debug folder and type `./main`
PLEASE DO NOT EDIT ANY FILES.
# Running 2
I found out my code is compatible with EmScripten...
To compile it with emscripten instead of make run `emcc src/*.cpp -I include -O2 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s "SDL2_IMAGE_FORMATS=['png']" -s USE_SDL_TTF=2 -s USE_SDL_MIXER=2 -std=c++14 --preload-file res -o index.html` in the root of the project (its the same command for all operating systems)
To play it (without doing crazy stuff go [here](https://hdfsyu.itch.io/sdlgame) and then go to the description of the page.
# pull requests
Sure but not yet because ik what people will say already and remember **I CANT MAKE IT BETTER UNTIL CODER GOPHER UPDATES HIS SDL2 TUTORIAL** ok now **bai**
