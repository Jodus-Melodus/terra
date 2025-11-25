#ifndef ENTITY_H
#define ENTITY_H

#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "types.h"

struct Entity
{
    const char *name;
    const char *texture;
};

struct Entity CreateEntity(const char *name, const char *texture);

#endif