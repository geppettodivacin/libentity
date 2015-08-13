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

#include "mask.h"
#include "entity.h"

typedef const Mask Component;
extern Component COMPONENT_NONE;
extern Component COMPONENT_ONE;

void addComponent ( Entity e, Component c, World * world );
void removeComponent ( Entity e, Component c, World * world );

#endif
