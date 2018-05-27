#include "Player.h"

#include <vector>
#include "Vector2.h"




void Player::load( Input& input ) {
  input_ = &input;
}

void Player::proccessInputs() {

}

void Player::update(SDL_Renderer* r) {

  if (input_) {
    if ( input_->isKeyPressed(SDL_SCANCODE_UP) ) {
      printf("UP UP DOWN DOWN LEFT RIGHT LEFT RIGHT A B START \n");
    }
  }
}


void Player::render(SDL_Renderer* r) {
  sprite->render(r);
}


Player::Player( SDL_Renderer* r, Vec2* position, int w, int h ) {
  sprite = new Sprite(r, textureName, NULL, new SDL_Rect{position->x, position->y, w, h} );
  
}

Player::~Player() {
  input_ = nullptr;

  delete sprite;
  sprite = nullptr;
}

