#pragma once

#include <SDL.h>

#include <vector>

#include "Input.h"


class State;

const Uint8 STATE_COUNT = 3;
enum GameState {
  mainMenu = 0,
  playing,
  test
};
  
  
class StateManager {
 private:

  Input* input_ = nullptr;
  
 public:
  
  SDL_Renderer* renderer;
  
  State* states[STATE_COUNT];
  
  State* currentState = nullptr;

  bool init(SDL_Renderer* r, Input* input);

  void proccessInputs();
  
  void load();
  
  void update();
  
  void render();
  
  void switchState(int state);

  
  StateManager();
  ~StateManager();


};
