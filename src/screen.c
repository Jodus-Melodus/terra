#include "screen.h"

ScreenBuffer *CreateScreenBuffer(const unsigned int width, const unsigned int height)
{
    ScreenBuffer *screen = malloc(sizeof(ScreenBuffer));
    if (!screen)
        return NULL;

    screen->layers = malloc(3 * sizeof(Layer *));
    if (!screen->layers)
    {
        free(screen);
        return NULL;
    }

    for (size_t i = 0; i < 3; i++)
    {
        Layer *layer = CreateLayer(width, height);
        if (!layer)
        {
            free(screen->layers);
            free(screen);
            return NULL;
        }
        screen->layers[i] = layer;
    }

    screen->layerCount = 3;
    screen->width = width;
    screen->height = height;
    return screen;
}

void FreeScreenBuffer(ScreenBuffer *screen)
{
    if (!screen)
        return;
    for (size_t i = 0; i < screen->layerCount; i++)
        FreeLayer(screen->layers[i]);
    free(screen->layers);
    free(screen);
}
