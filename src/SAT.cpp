#include "SAT.h"

SAT_Rect::SAT_Rect(int32_t x, int32_t y, int32_t w, int32_t h) : x(x), y(y), w(w), h(h) {
  half_w.x = w/2;
  half_h.y = h/2;

  center = new Vec2{ x + w/2, y + h/2 };
}

SAT_Rect::~SAT_Rect() {
  delete center;
  center = nullptr;
}




