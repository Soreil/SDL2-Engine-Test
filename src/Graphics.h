#pragma once

#include "SDL.h"
#include "string"

namespace Graphics {

	//	Loads an SDL_Surface, converts it to a texture, and returns the addr.
	SDL_Texture* LoadTexture(SDL_Renderer* renderer, std::string path) {
		SDL_Surface* s = SDL_LoadBMP(path.c_str());
		if (!s)
			printf("ERROR! Cannot load texture as surface: %s\n", SDL_GetError());
		SDL_Texture* t = SDL_CreateTextureFromSurface(renderer, s);
		if (!t)
			printf("ERROR: Cannot create texture from loaded surface!: %s\n", SDL_GetError());
		SDL_FreeSurface(s);
		return t;
	}


}