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

#include "mask.h"
#include "entity.h"
#include "component.h"
#include "world.h"

Entity newEntity ( World * world )
{
    Entity i = 0;
    for ( i = 0; i < ENTITY_COUNT; ++i )
    {
        if ( maskEqual ( world->mask[ i ], COMPONENT_NONE ) )
        {
            return i;
        }
    }
    fprintf ( stderr, "No more entities left.\n" );
    exit ( 1 );
}

void destroyEntity ( Entity e, World * world )
{
    maskCopy ( world->mask[ e ], COMPONENT_NONE );
}
