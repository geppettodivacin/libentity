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

typedef unsigned int Entity;

#include "world.h"

Entity newEntity ( World * world );
void destroyEntity ( Entity e, World * world );

#endif
