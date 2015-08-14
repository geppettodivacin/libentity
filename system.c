/*
 * =============================================================================
 *
 *       Filename:  system.c
 *
 *    Description:  Implementation for system functions and macros.
 *
 *        Version:  1.0
 *        Created:  08/14/2015 10:33:28 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Eric Dilmore (), ericdilmore@gmail.com
 *   Organization:  
 *
 * =============================================================================
 */

#include <stdlib.h>

#include "util.h"
#include "mask.h"
#include "entity.h"
#include "component.h"

bool validInSystem ( const Mask sysMask, Entity e, World * world )
{
    return maskSubset ( sysMask, world->mask[ e ] );
}
