
#pragma once

#include "stdio.h"
#include "Vector2.h"
#include <stdlib.h>



class SAT_Rect {
public:
  int32_t x, y, w, h;
  Vec2 half_w, half_h;
  Vec2* center = nullptr;

public:  
  void init() {
    half_w.x = w/2;
    half_h.y = h/2;

    center = new Vec2{ x + w/2, y + h/2 };
    
  }

  SAT_Rect( int32_t x, int32_t y, int32_t w, int32_t h );
  
  
  ~SAT_Rect();

};



namespace SAT {
 
  Vec2 getCollisionVector(SAT_Rect* a, SAT_Rect* b);
  
};
