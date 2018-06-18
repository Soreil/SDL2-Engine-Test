#include "TestEnt.h"


void TestEnt::load() {

}

void TestEnt::handleInputs() {

}

void TestEnt::update(float dt) {

}

void TestEnt::render(SDL_Renderer* r) {
  collider = new Collider(0, 0, 32, 32);    //Have a default just in case
}


TestEnt::TestEnt(int32_t x, int32_t y, int32_t w, int32_t h) {
  collider = new Collider(x, y, w, h);
}

TestEnt::~TestEnt() {
  delete collider;
  collider = nullptr;
}

