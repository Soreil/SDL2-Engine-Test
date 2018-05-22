#include "Vector2.h"


Vec2::Vec2(int32 x_, int32 y_)
  : x(x_),
    y(y_)
{} 


void Vec2::normalize() {
  if ( x != 0 && y != 0 ) {
    x /= sqrt(2);
    x /= sqrt(2);
  }
}
/*
Vec2 Vec2::operator+(const Vec2& v2) {
  return Vec2( x + v2.x, y + v2.y );
}

Vec2 Vec2::operator-(const Vec2& v2) {
  return Vec2( x - v2.x, y - v2.y  );
}

Vec2 Vec2::operator*(const Vec2& v2) {
  return Vec2( x * v2.x, y * v2.y );
}

Vec2 Vec2::operator/(const Vec2& v2) {
  return Vec2( x / v2.x,  y / v2.y );
  }*/
  
