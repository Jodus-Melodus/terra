#include "screen.h"

ScreenBuffer *CreateScreenBuffer(const unsigned int width, const unsigned int height)
{
    ScreenBuffer *screen = malloc(sizeof(ScreenBuffer));
    if (!screen)
    {
        printf("CreateScreenBuffer: Failed to allocate memory for screen buffer\n");
        return NULL;
    }

    screen->layers = malloc(3 * sizeof(Layer *));
    if (!screen->layers)
    {
        free(screen);
        printf("CreateScreenBuffer: Failed to allocate memory for screen buffer layers\n");
        return NULL;
    }

    for (size_t i = 0; i < 3; i++)
    {
        Layer *layer = CreateLayer(width, height);
        if (!layer)
        {
            free(screen->layers);
            free(screen);
            printf("CreateScreenBuffer: Failed to allocate memory for layer in screen buffer layers\n");
            return NULL;
        }
        screen->layers[i] = layer;
    }

    screen->layerCount = 3;
    screen->width = width;
    screen->height = height;
    screen->tileMap = CreateTextureMap("../../textures/tilemap.png");
    return screen;
}

void FreeScreenBuffer(ScreenBuffer *screen)
{
    if (!screen)
        return;
    for (size_t i = 0; i < screen->layerCount; i++)
        FreeLayer(screen->layers[i]);
    free(screen->layers);
    stbi_image_free(screen->tileMap.textureData);
    free(screen);
}
