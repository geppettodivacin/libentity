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

void registerComponent ( void (*defaultInit) ( void * ), Component c
                       , size_t cSize, World * world )
{
    unsigned int index = componentNumber ( c );

    assert ( world->component[ index ] == NULL );
    world->component[ index ] = initComponents ( cSize, defaultInit );
    world->componentSize[ index ] = cSize;
}

void deregisterComponent ( Component c, World * world )
{
    unsigned int index = componentNumber ( c );

    Entity e = 0;
    for ( e = 0; e < ENTITY_COUNT; ++e )
    {
        removeComponent ( e, c, world );
    }
    if ( world->component[ index ] )
    {
        free ( world->component[ index ] );
        world->component[ index ] = NULL;
        world->componentSize[ index ] = 0;
    }
}

void * initComponents ( size_t cSize, void (*defaultInit) ( void * ) )
{
    void * components = malloc ( ENTITY_COUNT * cSize );

    void * id = components;
    int i = 0;
    for ( i = 0; i < ENTITY_COUNT; ++i, id += cSize )
    {
        defaultInit ( id );
    }

    return components;
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

bool hasComponent ( Entity e, Component c, World * world )
{
    Mask result;
    Mask * entityMask = &world->mask[ e ];

    maskAnd ( result, c, *entityMask );
    if ( maskEqual ( c, result ) ) return true;

    return false;
}

void * getComponent ( Entity e, Component c, World * world )
{
    if ( !hasComponent ( e, c, world ) ) return NULL;

    unsigned int index = componentNumber ( c );
    void * ptr = world->component[ index ];
    ptr += e * world->componentSize[ index ];
    return ptr;
}
