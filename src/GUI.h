#pragma once
#include "SDL.h"

struct Button {
	SDL_Rect rect;
	SDL_Surface* tex;
	bool contains(int x, int y)
	{
		if ((x > this->rect.x) && (x < this->rect.x + this->rect.w) && (y > this->rect.y) && (y < this->rect.y + this->rect.h))
		{
			return true;
		}
		else {
			return false;
		}
	}
	void(*on_clicked)(bool is_clicked);
	void set_click_function(void(*func_ptr)(bool is_clicked))
	{
		this->on_clicked = func_ptr;
	}
	bool is_clicked;

	void cleanup()
	{
		SDL_FreeSurface(tex);
		tex = nullptr;
	}
};


