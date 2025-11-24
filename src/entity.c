#include "entity.h"

Entity CreateEntity(const char *name, int x, int y, const char *texture, int width, int height)
{
    if (!name)
    {
        printf("CreateEntity: Invalid name pointer\n");
        exit(1);
    }

    if (!texture)
    {
        printf("CreateEntity: Invalid texture pointer\n");
        exit(1);
    }

    return (Entity){
        .name = name,
        .texture = texture,
        .height = height,
        .width = width,
        .velocity = {0, 0},
        .x = x,
        .y = y};
}

int EntityOnGround(Entity *entity)
{
    if (!entity)
    {
        printf("EntityOnGround: Invalid entity pointer\n");
        return 1;
    }

    return entity->y >= GROUND_LEVEL;
}

void UpdateEntity(Entity *entity, float deltaTime)
{
    entity->x += round(entity->velocity.x * deltaTime);
    entity->y += round(entity->velocity.y * deltaTime);
}
