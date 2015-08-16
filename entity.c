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

Entity newEntity ( World * world )
{
    if ( world->nextEntity == ENTITY_COUNT )
    {
        growWorld ( world );
    }

    return world->nextEntity++;
}

void destroyEntity ( Entity e, World * world )
{
    maskCopy ( world->mask[ e ], COMPONENT_NONE );
}
