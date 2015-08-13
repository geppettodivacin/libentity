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

#include "util.h"
#include "mask.h"
#include "entity.h"
#include "component.h"

int main ( int argc, char *argv[] )
{
    Mask x = {0xFF, 0xA1, 0x01};
    Mask y = {0xFF, 0xA1, 0x03};
    printf ( "%hd\n", maskSubset ( y, x ) );
    return EXIT_SUCCESS;
}
