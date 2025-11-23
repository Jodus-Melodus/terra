#include "block.h"

BlockRegistry *CreateBlockRegistry()
{
    BlockRegistry *blockRegistry = malloc(sizeof(BlockRegistry));
    if (!blockRegistry)
    {
        printf("CreateBlockRegistry: Failed to allocate memory for block registry\n");
        return NULL;
    }

    blockRegistry->blockCount = 0;
    return blockRegistry;
}

int RegisterBlock(BlockRegistry *blockRegistry, BlockDefinition blockDefinition)
{
    if (!blockRegistry)
    {
        printf("RegisterBlock: Invalid block registry pointer\n");
        return 1;
    }

    blockRegistry->registry[blockRegistry->blockCount++] = blockDefinition;
    return 0;
}

int InitializeBlockRegistry(BlockRegistry *blockRegistry)
{
    if (!blockRegistry)
    {
        printf("InitializeBlockRegistry: Invalid block registry pointer\n");
        return 1;
    }

    RegisterBlock(blockRegistry, (BlockDefinition){
                                     .name = "Air",
                                     .isSolid = 0,
                                     .textureIndex = (Vector2){2, 0}});

    RegisterBlock(blockRegistry, (BlockDefinition){
                                     .name = "Grass",
                                     .isSolid = 1,
                                     .textureIndex = (Vector2){0,0}});

    RegisterBlock(blockRegistry, (BlockDefinition){
                                     .name = "Dirt",
                                     .isSolid = 1,
                                     .textureIndex = (Vector2){1,0}});

    

    return 0;
}
