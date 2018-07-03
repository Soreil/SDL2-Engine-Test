#include "Sprite.h"

#include "Entity.h"


void Sprite::update(Entity* entity) {
  if (renderQuad) {
    renderQuad->x = entity->position.x;
    renderQuad->y = entity->position.y;
  }
}

void Sprite::render(SDL_Renderer* r) {
  if (atlasTex)
    SDL_RenderCopy(r, atlasTex, atlasLoc, renderQuad);
  
}

Sprite::Sprite(SDL_Renderer* r, ResourceManager* resourceManager, Atlas atlas, const std::string spriteName, int x, int y ) {

  this->spriteName = spriteName;

  atlasTex = resourceManager->getAtlasTexture( atlas );
  atlasLoc = resourceManager->getSpriteLocation( spriteName, atlas );

  renderQuad = new SDL_Rect{ x, y, atlasLoc->w, atlasLoc->h };
  
}


Sprite::~Sprite() {
  atlasTex = nullptr;
  atlasLoc = nullptr;
  
  delete renderQuad;
  renderQuad = nullptr;
}
