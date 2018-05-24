#pragma once

#include <SDL.h>
#include "Graphics.h"
#include "Vector2.h"

class Sprite {
 public:
  SDL_Texture* texture = nullptr;

  SDL_Rect* renderQuad = nullptr;

  void render(SDL_Renderer* r);
  

  //Sprite();
  Sprite(SDL_Renderer* r, const std::string textureName, Vec2* position, SDL_Rect* rQuad);
   
    
    
  
  ~Sprite();
  
};
