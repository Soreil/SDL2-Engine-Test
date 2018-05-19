#include "Entity.h"
#include "Player.h"

Entity::Entity(std::vector<Component*> c)
  : components(c)
{}

void Entity::load() {

}


void Entity::update(SDL_Renderer* r) {
  for(auto c : components) {
    if (c->type != ComponentType::graphics)
      c->update(this);
  }
}

void Entity::render(SDL_Renderer* r) {
  for(auto c : components) {
    if (c->type == ComponentType::graphics)
      c->update(this);
  }
}

/*
  Returns the first component it find of 'type' in an entities components vector
*/
Component* Entity::getComponentByType(ComponentType type) {
  for(auto c : components) {
    if (c->type == type) {
      return c;
    }
  }
}


Entity::~Entity() {
  for( auto c : components ) {
    delete c;
  }
}
