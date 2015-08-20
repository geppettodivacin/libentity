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
#include <string.h>
#include <stdio.h>

#include "world.h"
#include "entity.h"
#include "mask.h"
#include "component.h"

unsigned int ENTITY_COUNT = 128; // the default maximum number of entities

// Returns a new, empty world.
World * newWorld ( void )
{
    int i;
    // Allocate memory for the world.
    World * world = ( World * ) malloc ( sizeof ( *world ) );

    // Allocate memory for masks.
    world->mask = ( Mask * ) malloc ( ENTITY_COUNT * sizeof ( *world->mask ) );

    // Ensure that all masks are cleared to begin with.
    for ( i = 0; i < ENTITY_COUNT; ++i )
    {
        maskCopy ( world->mask[ i ], COMPONENT_NONE );
    }

    // Ensure that all components are clear.
    for ( i = 0; i < 32 * MASK_LENGTH; ++i )
    {
        world->component[ i ] = NULL;
        world->componentSize[ i ] = 0;
    }

    // The first entity that should be allocated is 0.
    world->nextEntity = 0;

    return world;
}

// Free the world and all data.
void freeWorld ( World * world )
{
    // Free the mask array.
    free ( world->mask );

    // Ensure that all component arrays are freed.
    int i = 0;
    for ( i = 0; i < 32 * MASK_LENGTH; ++i )
    {
        if ( world->component[ i ] ) free ( world->component[ i ] );
    }

    // Free the world itself.
    free ( world );
}

// Shift entities down to the front of the array.
void shrinkWorld ( World * world )
{
    Entity e = 0;
    Entity f = ENTITY_COUNT - 1;
    // Search for the first blank component.
    for ( e = 0; e < f; ++e )
    {
        if ( maskEqual ( world->mask[ e ], COMPONENT_NONE ) )
        {
            // Search for the last non-blank component.
            for ( ; f > e; --f )
            {
                if ( !maskEqual ( world->mask[ f ], COMPONENT_NONE ) )
                {
                    // Swap the masks.
                    maskCopy ( world->mask[ e ], world->mask[ f ] );
                    maskCopy ( world->mask[ f ], COMPONENT_NONE );

                    // Copy the component data of the old to the new entity.
                    unsigned int i = 0;
                    for ( i = 0; i < COMPONENT_COUNT; ++i )
                    {
                        if ( world->component[ i ] != NULL )
                        {
                            unsigned int cSize = world->componentSize[ i ];
                            void * c1 = world->component[ i ] + e * cSize;
                            void * c2 = world->component[ i ] + f * cSize;

                            memcpy ( c1, c2, cSize );
                        }
                    }

                    // Start searching for the next blank.
                    break;
                }
            }
        }
    }
    // Set nextEntity to the next blank entity.
    world->nextEntity = f;
}

// Increase ENTITY_COUNT, increasing the maximum number of entities.
void growWorld ( World * world )
{
    // Double ENTITY_COUNT.
    ENTITY_COUNT *= 2;
    // Reallocate world for the new amount of memory.
    world->mask = realloc ( world->mask
                          , ENTITY_COUNT * sizeof ( *world->mask ) );

    int i = 0;
    // Reallocate all of the arrays of components.
    for ( i = 0; i < COMPONENT_COUNT; ++i )
    {
        if ( world->component[ i ] != NULL )
        {
            size_t cSize = world->componentSize[ i ];
            world->component[ i ] = realloc ( world->component[ i ]
                                            , ENTITY_COUNT * cSize );
        }
    }
}
