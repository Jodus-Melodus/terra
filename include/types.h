#ifndef TYPES_H
#define TYPES_H

#include <stdlib.h>
#include <stb_image.h>

#define SCREEN_PIXEL_WIDTH 1680
#define SCREEN_PIXEL_HEIGHT 960
#define BLOCK_SIZE 48
#define SCREEN_BLOCK_WIDTH (SCREEN_PIXEL_WIDTH / BLOCK_SIZE)
#define SCREEN_BLOCK_HEIGHT (SCREEN_PIXEL_HEIGHT / BLOCK_SIZE)
#define GROUND_LEVEL (SCREEN_PIXEL_HEIGHT - BLOCK_SIZE)

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