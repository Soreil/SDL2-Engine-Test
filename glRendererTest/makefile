OBJS = main.cpp $(wildcard src/*.cpp)

GLAD_OBJS = C:\dev_libs\include\GL\glad\src\glad.c

OBJ_NAME = build/main

INCLUDE_PATHS = -IC:\dev_libs\include\SDL2 -IC:\dev_libs\include\GL -Isrc

LIBRARY_PATHS = -LC:\dev_libs\lib

COMPILER_FLAGS = -w 
#These flags are left out for debug builds
#-Wl,-subsystem,windows

LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_mixer -lSDL2_ttf -lOpenGL32
#	This flag is left out for debug builds
#-mwindows

# When adding SDL_Mixer (Or possibly SDL_Image) add flag -SDL_Mixer (Or -SDL_Image for SDL_Image obviously)

STD = -std=c++11

all: $(OBJS)
	g++ $(OBJS) $(GLAD_OBJS)  $(STD) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(LINKER_FLAGS) $(COMPILER_FLAGS) -o $(OBJ_NAME)
