#pragma once

#include <cstdint>
#include <math.h>

struct Vec2 {
  int32_t x, y;

  Vec2() {}
  
  Vec2(int32_t x_, int32_t y_);
  
  void normalize();
  /*
  
  Vec2 operator+(const Vec2& v2);
  Vec2 operator-(const Vec2& v2);
  Vec2 operator*(const Vec2& v2);
  Vec2 operator/(const Vec2& v2);
  */
  Vec2 operator+(const Vec2& v2) {
    return Vec2( x + v2.x, y + v2.y );
  }
  
  Vec2 operator-(const Vec2& v2) {
    return Vec2( x - v2.x, y - v2.y  );
  }
  
  Vec2 operator*(const Vec2& v2) {
    return Vec2( x * v2.x, y * v2.y );
  }
  
  Vec2 operator/(const Vec2& v2) {
    return Vec2( x / v2.x,  y / v2.y );
  }
 
  
};
