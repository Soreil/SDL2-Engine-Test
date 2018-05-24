#pragma once

#include <SDL.h>

#include <vector>


class State;

const Uint8 STATE_COUNT = 2;
enum GameState {
  mainMenu = 0,
  playing,
  test
};
  
  
class StateManager {
 public:
  
  SDL_Renderer* renderer;
  
  State* states[STATE_COUNT];
  
  State* currentState = nullptr;

  bool init(SDL_Renderer* r);

  void proccessInputs();
  
  void load();
  
  void update();
  
  void render();
  
  void switchState(int state);

  
  StateManager();
  ~StateManager();


};
