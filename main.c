// =============================================================================
// 
//       Filename:  main.c
// 
//    Description:  The main test file.
// 
//        Version:  1.0
//        Created:  08/11/2015 10:38:30 PM
//       Revision:  none
//       Compiler:  gcc
// 
//         Author:  Eric Dilmore (), ericdilmore@gmail.com
//        Company:  
// 
// =============================================================================

#include <stdio.h>
#include <stdlib.h>

#include "util.h"
#include "entity.h"
#include "component.h"
#include "world.h"
#include "system.h"


// A test component with one int property.
Component COMPONENT_ONE = {1, 0};
struct One
{
    int x;
};
typedef struct One One;

// An initializer for the test component. This sets the property to a default
// value of 10.
void oneInit ( void * component )
{
    One * one = ( One * ) component;
    one->x = 10;
}

// A test system. It inspects all entities with a One component and prints the
// value of the One property.
void systemOne ( World * world )
{
    static Aspect aspect;
    if ( aspectIsEmpty ( aspect ) )
    {
        clearAspect ( aspect );
        setInAspect ( aspect, COMPONENT_ONE );
    }

    Entity e = 0;
    for ( e = 0; e < ENTITY_COUNT; ++e )
    {
        if ( validInSystem ( aspect, e, world ) )
        {
            One * one = ( One * ) getComponent ( e, COMPONENT_ONE, world );
            printf ( "Entity %u has a One with x = %d.\n", e, one->x );
        }
    }
}

int main ( int argc, char *argv[] )
{
    // Creates a new World struct.
    World * world = newWorld();
    // Registers the One component with its initializer, its Component tag, and
    // its size.
    registerComponent ( oneInit, COMPONENT_ONE, sizeof ( One ), world );

    // Creates a new Entity. This simply returns the next entity without
    // assigning it any components. If no components are added to it, it may
    // later be considered unused.
    Entity e = newEntity ( world );

    // Add components to the new entity, as well as several others. It is
    // possible to use any number as an entity, as long as it is less than
    // ENTITY_COUNT. The only danger in using arbitrary numbers is that they
    // may be overwritten later by properly created Entities. So don't do that.
    // The use here is simply for example.
    addComponent ( e, COMPONENT_ONE, world );
    addComponent ( 5, COMPONENT_ONE, world );
    addComponent ( 97, COMPONENT_ONE, world );
    addComponent ( 99, COMPONENT_ONE, world );

    // Set the value of the One property of each entity.
    ( ( One * ) getComponent ( e, COMPONENT_ONE, world ) )->x = 1;
    ( ( One * ) getComponent ( 5, COMPONENT_ONE, world ) )->x = 2;
    ( ( One * ) getComponent ( 97, COMPONENT_ONE, world ) )->x = 3;
    ( ( One * ) getComponent ( 99, COMPONENT_ONE, world ) )->x = 4;

    // Move all the Entities to the left, not necessarily in the same order.
    shrinkWorld ( world );
    printf ( "world->nextEntity = %u\n", world->nextEntity );

    // Flood the system with requests for more entities. This triggers the
    // expansion of the World to accomodate more Entities dynamically, up to
    // the max unsized int size.
    int i = 0;
    for ( i = 0; i < 200; ++i )
    {
        e = newEntity ( world );
        addComponent ( e, COMPONENT_ONE, world );
        ( ( One * ) getComponent ( e, COMPONENT_ONE, world ) )->x = 1;
    }
    systemOne ( world );

    // Free the World and its resources.
    freeWorld ( world );
    return EXIT_SUCCESS;
}
