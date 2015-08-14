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
#include "system.h"

bool validInSystem ( const Aspect aspect, Entity e, World * world )
{
    return maskSubset ( aspect, world->mask[ e ] );
}

void setInAspect ( Aspect aspect, Component c )
{
    maskOr ( aspect, aspect, c );
}

void removeFromAspect ( Aspect aspect, Component c )
{
    maskNand ( aspect, aspect, c );
}

void clearAspect ( Aspect aspect )
{
    maskCopy ( aspect, COMPONENT_NONE );
}

bool aspectIsEmpty ( Aspect aspect )
{
    return maskEqual ( aspect, COMPONENT_NONE );
}
