/*


Efficiently implement power function – Iterative and Recursive

Given two integers, x and n, where n is non-negative, efficiently compute the power function pow(x, n).

For example,
pow(-2, 10) = 1024
pow(-3, 4) = 81 
pow(5, 0) = 1 
pow(-2, 3) = -8 

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

void printbits(int val){
    for(int i =31;i>=0;i--){
        printf("%d",val&(1<<i)?1:0);
    }
    printf("\n");

}

int pow_iter(int x,unsigned int pw)
{
    long pow = 1;
    for(int i = 0;i<pw;i++){
        pow = pow*x;
    }
    return pow;
}

int main(int argc, char** argv)
{
    //printbits(-2);
    //printbits(-2>>1);
    //printbits(-2>>2);
    int x = -2;
    int pow =10;
    printf(" -2 ^ 10 =%d\n",pow_iter(x,pow));


    return 0;
}
