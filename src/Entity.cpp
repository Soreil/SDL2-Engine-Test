#include "Entity.h"





void Entity::updateSpriteAndCollider() {
  if (collider) {
    collider->x = position.x;
    collider->y = position.y;
    collider->sat_box->x = position.x;
    collider->sat_box->y = position.y;
  }
  if (sprite) {
    sprite->renderQuad->x = position.x;
    sprite->renderQuad->y = position.y;
  }
}



void Entity::wrapColliderToSprite(Collider* c, Sprite* s) {
  if (c && s) {
  c->w = s->atlasLoc->w;
  c->h = s->atlasLoc->h;
  }
}



Entity::Entity() {

}

Entity::~Entity() {

}

