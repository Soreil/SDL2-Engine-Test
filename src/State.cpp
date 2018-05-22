#include "State.h"


void StateHelper::switchState( State* currState, State* newState ) {
  if (newState != currState) {
    delete currState;
    currState = newState;
    printf("Switched state!\n");
  } else {
    printf("Cannot switch state! : Newstate == currentState\n");
  }  
}
