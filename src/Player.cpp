#include "Player.h"

#include <vector>
#include "GraphicsComponent.h"
#include "PhysicsComponent.h"
#include "PlayerInputComponent.h"




Entity* Player::createPlayer(SDL_Renderer* r) {
  return new Entity(
		    std::vector<Component*>{
		      new GraphicsComponent(r, "resources/ass.bmp"),
			new PhysicsComponent(0, 0, 32, 32),
			new PlayerInputComponent()
			}
		    );
}
