#pragma once

#include <SDL.h>
#include "State.h"
#include "Sprite.h"

#include "Timer.h"

#include "Player.h"

#include "EntityManager.h"

#include "Map.h"

class ResourceManager;


class PlayingState : public State {
 private:
  //temporary for testing, eventually move this to an entityManager
  Player* player = nullptr;

  EntityManager entityManager;

  Map* map = nullptr;
  
  Timer timer;
  
 public:
  void onEnterState(GameStateManager* sm);
  void onExitState();

  void handleEvents();

  void update(float deltaTime);
  void render(SDL_Renderer* r);

  PlayingState(SDL_Renderer* r, ResourceManager* resourceManager );
  ~PlayingState();
  
};
