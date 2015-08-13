/*
 * =============================================================================
 *
 *       Filename:  util.c
 *
 *    Description:  Implementations of utils.
 *
 *        Version:  1.0
 *        Created:  08/13/2015 12:45:21 PM
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

// As seen in reply to StackExchange comment http://stackoverflow.com/a/3065433.
unsigned int highestSetBit ( int n )
{
    int i = 0;
    while ( n >>= 1 ) ++i;
    return i;
}
