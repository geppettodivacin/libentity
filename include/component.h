/*
 * =============================================================================
 *
 *       Filename:  component.h
 *
 *    Description:  Header for Component stuff.
 *
 *        Version:  1.0
 *        Created:  08/12/2015 10:08:41 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Eric Dilmore (), ericdilmore@gmail.com
 *   Organization:  
 *
 * =============================================================================
 */

#ifndef COMPONENT_H
#define COMPONENT_H

#include "world.h"
#include "mask.h"
#include "entity.h"

// Components are simply Masks that represent a component.
typedef const Mask Component;
// Component for a blank entity.
extern Component COMPONENT_NONE;

// Reduce a Component to an int between 0 and COMPONENT_COUNT. COMPONENT_NONE
// returns -1.
unsigned int componentNumber ( Component c );
// Add a Component to a World.
void registerComponent ( void (*defaultInit) ( void * ), Component c
                       , size_t cSize, World * world );
// Remove a Component from a World.
void deregisterComponent ( Component c, World * world );
// Allocate memory for the Components and initialize them with defaults.
void * initComponents ( size_t cSize, void (*defaultInit) ( void * ) );
// Add a Component to an Entity.
void addComponent ( Entity e, Component c, World * world );
// Remove a Component from an Entity.
void removeComponent ( Entity e, Component c, World * world );
// Query whether an Entity has a given Component.
bool hasComponent ( Entity e, Component c, World * world );
// Get a pointer to the Component for an Entity.
void * getComponent ( Entity e, Component c, World * world );

#endif
