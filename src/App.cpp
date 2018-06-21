#include "App.h"
#include <stdio.h>
#include "Entity.h"
#include "Vector2.h"
#include <iostream>

App::App()
{
}

bool App::startup()
{
  // Initialize SDL2
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0) {
    printf("SDL could not initialize! Error: %s\n",SDL_GetError());
    return false;
  }
  // Initialize SDL_mixer
  if ( Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0 ) {
    printf("Error initializing SDL_mixer!: %s\n",Mix_GetError() );
    return false;
  }
  // Initialize SDL_tff
  if (TTF_Init() == -1 ) {
    printf( "Error Initializing SDL_ttf!: %s\n", TTF_GetError() );
    return false;
  }


  // Set game loop flag
  running = true;

  /*
   Initialize SDL window and renderer 
   */
  window = SDL_CreateWindow("Test", 200, 200,
			    WINDOW_WIDTH, WINDOW_HEIGHT,
			    SDL_WINDOW_SHOWN);

  if (!window) {
    printf(" Window Couldn't be loaded! Err: %s \n", SDL_GetError() );
    return false;
  }
  
  renderer = SDL_CreateRenderer(
				window, -1, SDL_RENDERER_ACCELERATED );

  if (!renderer) {
    printf(" Renderer Couldn't be loaded! Err: %s \n", SDL_GetError() );
    return false;
  }
    
  screenSurface = SDL_GetWindowSurface(window);
  if (!screenSurface) {
    printf("Error loading screen surface!: %s", SDL_GetError()); 
    return false;
  }


  gFont = TTF_OpenFont( "resources/sansation.ttf", 16 );
  if (!gFont) {
    printf( "Error loadng font! Err: %s\n", TTF_GetError() );
    return false;
  }
  

  //INIT ENGINE SYSTEMS
  
  //text = new TextHandler(gFont, renderer);  
  //If everything is successfully intialized, true is returned here
  return true;
}

/*
  Loads Important resources for the app to run
  This is where most managers and other things should be loaded
*/
void App::Load()
{
  stateManager = new GameStateManager(renderer);
}


void App::Update()
{    
  while (SDL_PollEvent(&e) != 0)
    {
      switch (e.type)
	{
	case SDL_MOUSEMOTION:
	  // printf("THERE IS MOUSE MOTION\n mouse position: (%d, %d)\n",
	  // e.motion.x, e.motion.y);
	  
	  break;
	  
	case SDL_KEYDOWN:
	  
	  break;
	  
	case SDL_KEYUP:
	  
	  break;
	  
	case SDL_MOUSEBUTTONDOWN:
	  
	  break;
	  
	case SDL_MOUSEBUTTONUP:
	  break;
	  
	case SDL_QUIT:
	  
	  running = false;
	  
	  break;
	}
    }


  //DT CALCULATION
  
  /*
  currTicks = SDL_GetTicks();
  float deltaTime = (currTicks - prevTicks) / 1000;
 
  printf("currTicks: %d\n deltaTime: %d\n prevTicks:  %d\n\n\n", currTicks, deltaTime, prevTicks);
  prevTicks = currTicks;
  */  

  prevTicks = currTicks;
  currTicks = SDL_GetTicks();
 
  deltaTime =  currTicks - prevTicks;

  //std::cout << deltaTime << std::endl;
 
  deltaTime /= 1000.f;

  //std::cout << deltaTime << std::endl;

  stateManager->update(deltaTime);
  
}



void App::Render()
{
  SDL_RenderClear(renderer);			//BEGINS RENDERING

  //ENTITY RENDERING

  //UPDATE STATEMANAGER

  stateManager->render(renderer);
  
  // UI RENDERING
  //text->renderText(Text::text::testSailor, Vec2{0,0});
  
  
  SDL_RenderPresent(renderer);		//ENDS RENDERING
  SDL_Delay(1/FRAMERATE);

}


/*
  Run calls each step of the Application proccess in order, and
  maintains our game loop
*/

void App::run()
{
  //Do startup operations
  if ( startup() ) {
    Load();
    while (running)
      {
	Update();
	Render();
	SDL_Delay(1.0f/FRAMERATE*1000.f);
      } 
  }
  
}

void App::cleanup()
{

  delete stateManager;
  stateManager = nullptr;

  /*
  delete text;
  text = nullptr;
  */


  SDL_FreeSurface(screenSurface);
  screenSurface = nullptr;
  
  SDL_DestroyWindow(window);
  window = nullptr;
  
  SDL_DestroyRenderer(renderer);
  renderer = nullptr;

  TTF_CloseFont(gFont);
  gFont = nullptr;

  
  SDL_Quit();
  Mix_Quit();
  TTF_Quit();
}

App::~App()
{
  cleanup();
}

