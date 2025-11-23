#ifndef SCREEN_H
#define SCREEN_H

#include "layer.h"
#include "types.h"

typedef struct
{
    Layer layers[3];
    TextureMap tileMap;
} ScreenBuffer;

ScreenBuffer CreateScreenBuffer();
void FreeScreenBuffer(ScreenBuffer *screen);

#endif