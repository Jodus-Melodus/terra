#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <stdio.h>

#include "screen.h"
#include "block.h"

#define SCREEN_WIDTH 1700
#define SCREEN_HEIGHT 950

typedef struct
{
    ScreenBuffer *screen;
    BlockRegistry *blockRegistry;
    BlockID world[10][10];
} Game;

Game *CreateGame();

#endif