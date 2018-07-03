/*
  SWEETSBEATS 2018
*/
#pragma once
#include <SDL.h>
#include "Entity.h"
#include <cstdint>


class ResourceManager;

enum Direction {
  UP = 0,
  DOWN,
  LEFT,
  RIGHT
};

class Player : public Entity {
 private:

  const std::string textureName = "red";

  Direction currDirection = Direction::UP;
  bool moving = false;
  
  float speed = 5.0f;
  
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
  
  Player(SDL_Renderer* r, ResourceManager* resourceManager, int x, int y, int w, int h );
  Player( SDL_Renderer* r, ResourceManager* resourceManager, int x, int y, bool sizeColliderToSprite);
  ~Player();
  

};
