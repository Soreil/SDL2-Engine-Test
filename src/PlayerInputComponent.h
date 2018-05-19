#pragma once

#include "InputComponent.h"
#include "Entity.h"



class PlayerInputComponent : public InputComponent {
 public:
  
  void update();
  void update(Entity* entity);
  
  PlayerInputComponent() {
  }
  ~PlayerInputComponent() {
  }
  
};
