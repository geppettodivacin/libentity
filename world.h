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

#include "mask.h"

#define ENTITY_COUNT    1048576
#define COMPONENT_COUNT (32 * MASK_LENGTH)

struct World
{
    Mask mask[ ENTITY_COUNT ];
    size_t componentSize[ COMPONENT_COUNT ];
    void * component[ COMPONENT_COUNT ];
    unsigned int nextEntity;
};
typedef struct World World;

World * newWorld ( void );
void freeWorld ( World * world );
void shrinkWorld ( World * world );

#endif
