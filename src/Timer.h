#pragma once

#include <stdint.h>
#include <SDL.h>

class Timer {
 private:
  bool ticking = false;
  bool paused = false;

  uint32_t startingTicks;
  uint32_t pausedTicks;
  
 public:

  uint32_t  getTicks() {
    uint32_t time = 0;
    if (paused) {
      time = pausedTicks;
    }
    else {
      time = SDL_GetTicks() - startingTicks;
    }
    
    return time;
  }
  
  void start() {
    ticking = true;
    paused = false;
    startingTicks = SDL_GetTicks();
  }

  void stop() {
    ticking = false;
    paused = false;
    startingTicks = 0;
  }


  void pause() {
    if (ticking && !paused) {
      paused = true;
      pausedTicks = SDL_GetTicks() - startingTicks;
    }
  }

  void unpause() {
    if (paused) {
      paused = false;
      startingTicks = SDL_GetTicks() - pausedTicks;
      pausedTicks = 0;
      
    }
  }
  
};
