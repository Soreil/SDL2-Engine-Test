#include "GraphicsComponent.h"
#include "Graphics.h"


GraphicsComponent::GraphicsComponent(SDL_Renderer* r) {
  if (r)
    renderer = r;
}

GraphicsComponent::GraphicsComponent(SDL_Renderer* r, const std::string pathfile) {
  if (r)
    renderer = r;
  setTexture(r, pathfile.c_str());
}


void GraphicsComponent::update() {

}

void GraphicsComponent::update(Entity* entity){
  SDL_RenderCopy( renderer, texture, NULL, NULL );
}

void GraphicsComponent::setTexture(SDL_Renderer* r, const std::string pathfile) {
  texture = Graphics::loadTexture(r, pathfile.c_str() );
  if (!texture)
    printf("Err loading texture to graphics component!: %s", SDL_GetError());
}

GraphicsComponent::~GraphicsComponent() {
  renderer = nullptr;
  SDL_DestroyTexture(texture);
  texture  = nullptr;
  delete renderArea;
  renderArea = nullptr;
}
