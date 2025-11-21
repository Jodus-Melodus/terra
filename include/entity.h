#ifndef ENTITY_H
#define ENTITY_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct
{
    const char *name;
    const char *texture;
    int width, height, x, y;
    float xVelocity, yVelocity;
} Entity;

Entity *CreateEntity(const char *name, int x, int y, const char *texture, int width, int height);
int EntityOnGround(Entity *entity);
void UpdateEntity(Entity *entity, float deltaTime);

#endif