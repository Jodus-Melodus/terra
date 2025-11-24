#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "screen.h"
#include "block.h"
#include "types.h"
#include "entity.h"
#include "utils.h"

static float deltaTime = 0;
static int groundLevel = GROUND_LEVEL;
static Vector2 mousePosition;
static BlockDefinition surroundingBlocks[4];

typedef struct
{
    ScreenBuffer screen;
    BlockRegistry blockRegistry;
    Entity player;
    BlockID world[SCREEN_BLOCK_HEIGHT][SCREEN_BLOCK_WIDTH];
    Texture2D textures[3];
} Game;

Game *CreateGame();
int GenerateWorld(Game *game, unsigned int seed);
int RunGame(Game *game);
void HandlePlayerMovement(Game *game);
int DrawWorld(Game *game);
void RedrawGame(Game *game);
void FinishGame(Game *game);

#endif