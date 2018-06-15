#include <SDL.h>


struct State {
public:

  virtual void onEnterState() = 0;
  virtual void onExitState() = 0;
  
  virtual void handleEvents() = 0;

  virtual void update() = 0;
  virtual void render() = 0;
  
};
