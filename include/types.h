#ifndef TYPES_H
#define TYPES_H

#include <stdlib.h>
#include <stb_image.h>

#define SCREEN_PIXEL_WIDTH 1680
#define SCREEN_PIXEL_HEIGHT 960
#define SCREEN_BLOCK_WIDTH (SCREEN_PIXEL_WIDTH / 24)
#define SCREEN_BLOCK_HEIGHT (SCREEN_PIXEL_HEIGHT / 24)

typedef enum
{
    BackgroundLayer,
    ForegroundLayer,
    MidgroundLayer
} LayerID;

typedef struct
{
    int width, height, channels;
    unsigned char *textureData;
} TextureMap;

TextureMap CreateTextureMap(const char *path);
void FreeTextureMap(TextureMap *textureMap);

#endif