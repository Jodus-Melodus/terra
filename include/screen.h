#ifndef SCREEN_H
#define SCREEN_H

#include "layer.h"

typedef struct
{
    unsigned char layerCount;
    Layer *layers;
} ScreenBuffer;

#endif