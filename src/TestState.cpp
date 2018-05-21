#include "TestState.h"


void TestState::load(SDL_Renderer* r) {
  testWorld.load(r);
}

void TestState::proccessInputs() {
  testWorld.proccessInputs();
}

void TestState::update(SDL_Renderer* r) {
  testWorld.update();
}

void TestState::render(SDL_Renderer* r) {
  testWorld.render(r);
}


TestState::TestState() {

}

TestState::~TestState() {
  
}
