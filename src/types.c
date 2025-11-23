#include "types.h"

TextureMap CreateTextureMap(const char *path)
{
    int width, height, channels;
    unsigned char *textureData = stbi_load(path, &width, &height, &channels, 0);
    if (!textureData)
    {
        printf("DrawLayerBlock: Failed to read texture\n");
        return;
    }

    return (TextureMap){
        .width = width,
        .height = height,
        .channels = channels,
        .textureData = textureData};
}