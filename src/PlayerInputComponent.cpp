#include "PlayerInputComponent.h"

void PlayerInputComponent::update() {

  
  
}


void PlayerInputComponent::update(Entity* entity) {

  const Uint8* state = SDL_GetKeyboardState(NULL);
  if ( state[SDL_SCANCODE_UP] ) {
    printf("UP UP DOWN DOWN LEFT RIGHT LEFT RIGHT B A START\n");
  }

  if ( state[SDL_SCANCODE_DOWN] ) {
    printf("DOWN UP DOWN UP START A B LEFT RIGHT LEFT RIGHT \n");
  }

  if ( state[SDL_SCANCODE_LEFT] ) {
    printf("hello, sailor!\n");
  }

  if ( state[SDL_SCANCODE_RIGHT] ) {
    printf("Pressing right!\n");
  }
  
  
}
/*
PlayerInputComponent::PlayerInputComponent() {

}

PlayerInputComponent::~PlayerInputComponent() {

}
*/
