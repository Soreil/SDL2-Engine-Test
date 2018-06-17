#pragma once

#include <SDL.h>
#include "State.h"
#include "Sprite.h"

class PlayingState : public State {
 public:

  void onEnterState();
  void onExitState();

  void handleEvents();

  void update(float deltaTime);
  void render(SDL_Renderer* r);

  PlayingState();
  ~PlayingState();
  
};
