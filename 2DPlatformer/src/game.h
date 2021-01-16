#ifndef GAME_H
#define GAME_H

// This probably shouldn't be a global
extern bool SHOULD_QUIT;

void poll_inputs();
void game_update();

#endif