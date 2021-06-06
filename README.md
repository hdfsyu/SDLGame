# SDLGame Project
How u doin!? So I decided to make a SDLGame which just displays some grass blocks and no controls. Remember im gonna have to wait until codergopher updates his SDL2 tutorial
So to install the game ~~(only on linux sorry windows users)~~
NOT TRUE I FOUND OUT MY CODE WORKS ON WINDOWS!
Install libsdl2-dev, libsdl2-2.0-0, libsdl2-image-dev, libsdl2-mixer-dev, libsdl2-ttf-dev. On windows: Install SDL2, SDL2_MIXER, SDL2_IMAGE and SDL2_TTF.
And type this command (in the root of SDLGame):
`make`
That will compile everything and run the game when u close the game copy the res folder to /bin/debug/ NOT RELEASE!
# Running
just go to the bin/debug folder and type `./main` on windows its gonna be `main.exe`
PLEASE DO NOT EDIT ANY FILES.
# Building
I found out my code is compatible with EmScripten...
To compile it with emscripten instead of make run:
`make emcc`
in the root of the project (its the same command for all operating systems)
To play it (without doing crazy stuff go [here](https://hdfsyu.itch.io/sdlgame) and then go to the description of the page.
# Building 2
To run it on windows run:
`make win`
in the root of the project.
If u get an error saying SDL2.dll is missing from ur computer or something like that copy all the dlls from C:\SDL2-w64\bin\ and paste it into debug NOT RELEASE!
# Building 3
I also found out my code is compatible with Mac OS X and higher run `make` to compile it and copy res to bin/debug NOT RELEASE! and it should compile fine
# Installer
using the installer is simple but u gotta do some stuff manually! Take note of the path that u installed it to and go to the path it installed to then make a new folder called res and move the folders dev and gfx into the res folder! Then run the executable (u can change the name of the executable or add it to the PATH enviorment variable) and to get the installer just get it from the releases page of this project, u can also run the installer as administrator to install for all users!
# pull requests
Sure but not yet because ik what people will say already and remember **I CANT MAKE IT BETTER UNTIL CODER GOPHER UPDATES HIS SDL2 TUTORIAL** ok now **bai**
