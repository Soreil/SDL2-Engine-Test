#include "App.h"
#include <stdio.h>
#include "Player.h"
#include "Entity.h"
#include "Component.h"
#include "Input.h"


App::App()
{
}

bool App::startup()
{
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0) {
    printf("SDL could not initialize! Error: %s\n",SDL_GetError());
    return false;
  } 
  if ( Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0 ) {
    printf("Error initializing SDL_mixer!: %s\n",Mix_GetError() );
    return false;
  }
  
  running = true;
  
  window = SDL_CreateWindow("Test", 200, 200,
			    WINDOW_WIDTH, WINDOW_HEIGHT,
			    SDL_WINDOW_SHOWN);
  
  renderer = SDL_CreateRenderer(
				window, -1, SDL_RENDERER_ACCELERATED);
  
  screenSurface = SDL_GetWindowSurface(window);
  if (!screenSurface) {
    printf("Error loading screen surface!: %s", SDL_GetError()); 
    return false;
  }
  //If everything is successfully intialized, true is returned here
  return true;
}

/*
  Loads Important resources for the app to run
  This is where most managers and other things should be loaded
*/
void App::Load()
{ 


  entityManager.init(renderer);
  
  
}

/*
  This is where the major updating/game loop happens
*/
void App::Update()
{  
  //SDL_GetMouseState(&mouse_position.x, &mouse_position.y);
  while (SDL_PollEvent(&e) != 0)
    {
      switch (e.type)
	{
	case SDL_MOUSEMOTION:
	  // printf("THERE IS MOUSE MOTION\n mouse position: (%d, %d)\n",
	  // e.motion.x, e.motion.y);
	  
	  break;
	  
	case SDL_KEYDOWN:
	  printf("KEYBOARD INPUT FROM KEY: %d \n", e.key.keysym.sym);
	  
	  break;
	  
	  
	case SDL_MOUSEBUTTONDOWN:
	  printf("MOUSE INPUT FROM KEY: %d \n", e.button.button);
	  break;
	  
	case SDL_MOUSEBUTTONUP:
	  break;
	  
	case SDL_QUIT:
	  
	  running = false;
	  
	  break;
	}

      //updates keystate array
      //SDL_PumpEvents();
  
      
      entityManager.proccessInputs();
      
      SDL_Delay(1 / FRAMERATE);  
      
    }

  
  entityManager.update();
   
  Render();
  //SDL_UpdateWindowSurface(window);
  
}



void App::Render()
{
  SDL_RenderClear(renderer);			//BEGINS RENDERING
  
  //currentWorld->render(renderer);		//Render the current world

  entityManager.render(renderer);
  
 
  
  
  SDL_RenderPresent(renderer);		//ENDS RENDERING
  SDL_Delay(1/60);
}

void App::run()
{
  //Do startup operations
  startup();
  Load();
  while (running)
    {
      Update();
    }
  //cleanup();
}

void App::cleanup()
{
  
  SDL_FreeSurface(screenSurface);
  screenSurface = nullptr;
  
  SDL_DestroyWindow(window);
  window = nullptr;
  
  SDL_DestroyRenderer(renderer);
  renderer = nullptr;
  
  SDL_Quit();
  Mix_Quit();
}

App::~App()
{
  cleanup();
}

