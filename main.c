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

int main ( int argc, char *argv[] )
{
    World * world = newWorld();
    Entity e = newEntity ( world );
    addComponent ( e, COMPONENT_ONE, world );
    printMask ( world->mask[ e ] );
    printf ( "Next entity: %d\n", newEntity ( world ) );
    removeComponent ( e, COMPONENT_ONE, world );
    printMask ( world->mask[ e ] );
    printf ( "Next entity: %d\n", newEntity ( world ) );
    freeWorld ( world );
    return EXIT_SUCCESS;
}
