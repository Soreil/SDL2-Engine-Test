#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include "Text.h"
#include "Input.h"
#include "Player.h"
#include "StateManager.h"


class App {
 public:
  const int WINDOW_WIDTH =  800;
  const int WINDOW_HEIGHT = 600;
  
  SDL_Window * window = nullptr;
  
  SDL_Surface* screenSurface = nullptr;
  SDL_Renderer* renderer = nullptr;
  
  SDL_Rect windowRect{0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};

  TTF_Font* gFont = nullptr;
  TextHandler* text = nullptr;  
 
  //Mix_Music* mus;

  
  //Event handler
  SDL_Event e;
  
  bool running;

  //used for calculating DT
  int currTicks = 0;
  int prevTicks = 0;

  float deltaTime;
  
  const int FRAMERATE = 60;
  
  GameStateManager* stateManager = nullptr;

 
  bool startup();
  
  void Load();
  
  void Update();
  
  void Render();
  
  void cleanup();
  
  void run();

   App();
  ~App();
};

