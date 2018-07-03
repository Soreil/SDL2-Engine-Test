#pragma once

#include <SDL.h>
#include "Graphics.h"
#include "Vector2.h"

#include "ResourceManager.h"

class Entity;


enum Atlas;

class Sprite {
 public:

  std::string spriteName;
  
  SDL_Texture* atlasTex = nullptr;
  SDL_Rect* atlasLoc    = nullptr;

  SDL_Rect* renderQuad = nullptr;

  
  void update(Entity* entity);
  
  void render(SDL_Renderer* r);

  //Sprite();
  Sprite(SDL_Renderer* r, ResourceManager* resourceManager, Atlas atlas, const std::string spriteName, int x, int y );   
  
  ~Sprite();
  
};
