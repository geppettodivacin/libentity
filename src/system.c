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

#include "system.h"
#include "util.h"
#include "mask.h"
#include "entity.h"
#include "component.h"

// Query whether an Entity meets the Aspect requirements of a System.
boolean validInSystem ( const Aspect aspect, Entity e, World * world )
{
    return maskSubset ( aspect, world->mask[ e ] );
}

// Set a Component into an Aspect.
void setInAspect ( Aspect aspect, Component c )
{
    maskOr ( aspect, aspect, c );
}

// Remove a Component from an Aspect.
void removeFromAspect ( Aspect aspect, Component c )
{
    maskNand ( aspect, aspect, c );
}

// Clear an Aspect of all Components.
void clearAspect ( Aspect aspect )
{
    maskCopy ( aspect, COMPONENT_NONE );
}

// Query whether an Aspect is empty.
boolean aspectIsEmpty ( Aspect aspect )
{
    return maskEqual ( aspect, COMPONENT_NONE );
}
