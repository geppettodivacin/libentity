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
#include "mask.h"
#include "entity.h"
#include "component.h"
#include "world.h"


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

int main ( int argc, char *argv[] )
{
    World * world = newWorld();
    registerComponent ( oneInit, COMPONENT_ONE, sizeof ( One ), world );

    Entity e = newEntity ( world );

    printf ( "Entity %d %s COMPONENT_ONE\n", e
           , hasComponent ( e, COMPONENT_ONE, world )
           ? "has" : "does not have" );
    addComponent ( e, COMPONENT_ONE, world );
    printf ( "Entity %d %s COMPONENT_ONE\n", e
           , hasComponent ( e, COMPONENT_ONE, world )
           ? "has" : "does not have" );
    printf ( "Entity %d %s COMPONENT_ONE\n", 1
           , hasComponent ( 1, COMPONENT_ONE, world )
           ? "has" : "does not have" );

    One * one = ( One * ) getComponent ( e, COMPONENT_ONE, world );
    if ( !one )
    {
        printf ( "Entity does not have the requested component.\n" );
        freeWorld ( world );
        return EXIT_FAILURE;
    }

    one->x = 5;

    One * two = ( One * ) getComponent ( e, COMPONENT_ONE, world );
    printf ( "This entity has COMPONENT_ONE with an x of %d.\n", two->x );

    freeWorld ( world );
    return EXIT_SUCCESS;
}
