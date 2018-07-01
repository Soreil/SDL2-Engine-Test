#include "App.h"
#include <stdio.h>
#include <iostream>

App::App()
{
}

bool App::startup()
{
  // Initialize SDL2
  if (SDL_Init( SDL_INIT_VIDEO ) < 0) {
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
  
  //Initialize SDL window and renderer  
  window = SDL_CreateWindow("Test", 200, 200,
			    WINDOW_WIDTH, WINDOW_HEIGHT,
			    SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL );

  if (!window) {
    printf(" Window Couldn't be loaded! Err: %s \n", SDL_GetError() );
    return false;
  }


  //std::cout << "Hello openGL!\n"  << std::endl;
  
  //INIT GLAD
  if ( !initGlad() ) {
    std::cout << "Hello openGL!\n"  << std::endl;
    return false;
  }
  
  /*
  if ( initGL() )
    return false;
  */


  // USE vSync
  if ( SDL_GL_SetSwapInterval( 1 ) < 0 ) {
    printf("Warning! Unable to set VSync! Error:%s\n", SDL_GetError() );
    return false;
  }

    
  //renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
  /*
  if (!renderer) {
    printf(" Renderer Couldn't be loaded! Err: %s \n", SDL_GetError() );
    return false;
  }
*/
  
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
  //stateManager = new GameStateManager(renderer);
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


  
}



void App::Render()
{

 glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  
 SDL_GL_SwapWindow(window);
  
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
	SDL_Delay(1000/FRAMERATE);
	
      } 
  }
  
}

void App::cleanup()
{

  /*
  delete stateManager;
  stateManager = nullptr;
  */
  
  /*
  delete text;
  text = nullptr;
  */



  SDL_FreeSurface(screenSurface);
  screenSurface = nullptr;

  SDL_GL_DeleteContext(glContext);
  
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



bool App::initGlad() {
  // INITIALIZE GL 3.3
  //SDL_GL_LoadLibrary(NULL);
  
  SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
  SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 3 );
  SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );

  SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
  SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 24 );
  
  glContext = SDL_GL_CreateContext( window );
  if ( glContext == NULL ) {
    printf("Error creating glContext in App.cpp! Error:%s\n", SDL_GetError() );
    return false;
  }

  //make context current
  if ( SDL_GL_MakeCurrent( window, glContext ) < 0 ) {
    printf("Cannot make glContext current!\n");
    return false;
  }
  
  if (!gladLoadGLLoader( (GLADloadproc) SDL_GL_GetProcAddress) ) {
    printf("Could not load SDL_GL_GetProcAddress into glad! Error\n");
    return false;
  }


  //INIT OpenGL
  if ( !initGL() ) {
    printf("Error: Unable to initalize OpenGL!\n" );
    return false;
  }
  
  return true;
}



bool App::initGL() {

  GLuint programID = glCreateProgram();

  GLuint vertexShader = glCreateShader( GL_VERTEX_SHADER );

  const GLchar* vertexShaderSource[] = {
    "#version 140\nin vec2 LVertexPos2D; void main() { gl_Position = vec4( LVertexPos2D.x, LVertexPos2D.y, 0, 1 ); }"
  };

  glShaderSource( vertexShader, 1, vertexShaderSource, NULL );
  glCompileShader( vertexShader );

  GLint vShaderCompiled = GL_FALSE;
  glGetShaderiv( vertexShader, GL_COMPILE_STATUS, &vShaderCompiled );

  if ( vShaderCompiled != GL_TRUE ) {
    printf("Unable to compile vertex shader!: %d\n", vertexShader); 
    return false;
  }

  //attatch frag. shader
  glAttachShader( programID, vertexShader );

  GLuint fragmentShader = glCreateShader( GL_FRAGMENT_SHADER );
  const GLchar* fragmentShaderSource[] = {
    "#version 140\nout vec4 LFragment; void main() { LFragment = vec4( 1.0, 1.0, 1.0, 1.0 ); }"
  };

  glShaderSource( fragmentShader, 1, fragmentShaderSource, NULL );
  glCompileShader( fragmentShader );

  GLint fShaderCompiled = GL_FALSE;
  glGetShaderiv( fragmentShader, GL_COMPILE_STATUS, &fShaderCompiled );
  if ( fShaderCompiled != GL_TRUE ) {
    printf("Unable to compile fragment shader!: %d\n", fragmentShader); 
    return false;
  }

  //attatch vert. shader
  glAttachShader( programID, fragmentShader );

  glLinkProgram( programID );

  // Check for errors
  GLint programSuccess = GL_TRUE;
  glGetProgramiv( programID, GL_LINK_STATUS, &programSuccess );
  if ( programSuccess != GL_TRUE ) {
    printf("Error linking program!: %d\n", programID); 
    return false;
  }

  //get vertex attribute location

  GLint vertexPos2DLocation = glGetAttribLocation( programID, "LVertexPos2D" );

  if ( vertexPos2DLocation == -1 ) {
    printf("LVertexPos2D is not a valid glsl program variable!\n");
    return false;
  }

  GLint vpWidth, vpHeight;
  SDL_GL_GetDrawableSize(window, &vpWidth, &vpHeight);
  glViewport(0, 0, vpWidth, vpHeight);

  return true;
  
}
