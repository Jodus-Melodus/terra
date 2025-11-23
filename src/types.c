#include "types.h"

TextureMap CreateTextureMap(const char *path)
{
    int width, height, channels;
    unsigned char *textureData = stbi_load(path, &width, &height, &channels, 0);
    if (!textureData)
    {
        perror("CreateTextureMap: Failed to read texture");
        exit(1);
    }

    return (TextureMap){
        .width = width,
        .height = height,
        .channels = channels,
        .textureData = textureData};
}

void FreeTextureMap(TextureMap *textureMap)
{
    stbi_image_free(textureMap->textureData);
}
