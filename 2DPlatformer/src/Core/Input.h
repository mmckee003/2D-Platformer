#pragma once

#include "KeyCodes.h"

struct Input
{
	static bool is_key_pressed(Keycode keycode);
	static bool is_mouse_button_pressed(int button);
	static float get_mouse_x();
	static float get_mouse_y();
	// static std::pair<float, float> get_mouse_position();
};