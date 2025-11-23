#ifndef TYPES_H
#define TYPES_H

#include <stdlib.h>

typedef enum
{
    BackgroundLayer,
    ForegroundLayer,
    MidgroundLayer
} LayerID;

typedef struct {
    int width, height, channels;
    unsigned char *textureData;
} TextureMap;

TextureMap CreateTextureMap(const char *path);

#endif