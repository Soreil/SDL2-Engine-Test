#include "Text.h"
#include <utility>
#include "Graphics.h"
#include <typeinfo>


TextSprite::TextSprite( SDL_Renderer* r, const std::string text, int textSize, SDL_Color* c, TTF_Font* f,
			int x, int y, int w, int h ) {

  texture = Graphics::loadTextTexture( text, r, f, c );
  
  renderQuad.x = x;
  renderQuad.y = y;
  renderQuad.w = w;
  renderQuad.h = h;
  
}

TextSprite::~TextSprite() {
  SDL_DestroyTexture(texture);
  delete texture;
}



TextHandler::TextHandler(TTF_Font* f, SDL_Renderer* r) {
  font = f;
  renderer = r;
  
  rect = new SDL_Rect{0, 0, 0, 0};
  
  // gameText[0] = Gr

  addText( "hello, sailor!", NULL, Vec2{0,0}, 32, 32  );
  
}


void TextHandler::addText( std::string text, SDL_Color* c, Vec2 position, int w, int h ) {
  gameText.push_back( Graphics::loadTextTexture(text, renderer, font, c) );
  printf("Added text to gameArray!\n");

}



void TextHandler::renderText( Text::text textKey, Vec2 position ) {
  if ( gameText[textKey] ) {
    SDL_QueryTexture( gameText[textKey], NULL, NULL, &rect->w, &rect->h ); //TODO(sweets): dangerous, if called 
    SDL_RenderCopy( renderer, gameText[textKey], NULL, rect);              // more than once, it will use the same
  } else {                                                                 // same rect and will probably crash
    printf(" Error! gameText[textKey] is null! No text set for this key! \n");
  }
  
  //    SDL_Texture* ->  gameText[textKey]
  
}


TextHandler::~TextHandler() {
   font = nullptr;
   for (auto t : gameText) {
     SDL_DestroyTexture(t);
     t = nullptr;
   }
}


