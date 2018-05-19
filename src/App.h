#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include "EntityManager.h"

class Entity;

class App {
 public:
  const int WINDOW_WIDTH =  800;
  const int WINDOW_HEIGHT = 600;
  
  SDL_Window * window = nullptr;
  SDL_Surface* screenSurface = nullptr;
  SDL_Renderer* renderer = nullptr;
  
  SDL_Rect windowRect{0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};

  EntityManager entityManager;
  
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

