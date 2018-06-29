#include "Physics.h"

#include "Collider.h"
#include "SAT.h"


bool Physics::isColliding( Collider* a, Collider* b ) {

  if ( a && b) {
  
    SAT_Rect* sat_a = a->sat_box;
    SAT_Rect* sat_b = b->sat_box;

    // b_box = sat_a :  cBox = sat_b
    
    if ( sat_a->x < sat_b->x + sat_b->w && sat_b->x < sat_a->x + sat_a->w &&
	 sat_a->y < sat_b->y + sat_b->h && sat_b->y < sat_a->y + sat_a->h    ) {

      sat_a = nullptr;
      sat_b = nullptr;
      return true;
    }
    else {
      sat_a = nullptr;
      sat_b = nullptr;
      return false;
    }
  }
  
  
}

