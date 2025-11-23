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

int RegisterBlock(BlockRegistry *blockRegistry, BlockDefinition *blockDefinition)
{
    if (!blockRegistry)
    {
        printf("RegisterBlock: Invalid block registry pointer\n");
        return 1;
    }

    if (!blockDefinition)
    {
        printf("RegisterBlock: Invalid block definition pointer");
        return 1;
    }

    blockRegistry->registry[blockRegistry->blockCount] = blockDefinition;
    return 0;
}
