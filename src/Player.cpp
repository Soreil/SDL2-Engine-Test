#include "Player.h"

#include <vector>
#include "Vector2.h"

#include "ResourceManager.h"

void Player::load( ) {
}


void Player::handleInputs() {
  const Uint8* keystate = SDL_GetKeyboardState(NULL);

  if (keystate[SDL_SCANCODE_DOWN]) {
    currDirection = Direction::DOWN;
    moving = true;
  }
  else if(keystate[SDL_SCANCODE_UP]) {
    currDirection = Direction::UP;
    moving = true;
  }
  else if(keystate[SDL_SCANCODE_LEFT]) {
    currDirection = Direction::LEFT;
    moving = true;
  }
  else if(keystate[SDL_SCANCODE_RIGHT]) {
    currDirection = Direction::RIGHT;
    moving = true;
  }
  else {
    moving = false;
  }
  
}

void Player::update(float dt) {
  //handleInputs();  
 
  const Uint8* keystate = SDL_GetKeyboardState(NULL);
  
  if ( keystate[SDL_SCANCODE_UP] ) {
    position.y -= speed;
  }
  if ( keystate[SDL_SCANCODE_DOWN] ) {
    position.y += speed;
  }
  if ( keystate[SDL_SCANCODE_LEFT] ) {
    position.x -= speed;
  }
  
  if ( keystate[SDL_SCANCODE_RIGHT] ) {
    position.x += speed;
  }
  
}



void Player::render(SDL_Renderer* r) {
  
  sprite->render(r);
}


Player::Player( SDL_Renderer* r, ResourceManager* resourceManager, int x, int y, int w, int h) {
  sprite = new Sprite(r, resourceManager, Atlas::ATLAS_TEST, textureName, x, y );

  
  
  collider = new Collider(x, y, w, h);

  position.x = x;
  position.y = y;
  
}

Player::Player( SDL_Renderer* r, ResourceManager* resourceManager, int x, int y, bool sizeColliderToSprite) {
  sprite = new Sprite(r, resourceManager, Atlas::ATLAS_TEST, textureName, x, y );
  if ( sizeColliderToSprite ) {
    collider = new Collider( x, y, sprite->atlasLoc->w, sprite->atlasLoc->h );
  }

  position.x = x;
  position.y = y;
  
}

Player::~Player( ) {
  delete sprite;
  sprite = nullptr;
}

