/*
 * =============================================================================
 *
 *       Filename:  entity.c
 *
 *    Description:  Implementation for Entity functions.
 *
 *        Version:  1.0
 *        Created:  08/12/2015 11:31:57 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Eric Dilmore (), ericdilmore@gmail.com
 *   Organization:  
 *
 * =============================================================================
 */

#include <stdlib.h>
#include <stdio.h>

#include "entity.h"
#include "mask.h"
#include "component.h"
#include "world.h"

// Gives the next valid, empty Entity. If there are not enough entities left,
// the world will grow.
Entity newEntity ( World * world )
{
    // If there is too little space for a new Entity...
    if ( world->nextEntity == ENTITY_COUNT )
    {
        // ... then grow the world.
        growWorld ( world );
    }

    return world->nextEntity++;
}

// Clear the Entity of any Components, leaving it available for reuse.
void destroyEntity ( Entity e, World * world )
{
    maskCopy ( world->mask[ e ], COMPONENT_NONE );
}
