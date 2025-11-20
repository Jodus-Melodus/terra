#include "layer.h"

Layer *CreateLayer(const unsigned char width, const unsigned char height)
{
    Layer *layer = calloc(0, sizeof(Layer));
    if (!layer)
        return NULL;
    layer->buffer = calloc(0, sizeof(Color) * width * height);
    if (!layer->buffer)
    {
        free(layer);
        return NULL;
    }
    layer->height = height;
    layer->width = width;
    return layer;
}

void FreeLayer(Layer *layer)
{
    if (!layer)
        return NULL;
    free(layer->buffer);
    free(layer);
}
