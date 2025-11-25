#include "game.h"

struct Game *CreateGame(unsigned int seed)
{
    struct Game *game = malloc(sizeof(struct Game));
    if (!game)
    {
        perror("Failed to allocate memory for game");
        return NULL;
    }

    game->screen = CreateScreenBuffer();
    game->blockRegistry = CreateBlockRegistry();
    game->player = CreateEntity("Player", 50, 50, "../../textures/test.png");
    game->camera = (Vector2){0, 0};

    InitializeBlockRegistry(&game->blockRegistry);
    InitWindow(SCREEN_PIXEL_WIDTH, SCREEN_PIXEL_HEIGHT, "Terra");

    Image backgroundImage = {
        .data = game->screen.layers[BackgroundLayer].buffer,
        .width = SCREEN_PIXEL_WIDTH,
        .height = SCREEN_PIXEL_HEIGHT,
        .format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8,
        .mipmaps = 1};

    game->textures[BackgroundLayer] = LoadTextureFromImage(backgroundImage);

    LoadLayerTextureFromFile(&game->screen.layers[BackgroundLayer], 0, 0, "../../textures/background.png");
    UpdateTexture(game->textures[BackgroundLayer], game->screen.layers[BackgroundLayer].buffer);

    Image midgroundImage = {
        .data = game->screen.layers[MidgroundLayer].buffer,
        .width = SCREEN_PIXEL_WIDTH,
        .height = SCREEN_PIXEL_HEIGHT,
        .format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8,
        .mipmaps = 1};

    game->textures[MidgroundLayer] = LoadTextureFromImage(midgroundImage);

    Image foregroundImage = {
        .data = game->screen.layers[ForegroundLayer].buffer,
        .width = SCREEN_PIXEL_WIDTH,
        .height = SCREEN_PIXEL_HEIGHT,
        .format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8,
        .mipmaps = 1};

    game->textures[ForegroundLayer] = LoadTextureFromImage(foregroundImage);
    noiseSeed(seed);

    return game;
}

enum BlockID GetWorldBlock(struct Game *game, int x)
{

    // TODO different blocks for given height
    return BI_Grass;
}

int RunGame(struct Game *game)
{
    if (!game)
    {
        printf("RunGame: Invalid game pointer\n");
        return 1;
    }

    SetTargetFPS(60);
    surroundingBlocks[Down] = game->blockRegistry.registry[BI_Air];

    while (!WindowShouldClose())
    {
        deltaTime = GetFrameTime();
        mousePosition = GetMousePosition();
        HandlePlayerMovement(game);
        RedrawGame(game);
    }

    return 0;
}

void HandlePlayerMovement(struct Game *game)
{
    if (IsKeyDown(KEY_A))
        game->camera.x -= BLOCK_SIZE/8;
    if (IsKeyDown(KEY_D))
        game->camera.x += BLOCK_SIZE/8;
    if (IsKeyDown(KEY_SPACE))
        game->camera.y -= BLOCK_SIZE;
}

int DrawWorld(struct Game *game)
{
    int startX = game->camera.x / BLOCK_SIZE;
    int endX = startX + SCREEN_BLOCK_WIDTH;

    for (int x = startX; x < endX; x++)
    {
        float terrain = noiseGet(x * 0.05f);
        int heightBlocks = (int)(terrain * (SCREEN_BLOCK_HEIGHT / 2)) + (SCREEN_BLOCK_HEIGHT / 4);

        struct BlockDefinition *block = &game->blockRegistry.registry[BI_Grass];
        DrawLayerBlock(
            &game->screen.layers[MidgroundLayer],
            game->screen.tileMap,
            (x * BLOCK_SIZE) - game->camera.x,
            (heightBlocks * BLOCK_SIZE) - game->camera.y,
            block);
    }

    return 0;
}

void RedrawGame(struct Game *game)
{
    FillLayer(&game->screen.layers[MidgroundLayer], BLANK);
    FillLayer(&game->screen.layers[ForegroundLayer], BLANK);
    DrawWorld(game);
    DrawLayerEntity(&game->screen.layers[MidgroundLayer], &game->player);
    LoadLayerTextureFromFile(
        &game->screen.layers[ForegroundLayer],
        (int)(mousePosition.x / BLOCK_SIZE) * BLOCK_SIZE,
        (int)(mousePosition.y / BLOCK_SIZE) * BLOCK_SIZE,
        "../../textures/mouse.png");

    UpdateTexture(game->textures[MidgroundLayer], game->screen.layers[MidgroundLayer].buffer);
    UpdateTexture(game->textures[ForegroundLayer], game->screen.layers[ForegroundLayer].buffer);
    BeginDrawing();
    ClearBackground(BLACK);
    DrawTexture(game->textures[BackgroundLayer], 0, 0, WHITE);
    DrawTexture(game->textures[MidgroundLayer], 0, 0, WHITE);
    DrawTexture(game->textures[ForegroundLayer], 0, 0, WHITE);
    EndDrawing();
}

void FinishGame(struct Game *game)
{
    if (!game)
    {
        printf("FinishGame: Invalid game pointer\n");
        return;
    }

    UnloadTexture(game->textures[BackgroundLayer]);
    UnloadTexture(game->textures[MidgroundLayer]);
    CloseWindow();
}
