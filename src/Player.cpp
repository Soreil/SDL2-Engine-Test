#include "Player.h"

#include <vector>
#include "Vector2.h"




void Player::load( ) {

}

void Player::proccessInputs() {

}

void Player::update(SDL_Renderer* r) {

  //  if (input_)
    if ( input_->isKeyPressed(SDL_SCANCODE_UP) ) {
      sprite->renderQuad->y -= SPEED;
      //printf("UP UP DOWN DOWN LEFT RIGHT LEFT RIGHT A B START \n");
    }
    if ( input_->isKeyPressed(SDL_SCANCODE_DOWN) ) {
      sprite->renderQuad->y += SPEED;
    }

    if ( input_->isKeyPressed(SDL_SCANCODE_LEFT) ) {
      sprite->renderQuad->x -= SPEED;
    }

    if ( input_->isKeyPressed(SDL_SCANCODE_RIGHT) ) {
      sprite->renderQuad->x += SPEED;
    }

}


void Player::render(SDL_Renderer* r) {
  sprite->render(r);
}


Player::Player( SDL_Renderer* r, Vec2* position, int w, int h, Input* input ) {
  sprite = new Sprite(r, textureName, NULL, new SDL_Rect{position->x, position->y, w, h} );

  input_ = input;

  if (!input)
    printf("Input is null!\n");
    
  
}

Player::~Player( ) {
  input_ = nullptr;

  delete sprite;
  sprite = nullptr;
}

