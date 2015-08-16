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

void printMask ( const Mask m )
{
    int i = 0;
    for ( i = 0; i < MASK_LENGTH; ++i )
    {
        printf ( "%#04X%s", m[ i ], ( i < MASK_LENGTH - 1 ) ? " " : ""  );
    }
    printf ( "\n" );
}

void maskCopy ( Mask dest, const Mask src )
{
    int i = 0;
    for ( i = 0; i < MASK_LENGTH; ++i )
    {
        dest[ i ] = src[ i ];
    }
}

void maskNot ( Mask dest, const Mask src )
{
    int i = 0;
    for ( i = 0; i < MASK_LENGTH; ++i )
    {
        dest[ i ] = ~src[ i ];
    }
}

bool maskEqual ( const Mask m, const Mask n )
{
    int i = 0;

    for ( i = 0; i < MASK_LENGTH; ++i )
    {
        if ( ( m[ i ] & n[ i ] ) != m[ i ] || ( m[ i ] & n[ i ] ) != n[ i ] )
            return false;
    }

    return true;
}

bool maskSubset ( const Mask m, const Mask n )
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

void maskAnd ( Mask result, const Mask m, const Mask n )
{
    int i = 0;
    for ( i = 0; i < MASK_LENGTH; ++i )
    {
        result[ i ] = m[ i ] & n[ i ];
    }
}

void maskNand ( Mask result, const Mask m, const Mask n )
{
    int i = 0;
    for ( i = 0; i < MASK_LENGTH; ++i )
    {
        result[ i ] = m[ i ] & ~n[ i ];
    }
}

void maskOr ( Mask result, const Mask m, const Mask n )
{
    int i = 0;
    for ( i = 0; i < MASK_LENGTH; ++i )
    {
        result[ i ] = m[ i ] | n[ i ];
    }
}

void maskOrN ( Mask result, int maskCount, ... )
{
    int i;

    if ( maskCount < 1 )
    {
        for ( i = 0; i < MASK_LENGTH; ++i )
        {
            result[ i ] = 0;
        }

        return;
    }

    va_list maskList;
    va_start ( maskList, maskCount );

    int * mask = va_arg ( maskList, int * );

    maskCopy ( result, mask );

    for ( i = 1; i < maskCount; ++i )
    {
        mask = va_arg ( maskList, int * );
        maskOr ( result, result, mask );
    }

    va_end ( maskList );
}
