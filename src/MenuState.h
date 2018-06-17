#pragma once

#include <SDL.h>
#include "State.h"

#include "Sprite.h"

class MenuState : public State {
 private:
  Sprite* backgroundLogo = nullptr;
  const std::string bgLogoName = "recources/menuTexture.bmp";

 public:

  void onEnterState();
  void onExitState();

  void handleEvents();

  void update(float deltaTime);
  void render(SDL_Renderer* r);

  MenuState();
  ~MenuState();
  
};
