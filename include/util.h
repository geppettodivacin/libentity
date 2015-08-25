/*
 * =============================================================================
 *
 *       Filename:  util.h
 *
 *    Description:  Simple utilities for use throughout program.
 *
 *        Version:  1.0
 *        Created:  08/12/2015 08:44:48 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Eric Dilmore (), ericdilmore@gmail.com
 *   Organization:  
 *
 * =============================================================================
 */

#ifndef UTIL_H
#define UTIL_H

// Define a boolean value, because C doesn't have that capability.
typedef short bool;
#define false   0
#define true    1

// Find the highest bit set in an int. Returns 0 if i is zero or one.
unsigned int highestSetBit ( int i );

#endif
