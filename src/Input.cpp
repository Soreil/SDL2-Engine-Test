#include "Input.h"

void Input::keyDownEvent(const SDL_Event& event) {
  pressedKeys_[event.key.keysym.scancode] = true;
  heldKeys_[event.key.keysym.scancode]    = true;
}

void Input::keyUpEvent(const SDL_Event& event) {
  pressedKeys_[event.key.keysym.scancode] = false;
  heldKeys_[event.key.keysym.scancode]    = false;
}

bool Input::isKeyPressed(SDL_Scancode key) {
  //printf("KEY_PRESSED; KEY: %s \n", key);
  return pressedKeys_[key];
}

bool Input::isKeyReleased(SDL_Scancode key) {
  //printf("KEY_RELEASED; KEY: %s \n", key);
  return releasedKeys_[key];
}

bool Input::isKeyHeld(SDL_Scancode key) {
  //printf("KEY_HELD; KEY: %s \n", key);
  return heldKeys_[key];
}


void Input::newFrameWipe() {
  pressedKeys_.clear();
  releasedKeys_.clear();
}

Input::Input() {

}

Input::~Input() {

}
