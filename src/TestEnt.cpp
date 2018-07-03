#include "TestEnt.h"

#include "SAT.h"

#include "ResourceManager.h"

#include "Vector2.h"

void TestEnt::load() {

}

void TestEnt::handleInputs() {

}

void TestEnt::update(float dt) {
}

void TestEnt::render(SDL_Renderer* r) {
  if (sprite)
    sprite->render(r);
}


TestEnt::TestEnt(SDL_Renderer* r, ResourceManager* resourceManager, int32_t x, int32_t y, int32_t w, int32_t h) {
  position.x = x;
  position.y = y;
  sprite = new Sprite( r, resourceManager, Atlas::ATLAS_TEST, textureName, x, y );
  collider = new Collider(x, y, sprite->atlasLoc->w ,sprite->atlasLoc->h );
}

TestEnt::~TestEnt() {
  delete collider;
  collider = nullptr;
  
  delete sprite;
  sprite = nullptr;
}

