#pragma once

#include <iostream>
#include <vector>
#include <SDL.h>

#include "Vector2.h"
#include "Component.h"

#include <typeinfo.h>


class Entity
{
 public:
  std::vector<Component*>components;
  
  
  Entity(std::vector<Component*> c);

  Component* getComponentByType(ComponentType type);
  
  int typeID;
  std::string u_tag;
  
  Vec2 position;
  Vec2 velocity;


  void load();
  
  void update(SDL_Renderer* r);
  
  void render(SDL_Renderer* r);
  
  template <typename T>
    T* getComponent() {
    for (auto c : components) {
      if ( typeid(*c) == typeid(T) ) {
	return dynamic_cast<T*>(c);
      }
    }
  }

  template <typename T>
    bool hasComponent() {
    for (auto c : components) {
      if ( typeid(*c) == typeid(T) ) {
	return true;
      }
    }
    return false; 
  }
  
  template <typename T>
    void getCompTest(){
    for (auto c : components) {
      if ( typeid( *c ) == typeid(T) ) {
	printf("found a match!\n");
      }
    }
  }
  
  
  
  ~Entity();
  
  
  
};
