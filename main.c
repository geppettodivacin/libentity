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


struct One
{
    int x;
};
typedef struct One One;

void oneInit ( void * component )
{
    One * one = ( One * ) component;
    one->x = 10;
}

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
    World * world = newWorld();
    registerComponent ( oneInit, COMPONENT_ONE, sizeof ( One ), world );

    Entity e = newEntity ( world );

    addComponent ( e, COMPONENT_ONE, world );
    addComponent ( 5, COMPONENT_ONE, world );
    addComponent ( 97, COMPONENT_ONE, world );
    addComponent ( 99, COMPONENT_ONE, world );

    ( ( One * ) getComponent ( e, COMPONENT_ONE, world ) )->x = 1;
    ( ( One * ) getComponent ( 5, COMPONENT_ONE, world ) )->x = 2;
    ( ( One * ) getComponent ( 97, COMPONENT_ONE, world ) )->x = 3;
    ( ( One * ) getComponent ( 99, COMPONENT_ONE, world ) )->x = 4;

    shrinkWorld ( world );
    systemOne ( world );

    freeWorld ( world );
    return EXIT_SUCCESS;
}
