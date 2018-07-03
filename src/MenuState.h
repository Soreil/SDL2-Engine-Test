#pragma once

#include <SDL.h>
#include "State.h"

#include "Sprite.h"

class ResourceManager;
class GameStateManager;


class MenuState : public State {
 private:
  Sprite* backgroundLogo = nullptr;
  const std::string bgLogoName = "resources/menuTexture.bmp";
  
 public:

  void onEnterState(GameStateManager* sm);
  void onExitState();

  void handleEvents();

  void update(float deltaTime);
  void render(SDL_Renderer* r);

  MenuState(SDL_Renderer* r, ResourceManager* resourceManager);
  ~MenuState();
  
};
