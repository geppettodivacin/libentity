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

typedef Mask Aspect;

bool validInSystem ( const Aspect aspect, Entity e, World * world );
void setInAspect ( Aspect aspect, Component c );
void removeFromAspect ( Aspect aspect, Component c );
void clearAspect ( Aspect aspect );
bool aspectIsEmpty ( Aspect aspect );

#endif
