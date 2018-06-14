#include <SDL.h>


struct State {
public:

  virtual void handleEvents();

  virtual void update();
  virtual void render();
  
};
