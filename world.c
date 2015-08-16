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

    world->nextEntity = 0;

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

void shrinkWorld ( World * world )
{
    Entity e = 0;
    Entity f = ENTITY_COUNT - 1;
    for ( e = 0; e < f; ++e )
    {
        if ( maskEqual ( world->mask[ e ], COMPONENT_NONE ) )
        {
            for ( ; f > e; --f )
            {
                if ( !maskEqual ( world->mask[ f ], COMPONENT_NONE ) )
                {
                    maskCopy ( world->mask[ e ], world->mask[ f ] );
                    maskCopy ( world->mask[ f ], COMPONENT_NONE );

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

                    break;
                }
            }
        }
    }
    world->nextEntity = f;
}
