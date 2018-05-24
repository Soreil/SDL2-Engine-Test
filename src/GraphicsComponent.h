#pragma once
#include "SDL.h"
#include "Component.h"

#include "Sprite.h"

#include "Vector2.h"

class Entity;

class GraphicsComponent : public Component
{
 public:
  SDL_Renderer* renderer = nullptr;
  Sprite* sprite         = nullptr;

  //SDL_Texture* texture =   nullptr;
  //SDL_Rect* renderArea =   nullptr;

  GraphicsComponent( SDL_Renderer* r, const std::string texturePath,
					Vec2* position, SDL_Rect* rQuad);
  
  
  //GraphicsComponent(SDL_Renderer* r);
  //GraphicsComponent(SDL_Renderer* r, const std::string pathfile);

  void update();
  void update(Entity* entity);
  
  //void setTexture(SDL_Renderer* r, const std::string pathfile); 


  ~GraphicsComponent();
}; 

