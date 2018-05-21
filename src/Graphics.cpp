#include "Graphics.h"

 
  //	Loads an SDL_Surface, converts it to a texture, and returns the addr.
SDL_Texture* Graphics::loadTexture(SDL_Renderer* renderer, std::string path) {
  SDL_Surface* s = SDL_LoadBMP(path.c_str());
  if (!s)
    printf("ERROR! Cannot load texture as surface: %s\n", SDL_GetError());
  SDL_Texture* t = SDL_CreateTextureFromSurface(renderer, s);
  if (!t)
    printf("ERROR: Cannot create texture from loaded surface!: %s\n", SDL_GetError());
  SDL_FreeSurface(s);
  return t;
}


SDL_Texture* Graphics::loadTextTexture ( const std::string text, SDL_Renderer* renderer,
					 TTF_Font* font, SDL_Color* color ) {
  
  // default color if color == NULL 
  if ( !color )
    color = new SDL_Color{0, 0, 0};
  
  SDL_Surface* s = TTF_RenderText_Solid( font, text.c_str(), *color );
  if (!s)
    printf( "Error! Cannot load text as surface! Err : %s\n", SDL_GetError() );
  
  SDL_Texture* t = SDL_CreateTextureFromSurface( renderer, s );
  if (!t)
    printf( "Error! Cannot convert TextSurface to Texture! Err: %s\n", SDL_GetError() );
  
  SDL_FreeSurface(s);
  delete color;
  return t;
}
