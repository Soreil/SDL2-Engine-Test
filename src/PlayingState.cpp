#include "PlayingState.h"

#include <iostream>

void PlayingState::onEnterState(GameStateManager* sm) {
  setStateManager(sm);
  timer.start();
}

void PlayingState::onExitState() {
  releaseStateManager();
}

void PlayingState::handleEvents() {

}

void PlayingState::update(float deltaTime) {
  player->update(deltaTime);
  std::cout << timer.getTicks()/1000.f << std::endl;
}

void PlayingState::render(SDL_Renderer* r) {
  player->render(r);
}

PlayingState::PlayingState(SDL_Renderer* r) {
  player = new Player(r, new Vec2{100,100}, 100, 100 );
}

PlayingState::~PlayingState() {
  delete player;
  player = nullptr;
}
