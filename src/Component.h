#pragma once

#include <iostream>
#include <vector>
#include <SDL.h>

class Entity;


enum ComponentType {
  graphics,
  physics
}; 

class Component
{
 public:
  
  Component();
	
  Entity* entity;
  
  uint8_t type = NULL;
  
  virtual void update() = 0;
  
  virtual void update(Entity* e) = 0;
  
  ~Component();
};

