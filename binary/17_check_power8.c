/*


Check if a number is a power of 8 or not

Given a positive number, check if it is a power of 8 or not.


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

bool is_power_of8(unsigned int val)
{
    unsigned int mask = 0;
    int pos =3;
    while(pos <32){
        mask |=1<<pos;
        pos+=3;
    }
    printf("0x%x\n",mask);
    return (!(val&(val-1)) && (val&mask)) ;
}


int main(int argc, char** argv)
{
    int n = 64*8;
    printf("%d %s power of 8\n",n,is_power_of8(n)?"is":"is not");

    return 0;
}
