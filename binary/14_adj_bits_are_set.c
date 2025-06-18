/*


Check if adjacent bits are set in the binary representation of a number

Given a number, check if adjacent bits are set in the binary representation of it.
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

void printbits(int val)
{
    for(int i =31;i>=0;i--){
        printf("%d",((val&(1<<i))!=0)?1:0);
        //printf("%d",(val&(1<<i))?1:0);
        //printf("%d %d %d\n",val,1<<i,);
    }
    printf("\n");
}

bool check_adj_bits(int val)
{
    return (val&(val>>1));
}


int main(int argc, char** argv)
{
    int n = 67;
    printbits(n);
    bool res = check_adj_bits(n);
    printf("adjacent bit %s \n",res?"is set":"is not set");

    return 0;
}
