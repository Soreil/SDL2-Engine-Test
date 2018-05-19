#pragma once
#include "SDL.h"
#include "Component.h"

class Entity;

class GraphicsComponent : public Component
{
 public:
  SDL_Renderer* renderer = nullptr;
  SDL_Texture* texture =   nullptr;
  SDL_Rect* renderArea =   nullptr;

  GraphicsComponent(SDL_Renderer* r);
  GraphicsComponent(SDL_Renderer* r, const std::string pathfile);
  void update();
  void update(Entity* entity);
  void setTexture(SDL_Renderer* r, const std::string pathfile); 
  ~GraphicsComponent();
}; 

