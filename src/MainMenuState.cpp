#include "MainMenuState.h"

#include "Graphics.h"

bool MainMenuState::load(SDL_Renderer* r, StateManager* sm) {
  if (!r  || !sm)
    return false;
  stateManager = sm;
  
  menuTexture = Graphics::loadTexture( r, "resources/menuTexture.bmp" );
  if (!menuTexture)
    return false;

  return true;
}


void MainMenuState::update(SDL_Renderer* r) {
  const Uint8* keyState = SDL_GetKeyboardState(NULL);
  
  if ( keyState[ SDL_SCANCODE_RETURN ] ) {
    if (stateManager) {
      printf("Switching states!\n");
      stateManager->switchState( GameState::playing );
    }
  }  
}

void MainMenuState::render(SDL_Renderer* r) {
  SDL_RenderCopy( r, menuTexture, NULL, NULL );
}

MainMenuState::MainMenuState() {

}

MainMenuState::~MainMenuState() {

  SDL_DestroyTexture(menuTexture);
  menuTexture = nullptr;

}
