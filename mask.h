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

#define MASK_LENGTH 10
typedef int Mask[ MASK_LENGTH ];

void printMask ( const Mask m );
void maskCopy ( Mask dest, const Mask src );
bool maskEqual ( const Mask m, const Mask n );
bool maskSubset ( const Mask m, const Mask n );
void maskOr ( Mask result, const Mask m, const Mask n );
void maskOrN ( Mask result, int maskCount, ... );

#endif
