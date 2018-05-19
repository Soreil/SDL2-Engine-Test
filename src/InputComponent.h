#pragma once
#include <SDL.h>
#include "Component.h"

class Entity;

class InputComponent : public Component {
 public:
  
  virtual void update() = 0;
  virtual void update(Entity* entity) = 0;

  InputComponent() {}
  ~InputComponent() {}
    
};
