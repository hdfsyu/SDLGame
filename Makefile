main: src/*.cpp
	g++ -c src/*.cpp -std=c++14 -m64 -g -Wall -I include && g++ *.o -o bin/debug/main -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf && ./bin/debug/main	

.PHONY: win32

win32:
	g++ -c src/*.cpp -std=c++14 -g -Wall -m64 -I include -I C:/SDL2-w64/include && g++ *.o -o bin/debug/main -L C:/SDL2-w64/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf && start bin/debug/main

.PHONY: emcc

emcc:
	emcc src/*.cpp -I include -O2 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s "SDL2_IMAGE_FORMATS=['png']" -s USE_SDL_TTF=2 -s USE_SDL_MIXER=2 -std=c++14 --preload-file res -o index.html
