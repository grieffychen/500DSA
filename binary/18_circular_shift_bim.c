/*


Circular shift on the binary representation of an integer by `k` positions

Given two positive integers n and k, perform a circular shift on the binary representation of n by k positions.

The circular shift can be of two types:

    Left circular shift (moving the final bit to the first position while shifting all other bits to the next position).
    Right circular shift (moving the first bit to the last position while shifting all other bits to the previous position).

 

For example,
Input:
  N = 127        (00000000000000000000000001111111) shift = 3  
  Output:   Left Shift     00000000000000000000001111111000 
            Right Shift    11100000000000000000000000001111 


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

void printbits(unsigned int val)
{
    for(int i = 31;i>=0;i--){
        printf("%d",(val&1<<i)?1:0);
    }
    printf("\n");
}

unsigned int leftshift(unsigned int val , int k)
{
    unsigned int bitmask = 0;
    int p = 0;
    unsigned int sval = 0;
    while(p<k){
        int bit = val&(1<<31-p)?1:0;
        sval<<=1;
        sval|=bit;
        p++;
    }
    //printbits(sval);

    return (val<<k)|sval;

}

unsigned int rightshift(unsigned int val , int k)
{
    unsigned int bitmask  = 0;
    int p = 0;
    unsigned int sval = 0;
    while(p<k){
        int bit = val&(1<<p)?1:0;
        //printf("%d\n",bit);
        sval>>=1;
        sval|=(bit<<31);
        //printbits(sval);
        p++;
    }
    //printbits(sval);
    return (val>>k)|sval;
}

unsigned int rcshift(unsigned int val , int k)
{
    return (val>>k) |(val<<(32-k));
    //return (val<<k) | (val>>(32-k));
}

unsigned int lcshift(unsigned int val , int k)
{    
    return (val<<k) | (val>>(32-k));
    //return (val>>k) |(val<<(32-k));
}


int main(int argc, char** argv)
{
    int val =127;
    int k = 3;
    printbits(val);
    int lv = leftshift(val,k);
    printbits(lv);
    int rv = rightshift(val,k);
    printbits(rv);

    int lv2 = lcshift(val,k);
    printbits(lv2);
    int rv2 = rcshift(val,k);
    printbits(rv2);

    return 0;
}
