#pragma once

#include <SDL.h>
#include <map>


/*
  Class structure is borrowed from github.com/cavestory-sdl2
  Sorry, but it was really simple and good.
*/

class Input {
 private:
  std::map<SDL_Scancode, bool> pressedKeys_;
  std::map<SDL_Scancode, bool> releasedKeys_;
  std::map<SDL_Scancode, bool> heldKeys_;
  
 public:
  void newFrameWipe();
  
  bool isKeyPressed(SDL_Scancode key);
  bool isKeyReleased(SDL_Scancode key);
  bool isKeyHeld(SDL_Scancode key);

  void keyDownEvent(const SDL_Event& event);
  void keyUpEvent(const SDL_Event& event);
  
  Input();
  ~Input();  

};
