/*
 * =============================================================================
 *
 *       Filename:  component.c
 *
 *    Description:  Implementation for Components.
 *
 *        Version:  1.0
 *        Created:  08/12/2015 11:45:00 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Eric Dilmore (), ericdilmore@gmail.com
 *   Organization:  
 *
 * =============================================================================
 */

#include <stdlib.h>
#include <assert.h>

#include "component.h"
#include "entity.h"
#include "mask.h"
#include "util.h"

Component COMPONENT_NONE = {0};
Component COMPONENT_ONE = {1, 0};

unsigned int componentNumber ( Component c )
{
    int i = 0;
    for ( i = 0; i < MASK_LENGTH; ++i )
    {
        if ( c[ i ] )
        {
            return 32 * i + highestSetBit ( c[ i ] );
        }
    }
    return -1;
}

void registerComponent ( void * componentArray, Component c, World * world )
{
    unsigned int index = componentNumber ( c );

    assert ( world->component[ index ] == NULL );
    world->component[ index ] = componentArray;
}

void deregisterComponent ( Component c, World * world )
{
    unsigned int index = componentNumber ( c );

    if ( world->component[ index ] )
    {
        free ( world->component[ index ] );
        world->component[ index ] = NULL;
    }
}

void * initComponents ( size_t cSize )
{
    return malloc ( ENTITY_COUNT * cSize );
}

void addComponent ( Entity e, Component c, World * world )
{
    assert ( e < ENTITY_COUNT );

    maskOr ( world->mask[ e ], world->mask[ e ], c );
}

void removeComponent ( Entity e, Component c, World * world )
{
    assert ( e < ENTITY_COUNT );

    Mask notC;
    maskNot ( notC, c );
    maskAnd ( world->mask[ e ], world->mask[ e ], notC );
}
