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

#include "util.h"
#include "mask.h"

void printMask ( Mask m )
{
    int i = 0;
    for ( i = 0; i < MASK_LENGTH; ++i )
    {
        printf ( "%#04X%s", m[ i ], ( i < MASK_LENGTH - 1 ) ? " " : ""  );
    }
    printf ( "\n" );
}

bool maskEqual ( Mask m, Mask n )
{
    int i = 0;

    for ( i = 0; i < MASK_LENGTH; ++i )
    {
        if ( ( m[ i ] & n[ i ] ) != m[ i ] || ( m[ i ] & n[ i ] ) != n[ i ] )
            return false;
    }

    return true;
}

bool maskSubset ( Mask m, Mask n )
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

void maskCombine ( Mask * result, Mask m, Mask n )
{
    int i = 0;
    for ( i = 0; i < MASK_LENGTH; ++i )
    {
        printf ( "%#08X | %#08X = %#08X\n", m[ i ], n[ i ], m[ i ] | n[ i ] );
        *result[ i ] = m[ i ] | n[ i ];
        printf ( "result[ %d ] = %#08X\n", i, *result[ i ] );
    }

    printMask ( *result );
}