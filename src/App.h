#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include "EntityManager.h"

#include "Text.h"

#include "World.h"

#include "StateManager.h"

#include "Sprite.h"


class Entity;


class App {
 public:
  const int WINDOW_WIDTH =  800;
  const int WINDOW_HEIGHT = 600;
  
  SDL_Window * window = nullptr;
  SDL_Surface* screenSurface = nullptr;
  SDL_Renderer* renderer = nullptr;
  
  SDL_Rect windowRect{0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};

  StateManager stateManager;
  
  
  TTF_Font* gFont = nullptr;
  TextHandler* text = nullptr;  
  
  Entity* player = nullptr;
  
  Mix_Music* mus;
  
  //Event handler
  SDL_Event e;
  
  bool running;
  
  const int FRAMERATE = 60;
  int frametime = 0;  
  
  App();
  
  bool startup();
  
  void Load();
  
  void Update();
  
  void Render();
  
  void cleanup();
  
  void run();
  
  ~App();
};

