#pragma once
#include <SDL.h>
#include <stdio.h>


class State {
 public:

  virtual void load(SDL_Renderer* r) = 0;


  virtual void proccessInputs() = 0;
  
  virtual void update(SDL_Renderer* r) = 0;


  virtual void render(SDL_Renderer* r) = 0;


  State(){}
  ~State(){}
  

}; 


namespace StateHelper {
  void switchState( State* s, State* newState );
}
