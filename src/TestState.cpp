#include "TestState.h"

#include "Player.h"

#include "StateManager.h"

bool TestState::load(SDL_Renderer* r, StateManager* sm ) {
  if (!r || !sm)
    return false;
  
  stateManager = sm;

  testWorld.load(r);
  return true;
}

void TestState::proccessInputs(  ) {
  testWorld.proccessInputs();

  const Uint8* keyState = SDL_GetKeyboardState(NULL);

  if ( keyState[ SDL_SCANCODE_UP ] ) {
    if (stateManager) {
      printf("Switching states!\n");
      stateManager->switchState( GameState::playing );
    }
  }

}

void TestState::update(SDL_Renderer* r) {
  testWorld.update(r);
}

void TestState::render(SDL_Renderer* r) {
  testWorld.render(r);
}


TestState::TestState( ) {
  
}

TestState::~TestState() {
  stateManager = nullptr;
}
