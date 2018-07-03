#pragma once

#include <SDL.h>

#include "Entity.h"
#include "Collider.h"

class ResourceManager;

class TestEnt : public Entity {

 private:
  const std::string textureName = "green";
  
 public:

  void load();
  void handleInputs();
  void update(float dt);
  void render(SDL_Renderer* r);

  TestEnt();
  TestEnt(SDL_Renderer* r, ResourceManager* resourceManager, int32_t x, int32_t y, int32_t w, int32_t h);

  ~TestEnt();
  
};
