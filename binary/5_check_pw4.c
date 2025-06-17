/*


Check if a number is a power of 4 or not

Given a positive number, check if it is a power of four or not.


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


bool is_power_of4(unsigned int val)
{
    int mask = 0xaaaaaaaa;
    return (!(val&(val-1))) && (!(val&mask) );
}

int main(int argc, char** argv)
{
    //int n = 256;
    int n = 255;

    printf("%d %s power of 4\n",n,is_power_of4(n)?"is":"is not");

    return 0;
}
