/*
 * =============================================================================
 *
 *       Filename:  mask.h
 *
 *    Description:  Code for masks.
 *
 *        Version:  1.0
 *        Created:  08/12/2015 08:48:33 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Eric Dilmore (), ericdilmore@gmail.com
 *   Organization:  
 *
 * =============================================================================
 */

#ifndef MASK_H
#define MASK_H

#include "util.h"

#define MASK_LENGTH 10 // how many ints long a single mask is
typedef int Mask[ MASK_LENGTH ];

// Function to print the Mask as a series of hex numerals.
void printMask ( const Mask m );
// Copy a Mask.
void maskCopy ( Mask dest, const Mask src );
// Get the binary complement of the source Mask.
void maskNot ( Mask dest, const Mask src );
// Test if two Masks are equal.
bool maskEqual ( const Mask m, const Mask n );
// Test whether the set bits of Mask m is a subset of Mask n.
bool maskSubset ( const Mask m, const Mask n );
// Perform a binary and operation on two Masks.
void maskAnd ( Mask result, const Mask m, const Mask n );
// Perform a binary nand operation on two Masks.
void maskNand ( Mask result, const Mask m, const Mask n );
// Perform a binary or operation on two Masks.
void maskOr ( Mask result, const Mask m, const Mask n );
// Perform a binary or operation on maskCount Masks.
void maskOrN ( Mask result, int maskCount, ... );

#endif
