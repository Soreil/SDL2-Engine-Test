#include "PlayingState.h"


void PlayingState::onEnterState(GameStateManager* sm) {
  setStateManager(sm);
}
void PlayingState::onExitState() {
  releaseStateManager();
}

void PlayingState::handleEvents() {

}

void PlayingState::update(float deltaTime) {
  player->update(deltaTime);
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
