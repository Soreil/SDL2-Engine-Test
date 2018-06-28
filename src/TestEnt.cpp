#include "TestEnt.h"

#include "SAT.h"

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


TestEnt::TestEnt(SDL_Renderer* r, int32_t x, int32_t y, int32_t w, int32_t h) {
  position.x = x;
  position.y = y;
  collider = new Collider(x, y, w, h);
  sprite = new Sprite( r, textureName, nullptr, new SDL_Rect{x, y, w, h} );
}

TestEnt::~TestEnt() {
  delete collider;
  collider = nullptr;
  
  delete sprite;
  sprite = nullptr;
}

