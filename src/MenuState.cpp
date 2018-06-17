#include "MenuState.h"

void MenuState::onEnterState() {

}

void MenuState::onExitState() {
  
}

void MenuState::handleEvents() {
  
}

void MenuState::update(float deltaTime) {
    
}

void MenuState::render(SDL_Renderer *r) {
  backgroundLogo.render(r);
}

MenuState::MenuState(SDL_Renderer* r) {
  backgroundLogo = new Sprite(r, bgLogoName, new Vec2{0,0}, NULL);
}

MenuState::~MenuState() {
  delete backgroundLogo;
  backgroundLogo = nullptr;
}

