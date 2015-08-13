/*
 * =============================================================================
 *
 *       Filename:  world.h
 *
 *    Description:  Header for World.
 *
 *        Version:  1.0
 *        Created:  08/12/2015 10:19:14 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Eric Dilmore (), ericdilmore@gmail.com
 *   Organization:  
 *
 * =============================================================================
 */

#ifndef WORLD_H
#define WORLD_H

#include "entity.h"
#include "mask.h"

struct World
{
    Mask mask[ ENTITY_COUNT ];
};
typedef struct World World;

World * newWorld ( void );
void freeWorld ( World * world );

#endif
