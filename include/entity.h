#ifndef ENTITY_H
#define ENTITY_H

#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    const char *name;
    unsigned int x, y;
    const char *texture;
} Entity;

Entity *CreateEntity(const char *name, unsigned int x, unsigned int y, const char *texture);
int MoveEntity(Entity *entity, int x, int y);
void FreeEntity(Entity *entity);

#endif