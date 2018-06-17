#pragma once

#include <SDL.h>
#include "State.h"
#include "Sprite.h"

#include "Player.h"

class PlayingState : public State {
 private:
  //temporary for testing, eventually move this to an entityManager
  Player* player = nullptr;
  
 public:
  void onEnterState(GameStateManager* sm);
  void onExitState();

  void handleEvents();

  void update(float deltaTime);
  void render(SDL_Renderer* r);

  PlayingState(SDL_Renderer* r);
  ~PlayingState();
  
};
