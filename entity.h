/*
 * =============================================================================
 *
 *       Filename:  entity.h
 *
 *    Description:  Header for Entity functions.
 *
 *        Version:  1.0
 *        Created:  08/12/2015 08:59:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Eric Dilmore (), ericdilmore@gmail.com
 *   Organization:  
 *
 * =============================================================================
 */

#ifndef ENTITY_H
#define ENTITY_H

// An Entity is simply an int tag that stands for an object.
typedef unsigned int Entity;

#include "world.h"

// Gives the next valid, empty Entity. If there are not enough entities left,
// the world will grow.
Entity newEntity ( World * world );
// Clear the Entity of any Components, leaving it available for reuse.
void destroyEntity ( Entity e, World * world );

#endif
