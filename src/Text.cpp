#include "Text.h"
#include <utility>
#include "Graphics.h"
#include <typeinfo>



TextSprite::TextSprite( SDL_Renderer* r, const std::string text, SDL_Color c, TTF_Font* f,
			int x, int y ) {

  
  texture = Graphics::loadTextTexture( text, r, f, c );
  
  renderQuad = new SDL_Rect{x, y};

  SDL_QueryTexture( texture, NULL, NULL, &renderQuad->w, &renderQuad->h );
  
}



TextSprite::TextSprite( SDL_Renderer* r, const std::string text, int textSize, SDL_Color c, TTF_Font* f,
			int x, int y, int w, int h ) {

  texture = Graphics::loadTextTexture( text, r, f, c );

  if ( w == -1 || h == -1 ) {
    renderQuad = new SDL_Rect{ x, y };
    SDL_QueryTexture( texture, NULL, NULL, &renderQuad->w, &renderQuad->h );
  } else {
  renderQuad = new SDL_Rect{x, y, w, h};  
  }
}

void TextSprite::render(SDL_Renderer* r) {
  if (texture)
    SDL_RenderCopy( r, texture, NULL, renderQuad );
  
}

TextSprite::~TextSprite() {
  SDL_DestroyTexture(texture);
  texture = nullptr;
  delete renderQuad;
}


void TextHandler::addText(std::string text, SDL_Color c, Vec2 position) {
  gameText.push_back( new TextSprite(renderer, text, c, font, position.x, position.y ) );
  printf( "Added text to gameText vector!\n" );
}


void TextHandler::addText( std::string text, SDL_Color c, Vec2 position, int w, int h ) {
  //  gameText.push_back( Graphics::loadTextTexture(text, renderer, font, c) );
  printf("Added text to gameArray!\n");

}



void TextHandler::renderText( Text::text textKey, Vec2 position ) {
  if ( gameText[textKey] ) {
    SDL_RenderCopy( renderer, gameText[textKey]->texture, NULL, gameText[textKey]->renderQuad);
  } else {                                                                 
    printf(" Error! gameText[textKey] is null! No text set for this key! \n");
  }
  
  //    SDL_Texture* ->  gameText[textKey]
}

TextHandler::TextHandler(TTF_Font* f, SDL_Renderer* r) {
  font = f;
  renderer = r;

  addText( "hello, sailor!", SDL_Color{255,0,255}, Vec2{0,0} );  
}

TextHandler::~TextHandler() {
  renderer = nullptr;
  font = nullptr;
  for (auto t : gameText) {
    delete t;
    t = nullptr;
  }
}


