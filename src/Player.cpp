#include "Player.h"

#include <vector>
#include "Vector2.h"




void Player::load( Input& input ) {
  input_ = &input;
}

void Player::proccessInputs() {

}

void Player::update(SDL_Renderer* r) {

  if ( input_->isKeyPressed(SDL_SCANCODE_UP) ) {
    printf("UP UP DOWN DOWN LEFT RIGHT LEFT RIGHT A B START \n");
  }

}


void Player::render(SDL_Renderer* r) {

}

Player::Player() {
  
}

Player::~Player() {
  input_ = nullptr;
}

