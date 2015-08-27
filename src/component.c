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

// Component for a blank entity.
Component COMPONENT_NONE = {0};

// Reduce a Component to an int between 0 and COMPONENT_COUNT. COMPONENT_NONE
// returns -1.
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
    // If everything is 0, return -1. This is technically signed, but the max
    // will never be reached.
    return -1;
}

// Add a Component to a World.
void registerComponent ( void (*defaultInit) ( void * ), Component c
                       , size_t cSize, World * world )
{
    unsigned int index = componentNumber ( c );

    assert ( world->component[ index ] == NULL );
    world->component[ index ] = initComponents ( cSize, defaultInit );
    world->componentSize[ index ] = cSize;
}

// Remove a Component from a World.
void deregisterComponent ( Component c, World * world )
{
    unsigned int index = componentNumber ( c );

    // Remove this Component from all Entities.
    Entity e = 0;
    for ( e = 0; e < ENTITY_COUNT; ++e )
    {
        removeComponent ( e, c, world );
    }
    // Free the used memory and reset metadata.
    if ( world->component[ index ] )
    {
        free ( world->component[ index ] );
        world->component[ index ] = NULL;
        world->componentSize[ index ] = 0;
    }
}

// Allocate memory for the Components and initialize them with defaults.
void * initComponents ( size_t cSize, void (*defaultInit) ( void * ) )
{
    // Allocate enough memory for a component per entity.
    void * components = malloc ( ENTITY_COUNT * cSize );

    // Initialize each Component with a default function.
    void * id = components;
    int i = 0;
    for ( i = 0; i < ENTITY_COUNT; ++i, id += cSize )
    {
        defaultInit ( id );
    }

    return components;
}

// Add a Component to an Entity.
void addComponent ( Entity e, Component c, World * world )
{
    assert ( e < ENTITY_COUNT );

    maskOr ( world->mask[ e ], world->mask[ e ], c );
}

// Remove a Component from an Entity.
void removeComponent ( Entity e, Component c, World * world )
{
    assert ( e < ENTITY_COUNT );

    maskNand ( world->mask[ e ], world->mask[ e ], c );
}

// Query whether an Entity has a given Component.
boolean hasComponent ( Entity e, Component c, World * world )
{
    Mask result;
    Mask * entityMask = &world->mask[ e ];

    maskAnd ( result, c, *entityMask );
    if ( maskEqual ( c, result ) ) return true;

    return false;
}

// Get a pointer to the Component for an Entity.
void * getComponent ( Entity e, Component c, World * world )
{
    // Verify that the requested component exists.
    if ( !hasComponent ( e, c, world ) ) return NULL;

    // Do calculations to find the pointer to the requested component.
    unsigned int index = componentNumber ( c );
    void * ptr = world->component[ index ];
    ptr += e * world->componentSize[ index ];
    return ptr;
}
