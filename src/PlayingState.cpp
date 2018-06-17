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

}

void PlayingState::render(SDL_Renderer* r) {

}

PlayingState::PlayingState() {

}

PlayingState::~PlayingState() {

}
