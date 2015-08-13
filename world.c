/*
 * =============================================================================
 *
 *       Filename:  world.c
 *
 *    Description:  Implementation for World functions.
 *
 *        Version:  1.0
 *        Created:  08/12/2015 11:52:43 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Eric Dilmore (), ericdilmore@gmail.com
 *   Organization:  
 *
 * =============================================================================
 */

#include <stdlib.h>

#include "entity.h"
#include "world.h"
#include "mask.h"
#include "component.h"

World * newWorld ( void )
{
    int i;
    World * world = ( World * ) malloc ( sizeof ( *world ) );

    for ( i = 0; i < ENTITY_COUNT; ++i )
    {
        maskCopy ( world->mask[ i ], COMPONENT_NONE );
    }

    for ( i = 0; i < 32 * MASK_LENGTH; ++i )
    {
        world->component[ i ] = NULL;
        world->componentSize[ i ] = 0;
    }

    return world;
}

void freeWorld ( World * world )
{
    int i = 0;
    for ( i = 0; i < 32 * MASK_LENGTH; ++i )
    {
        if ( world->component[ i ] ) free ( world->component[ i ] );
    }

    free ( world );
}
