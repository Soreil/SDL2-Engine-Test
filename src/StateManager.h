#include "State.h"

#include <vector>

enum GameState {
  STARTUP,
  MENU,
  PLAYING,
  SHUTDOWN,
  TRANSITION
};

class GameStateManager {
 private:
  State* currentState = nullptr;
  State* prevState    = nullptr;

 public:

  void switchState(State* newState);
  /*
    if (currentState != newState) {
      currentState = newState;
      currentState->onEnter();
    }
    else {
      printf("err...");
    }
   */

  void update();

  void render();
  
  
};
