// =============================================================================
// 
//       Filename:  main.c
// 
//    Description:  The main test file.
// 
//        Version:  1.0
//        Created:  08/11/2015 10:38:30 PM
//       Revision:  none
//       Compiler:  gcc
// 
//         Author:  Eric Dilmore (), ericdilmore@gmail.com
//        Company:  
// 
// =============================================================================

#include <stdio.h>
#include <stdlib.h>

typedef short bool;
#define false   0
#define true    1

#define MASKLEN    10
typedef int Mask[ MASKLEN ];

typedef int Entity;

void printMask ( Mask m );
bool maskEqual ( Mask m, Mask n );
bool maskSubset ( Mask m, Mask n );

int main ( int argc, char *argv[] )
{
    Mask x = {0xFF, 0xA1, 0x01};
    Mask y = {0xFF, 0xA1, 0x03};
    printf ( "%hd\n", maskSubset ( y, x ) );
    return EXIT_SUCCESS;
}

void printMask ( Mask m )
{
    int i = 0;
    for ( i = 0; i < MASKLEN; ++i )
    {
        printf ( "%#04X%s", m[ i ], ( i < MASKLEN - 1 ) ? " " : ""  );
    }
    printf ( "\n" );
}

bool maskEqual ( Mask m, Mask n )
{
    int i = 0;

    for ( i = 0; i < MASKLEN; ++i )
    {
        if ( ( m[ i ] & n[ i ] ) != m[ i ] || ( m[ i ] & n[ i ] ) != n[ i ] )
            return false;
    }

    return true;
}

bool maskSubset ( Mask m, Mask n )
{
    int i = 0;

    for ( i = 0; i < MASKLEN; ++i )
    {
        if ( ( m[ i ] & n[ i ] ) != m[ i ] )
        {
            return false;
        }
    }

    return true;
}
