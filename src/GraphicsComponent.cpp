#include "GraphicsComponent.h"
#include "Graphics.h"



GraphicsComponent::GraphicsComponent( SDL_Renderer* r, const std::string texturePath,
				      Vec2* position, SDL_Rect* rQuad ) {
  if (r)
    renderer = r;
  sprite = new Sprite( r, texturePath, position, rQuad );
  
}

void GraphicsComponent::update() {

}

void GraphicsComponent::update(Entity* entity){
  sprite->render(renderer);
}




GraphicsComponent::~GraphicsComponent() {
  renderer = nullptr;
  delete sprite;

  /*
  SDL_DestroyTexture(texture);
  texture  = nullptr;
  delete renderArea;
  renderArea = nullptr;
  */
}
