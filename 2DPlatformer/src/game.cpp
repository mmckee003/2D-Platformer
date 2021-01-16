#include "game.h"

// TODO: Make this platform independent (1/16/21)
#include "Windows.h"

#include <iostream>

// TODO: Make this platform independent (1/16/21)
void poll_inputs()
{
    MSG message;
	while (PeekMessage(&message, NULL, 0, 0, 1) > 0)
	{
		// TODO: look into DispatchMessageW(...) (1/16/21)
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
}

void game_update()
{
	SHOULD_QUIT = false;
	while (true)
	{
		poll_inputs();

		if (SHOULD_QUIT)
		{
			break;
		}
		//std::cout << "Game Loop!\n";
	}
}