#include "Sprite.h"



void Sprite::render(SDL_Renderer* r) {
  SDL_RenderCopy(r, texture, NULL, renderQuad);
}


Sprite::Sprite(SDL_Renderer* r, const std::string textureName, Vec2* position, SDL_Rect* rQuad) {
  texture = Graphics::loadTexture(r,textureName);
  if ( !rQuad ) {
    if ( !position ) {
      renderQuad = new SDL_Rect{0,0};
    } else {
      renderQuad = new SDL_Rect{position->x, position->y};
      delete position;
    }
    SDL_QueryTexture(texture , NULL, NULL, &renderQuad->w, &renderQuad->h );

  } else {
    renderQuad = rQuad;
    if (position)
      renderQuad->x = position->x; renderQuad->y = position->y;
  }
}


Sprite::~Sprite() {
  SDL_DestroyTexture(texture);
  texture = nullptr;

  delete renderQuad;
}
