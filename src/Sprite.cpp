#include "Sprite.h"

#include "Entity.h"

void Sprite::update(Entity* entity) {
  renderQuad->x = entity->position.x;
  renderQuad->y = entity->position.y;
}

void Sprite::render(SDL_Renderer* r) {
  if (texture)
    SDL_RenderCopy(r, texture, NULL, renderQuad);
  
}


void Sprite::setTexture(SDL_Renderer* r, const std::string textureName) {
  if (r)
    texture = Graphics::loadTexture(r, textureName);
}


Sprite::Sprite(SDL_Renderer* r, const std::string textureName, Vec2* position, SDL_Rect* rQuad) {
  if (r)
    texture = Graphics::loadTexture(r,textureName);
  
  
  if (!texture) {
    printf("Error loading texture for sprite class!\n" );
      }
  else {
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
     
      if (position) {
	renderQuad->x = position->x;
	renderQuad->y = position->y;
      }
    }
  }
}


Sprite::~Sprite() {
  SDL_DestroyTexture(texture);
  texture = nullptr;

  delete renderQuad;
}
