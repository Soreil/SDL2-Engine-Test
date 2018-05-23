#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <vector>
#include <map>

#include "Vector2.h"


struct TextSprite {
  SDL_Texture* texture = nullptr;
  SDL_Rect* renderQuad = nullptr;
  SDL_Color* color =     nullptr;
  
  TextSprite( SDL_Renderer* r, const std::string text, SDL_Color* c, TTF_Font* f,
	      int x, int y);
  
  TextSprite(SDL_Renderer* r, const std::string text, int textSize, SDL_Color* c, TTF_Font* f,
	     int x, int y, int w, int h);

  void render(SDL_Renderer* r);
  
  ~TextSprite();
};


//TODO(sweets): finish new text system TODAY!

namespace Text {
  enum text {
    testSailor = 0
  };
}

class TextHandler {
 public:
  TTF_Font* font = nullptr;

  SDL_Rect* rect = nullptr;
  
  SDL_Renderer* renderer = nullptr;
  
  const Uint8 MAX_TEXT = 16; 
  
  //std::vector<SDL_Texture*>gameText;
  std::vector<TextSprite*>gameText;

  void addText(std::string text, SDL_Color* c, Vec2 position);
  
  void addText( std::string text, SDL_Color* c, Vec2 position, int w, int h );

  void renderText( Text::text textKey, Vec2 position );
  
  
  TextHandler( TTF_Font* f, SDL_Renderer* r );
  ~TextHandler();

};
