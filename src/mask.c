/*
 * =============================================================================
 *
 *       Filename:  mask.cpp
 *
 *    Description:  Implementation for Mask functions.
 *
 *        Version:  1.0
 *        Created:  08/12/2015 08:50:53 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Eric Dilmore (), ericdilmore@gmail.com
 *   Organization:  
 *
 * =============================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#include "mask.h"
#include "util.h"

// Function to print the Mask as a series of hex numerals.
void printMask ( const Mask m )
{
    int i = 0;
    for ( i = 0; i < MASK_LENGTH; ++i )
    {
        printf ( "%#04X%s", m[ i ], ( i < MASK_LENGTH - 1 ) ? " " : ""  );
    }
    printf ( "\n" );
}

// Copy a Mask.
void maskCopy ( Mask dest, const Mask src )
{
    int i = 0;
    for ( i = 0; i < MASK_LENGTH; ++i )
    {
        dest[ i ] = src[ i ];
    }
}

// Get the binary complement of the source Mask.
void maskNot ( Mask dest, const Mask src )
{
    int i = 0;
    for ( i = 0; i < MASK_LENGTH; ++i )
    {
        dest[ i ] = ~src[ i ];
    }
}

// Test if two Masks are equal.
boolean maskEqual ( const Mask m, const Mask n )
{
    int i = 0;

    for ( i = 0; i < MASK_LENGTH; ++i )
    {
        if ( m[ i ] != n[ i ] )
            return false;
    }

    return true;
}

// Test whether the set bits of Mask m is a subset of Mask n.
boolean maskSubset ( const Mask m, const Mask n )
{
    int i = 0;

    for ( i = 0; i < MASK_LENGTH; ++i )
    {
        if ( ( m[ i ] & n[ i ] ) != m[ i ] )
        {
            return false;
        }
    }

    return true;
}

// Perform a binary and operation on two Masks.
void maskAnd ( Mask result, const Mask m, const Mask n )
{
    int i = 0;
    for ( i = 0; i < MASK_LENGTH; ++i )
    {
        result[ i ] = m[ i ] & n[ i ];
    }
}

// Perform a binary nand operation on two Masks.
void maskNand ( Mask result, const Mask m, const Mask n )
{
    int i = 0;
    for ( i = 0; i < MASK_LENGTH; ++i )
    {
        result[ i ] = m[ i ] & ~n[ i ];
    }
}

// Perform a binary or operation on two Masks.
void maskOr ( Mask result, const Mask m, const Mask n )
{
    int i = 0;
    for ( i = 0; i < MASK_LENGTH; ++i )
    {
        result[ i ] = m[ i ] | n[ i ];
    }
}

// Perform a binary or operation on maskCount Masks.
void maskOrN ( Mask result, int maskCount, ... )
{
    int i;

    // If there are no Masks to or...
    if ( maskCount < 1 )
    {
        // clear the mask.
        for ( i = 0; i < MASK_LENGTH; ++i )
        {
            result[ i ] = 0;
        }

        return;
    }

    va_list maskList;
    va_start ( maskList, maskCount );

    // Copy the first Mask over to result.
    int * mask = va_arg ( maskList, int * );
    maskCopy ( result, mask );

    // Or each subsequent Mask with the previous result.
    for ( i = 1; i < maskCount; ++i )
    {
        mask = va_arg ( maskList, int * );
        maskOr ( result, result, mask );
    }

    va_end ( maskList );
}
