/*

Solve a given set of problems without using multiplication or division operators



*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>			// File Control Definitions.
#include <termios.h>		// POSIX Terminal Control Definitions.
#include <unistd.h>			// UNIX Standard Definitions.
#include <errno.h>			// ERROR Number Definitions.
#include <pthread.h>
#include <sys/select.h>
#include <sys/time.h>
#include <signal.h>
#include <time.h>
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Problem 1. Multiply a given integer with 15 without using multiplication and division operators.
*/

int multi_15(int val)
{
    return ((val<<4)-val);
}

/*
Problem 2. Multiply a given even integer with 7.5 without using multiplication and division operators.
*/

int multi_7p5(int val)
{
    return (val<<3)-(val>>1);
}

int main(int argc, char** argv)
{
    printf("%d x15 =%d\n",6,multi_15(6));
    printf("%d x15 =%d\n",6,multi_7p5(6));

    return 0;
}
