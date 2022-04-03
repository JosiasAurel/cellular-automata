
default:
	g++ game.cpp $(RAYLIB_PATH)\src\raylib.rc.data -s -static -Os -Wall -I$(RAYLIB_PATH)\src -Iexternal -lraylib -lopengl32 -lgdi32 -lwinmm -o game
