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

// the maximum number of entities possible without growing
extern unsigned int ENTITY_COUNT;
#define COMPONENT_COUNT (32 * MASK_LENGTH) // the maximum number of components

// Holds state data for entities and components.
struct World
{
    Mask * mask; // masks for the component ownership of entities
    size_t componentSize[ COMPONENT_COUNT ]; // array of sizes of components
    // component data for all components; components will be typecast
    void * component[ COMPONENT_COUNT ];
    unsigned int nextEntity; // the next entity to allocate
};
typedef struct World World;

// Returns a new, empty world.
World * newWorld ( void );
// Frees the world.
void freeWorld ( World * world );
// Shift entities such that they fill contiguous space.
void shrinkWorld ( World * world );
// Increase ENTITY_COUNT, increasing the maximum number of entities.
void growWorld ( World * world );

#endif
