#include "entity.h"

Entity *CreateEntity(const char *name, float x, float y, const char *texture)
{
    Entity *entity = malloc(sizeof(Entity));
    if (!entity)
    {
        printf("CreateEntity: Failed to allocate memory for entity\n");
        return NULL;
    }

    if (!name)
    {
        printf("CreateEntity: Invalid name pointer\n");
        return NULL;
    }

    if (!texture)
    {
        printf("CreateEntity: Invalid texture pointer\n");
        return NULL;
    }

    entity->name = name;
    entity->texture = texture;
    entity->x = x;
    entity->y = y;
    entity->xVelocity = 0;
    entity->yVelocity = 0;
    return entity;
}

void UpdateEntity(Entity *entity, float deltaTime)
{
    entity->x += entity->xVelocity * deltaTime;
    entity->y += entity->yVelocity * deltaTime;
}
