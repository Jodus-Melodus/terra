#include "entity.h"

Entity *CreateEntity(const char *name, unsigned int x, unsigned int y, const char *texture)
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
    entity->x = x;
    entity->y = y;
    entity->texture = texture;
    return entity;
}

int MoveEntity(Entity *entity, int x, int y)
{
    if (!entity)
    {
        printf("MoveEntity: Invalid entity pointer\n");
        return 1;
    }

    entity->x += x;
    entity->y += y;
    return 0;
}

void FreeEntity(Entity *entity)
{
    if (!entity)
        return;
    if (entity->name)
        free(entity->name);
    if (entity->texture)
        free(entity->texture);
}
