#pragma once

#include <cstdint>
#include <math.h>

typedef int32_t int32;

struct Vec2 {
  int32 x, y;

  Vec2() {}
  
  Vec2(int32 x_, int32 y_);
  
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
