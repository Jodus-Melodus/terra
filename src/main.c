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
    Entity *player = CreateEntity("Player", 25, 25, "../../textures/test.png");

    Image image = {
        .data = screen->layers[BackgroundLayer]->buffer,
        .width = width,
        .height = height,
        .format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8,
        .mipmaps = 1};

    Texture2D texture = LoadTextureFromImage(image);

    float deltaTime = 0;

    while (!WindowShouldClose())
    {
        deltaTime = GetFrameTime();

        if (IsKeyDown(KEY_A))
            player->xVelocity = -100;
        else if (IsKeyDown(KEY_D))
            player->xVelocity = 100;
        else
            player->xVelocity = 0;

        if (IsKeyDown(KEY_W))
            player->yVelocity = -100;
        else if (IsKeyDown(KEY_S))
            player->yVelocity = 100;
        else
            player->yVelocity = 0;

        FillLayer(screen->layers[BackgroundLayer], BLACK);
        DrawLayerEntity(screen->layers[BackgroundLayer], player);

        printf("Player coords: (%.2f, %.2f)\n", player->x, player->y);

        UpdateEntity(player, deltaTime);

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