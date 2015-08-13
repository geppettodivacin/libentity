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

Component COMPONENT_NONE = {0};

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
