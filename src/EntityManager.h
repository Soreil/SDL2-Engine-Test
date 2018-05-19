#pragma once

#include <SDL.h>
#include <vector>

#include "Entity.h"

#include "GraphicsComponent.h"
#include "InputComponent.h"
#include "PlayerInputComponent.h"
#include "PhysicsComponent.h"


struct EntityManager {

  std::vector<Entity*> entities;
  
  void init(SDL_Renderer* r);

  void proccessInputs();
  
  void update();

  void render(SDL_Renderer* r);

  Entity* getEntityByTag(const std::string tag); //for entities that don't share tags

  template <typename T>
  std::vector<Entity*> getEntitiesWithComponentType();
     
  void addEntity(Entity* entity);

  EntityManger();
  ~EntityManager();
  
};
