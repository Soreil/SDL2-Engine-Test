#include <SDL.h>
#include <map>

namespace Input {

  const int USER_KEY_COUNT = 4;
  
  int validKeys[USER_KEY_COUNT] = {
    SDLK_LEFT,
    SDLK_RIGHT,
    SDLK_UP,
    SDLK_DOWN
  };
  
  std::map<SDL_Keycode, bool> inputs;


  void initInputs() {
    for ( int i = 0; i < USER_KEY_COUNT; i++ ) {
      inputs.insert( std::make_pair( validKeys[i], false ) );
    }
  }
  
  void proccessInputs(SDL_Event* e) {
    while (SDL_PollEvent(e)!= 0 ) {
      for ( int i = 0; i < USER_KEY_COUNT; i++ ) {
	if ( e->key.keysym.sym == validKeys[i] ) {
   
	  if( e->type == SDL_KEYDOWN){
	    inputs[i] = true;
	  } else if ( e->type == SDL_KEYUP ) {
	    inputs[i] = false;
	  } else {
	    printf("wrong code path!\n");
	  }
	 
	}
      }
    }
  }
  
      
}
    
