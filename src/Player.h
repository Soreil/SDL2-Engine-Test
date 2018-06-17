/*
  SWEETSBEATS 2018
*/
#pragma once
#include <SDL.h>
#include "Entity.h"
#include <cstdint>


enum Direction {
  UP = 0,
  DOWN,
  LEFT,
  RIGHT
};

class Player : public Entity {
 private:

  const std::string textureName = "resources/ass.bmp";

  Direction currDirection = Direction::UP;
  bool moving = false;
  
  float speed = 1.0f;
  
 public:

  /*
  void startMovingUp();
  void startMovingDown();
  void startMovingLeft();
  void startMovingRight();
  void stopMoving();
  */
  
  
  void load();

  void handleInputs();
  
  void update(float dt);

  void render(SDL_Renderer *r);
  
  Player(SDL_Renderer* r, Vec2* position, int w, int h );
  ~Player();
  

};
