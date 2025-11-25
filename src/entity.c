#include "entity.h"

struct Entity CreateEntity(const char *name, const char *texture)
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

    return (struct Entity){
        .name = name,
        .texture = texture,
    };
}