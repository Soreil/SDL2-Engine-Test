#include "Player.h"

#include <vector>
#include "Vector2.h"


void Player::load( ) {
  position.x = 100;
  position.y = 100;
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
  handleInputs();  

  if ( moving ) {
    switch (currDirection) {
      
    case Direction::DOWN:
      position.y += SPEED * dt;
      break;

    case Direction::UP:
      position.y -= SPEED * dt;
      break;

    case Direction::LEFT:
      position.x -= SPEED * dt;
      break;

    case Direction::RIGHT:
      position.x += SPEED * dt;
      break; 
    }
  }
}


void Player::render(SDL_Renderer* r) {
  sprite->renderQuad->x = position.x;
    sprite->renderQuad->y = position.y;
  sprite->render(r);
}


Player::Player( SDL_Renderer* r, Vec2* position, int w, int h) {
  sprite = new Sprite(r, textureName, NULL, new SDL_Rect{position->x, position->y, w, h} );

  load();
    
  
}

Player::~Player( ) {
  delete sprite;
  sprite = nullptr;
}

