/*
 * =============================================================================
 *
 *       Filename:  system.h
 *
 *    Description:  Header for system functions and macros.
 *
 *        Version:  1.0
 *        Created:  08/14/2015 09:58:59 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Eric Dilmore (), ericdilmore@gmail.com
 *   Organization:  
 *
 * =============================================================================
 */

#ifndef SYSTEM_H
#define SYSTEM_H

#include "mask.h"
#include "component.h"
#include "util.h"

// Aspects are simply Masks that define Components that a System will look at.
typedef Mask Aspect;

// Query whether an Entity meets the Aspect requirements of a System.
bool validInSystem ( const Aspect aspect, Entity e, World * world );
// Set a Component into an Aspect.
void setInAspect ( Aspect aspect, Component c );
// Remove a Component from an Aspect.
void removeFromAspect ( Aspect aspect, Component c );
// Clear an Aspect of all Components.
void clearAspect ( Aspect aspect );
// Query whether an Aspect is empty.
bool aspectIsEmpty ( Aspect aspect );

#endif
