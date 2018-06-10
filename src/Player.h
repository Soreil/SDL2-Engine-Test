/*
  SWEETSBEATS 2018
*/
#pragma once
#include <SDL.h>

#include "Entity.h"


const int SPEED = 5;


enum Direction {
  UP = 0,
  DOWN,
  LEFT,
  RIGHT
};

class Player : public Entity {
 private:

  const std::string textureName = "resources/ass.bmp";

 public:

  /*
  void startMovingUp();
  void startMovingDown();
  void startMovingLeft();
  void startMovingRight();
  void stopMoving();
  */
  
  
  void load();
  
  void proccessInputs();
  
  void update(SDL_Renderer* r);

  void render(SDL_Renderer *r);
  
  Player(SDL_Renderer* r, Vec2* position, int w, int h );
  ~Player();
  

};
