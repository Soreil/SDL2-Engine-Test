#pragma once

#include <math.h>

struct Vec2 {
	int x, y;
	void normalize() {
		if (x != 0 && y != 0) {
			x /= sqrt(2);
			y /= sqrt(2);
		}
	}
};
