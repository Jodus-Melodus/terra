#ifndef LAYER_H
#define LAYER_H

#include <stdlib.h>
#include <raylib.h>
#include <stb_image.h>

#include "types.h"
#include "entity.h"
#include "block.h"

typedef struct
{
    Color buffer[SCREEN_PIXEL_WIDTH * SCREEN_PIXEL_HEIGHT];
} Layer;

Layer CreateLayer();
int LoadLayerTextureFromFile(Layer *layer, const unsigned int x, const unsigned int y, const char *texturePath);
int DrawLayerEntity(Layer *layer, Entity *entity);
int FillLayer(Layer *layer, Color color);
int DrawLayerBlock(Layer *layer, TextureMap tileMap, const unsigned int x, const unsigned int y, BlockDefinition *blockDefinition);

#endif