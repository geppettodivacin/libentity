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

#define MASK_LENGTH 10
typedef int Mask[ MASK_LENGTH ];

void printMask ( Mask m );
bool maskEqual ( Mask m, Mask n );
bool maskSubset ( Mask m, Mask n );
void maskCombineN ( Mask result, int maskCount, ... );
void maskCombine ( Mask result, Mask m, Mask n );

#endif
