#pragma once

#include <SDL.h>

#include "State.h"

class MenuState : public State {
 public:

  void onEnterState();
  void onExitstate();

  void handleEvents();

  void update();
  void render();
  
};
