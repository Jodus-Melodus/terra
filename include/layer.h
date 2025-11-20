#ifndef LAYER_H
#define LAYER_H

#include <stdlib.h>
#include "types.h"
#include "raylib.h"
#include "stb_image.h"

typedef struct
{
    unsigned int width, height;
    Color *buffer;
} Layer;

Layer *CreateLayer(const unsigned int width, const unsigned int height);
int LoadLayerTextureFromFile(Layer *layer, const char *texturePath);
void FreeLayer(Layer *layer);

#endif