#include "Player.h"

#include <vector>
#include "GraphicsComponent.h"
#include "PhysicsComponent.h"
#include "PlayerInputComponent.h"
#include "Vector2.h"



Entity* Player::createPlayer(SDL_Renderer* r) {
  return new Entity(
		    std::vector<Component*>{
		      new GraphicsComponent(r, "resources/ass.bmp", NULL, new SDL_Rect{0,0,800,600} ),
			new PhysicsComponent(0, 0, 32, 32),
			new PlayerInputComponent()
			}
		    );
}
