#include <stdio.h>

#include "raylib.h"
#include "screen.h"
#include "entity.h"

int main()
{
    const unsigned int width = 1700;
    const unsigned int height = 960;

    InitWindow(width, height, "Terra");
    SetTargetFPS(60);

    ScreenBuffer *screen = CreateScreenBuffer(width, height);
    Entity *player = CreateEntity("Player", 0, 0, "../../textures/test.png");

    Image image = {
        .data = screen->layers[BackgroundLayer]->buffer,
        .width = width,
        .height = height,
        .format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8,
        .mipmaps = 1};

    Texture2D texture = LoadTextureFromImage(image);

    while (!WindowShouldClose())
    {
        if (IsKeyDown(KEY_A))
            player->x -= 1;
        if (IsKeyDown(KEY_D))
            player->x += 1;
        if (IsKeyDown(KEY_W))
            player->y -= 1;
        if (IsKeyDown(KEY_S))
            player->y += 1;

        FillLayer(screen->layers[BackgroundLayer], BLACK);
        DrawLayerEntity(screen->layers[BackgroundLayer], player);

        UpdateTexture(texture, screen->layers[BackgroundLayer]->buffer);
        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexture(texture, 0, 0, WHITE);
        EndDrawing();
    }

    FreeScreenBuffer(screen);
    UnloadTexture(texture);
    CloseWindow();
    return 0;
}