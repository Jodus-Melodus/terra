#include <stdio.h>

#include "raylib.h"
#include "screen.h"

int main()
{
    const unsigned int width = 1700;
    const unsigned int height = 960;

    InitWindow(width, height, "Terra");
    SetTargetFPS(60);

    ScreenBuffer *screen = CreateScreenBuffer(width, height);

    Image image = {
        .data = screen->layers[BackgroundLayer]->buffer,
        .width = width,
        .height = height,
        .format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8,
        .mipmaps = 1};

    Texture2D texture = LoadTextureFromImage(image);

    while (!WindowShouldClose())
    {
        UpdateTexture(texture, screen->layers[BackgroundLayer]->buffer);
        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexture(texture, 0, 0, WHITE);
        EndDrawing();
    }

    UnloadTexture(texture);
    FreeScreenBuffer(screen);
    CloseWindow();
    return 0;
}