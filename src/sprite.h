#pragma once

#include <SDL.h>
#include "Graphics.h"
#include "Vector2.h"


class Entity;

class Sprite {
 public:
  SDL_Texture* texture = nullptr;

  SDL_Rect* renderQuad = nullptr;

  void update(Entity* entity);
  
  void render(SDL_Renderer* r);

  void setTexture(SDL_Renderer* r, const std::string textureName);

  //Sprite();
  Sprite(SDL_Renderer* r, const std::string textureName, Vec2* position, SDL_Rect* rQuad);
    
  
  ~Sprite();
  
};
