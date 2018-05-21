#pragma once

#include <SDL.h>
#include <SDL_ttf.h>

#include <string>


namespace Graphics {
  
  //	Loads an SDL_Surface, converts it to a texture, and returns the addr.
  SDL_Texture* loadTexture(SDL_Renderer* renderer, std::string path);
  
  
  SDL_Texture* loadTextTexture ( const std::string text, SDL_Renderer* renderer,
				 TTF_Font* font, SDL_Color* color );
    
  
  
}
