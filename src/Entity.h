#pragma once

#include <iostream>
#include <vector>
#include <SDL.h>

#include "Vector2.h"

#include "Sprite.h"

#include <stdint.h>

typedef uint32_t Uint32;


class Entity
{
 public:
  
  std::string u_tag;
  
  Vec2 position;
  Vec2 velocity;
  
  SDL_Rect* b_box = nullptr;

  Sprite* sprite = nullptr;

  virtual void load() = 0;
  
  virtual void update(SDL_Renderer* r) = 0;
  
  virtual void render(SDL_Renderer* r) = 0;
  

  
  Entity(); 
  ~Entity();
  
  
  
};
