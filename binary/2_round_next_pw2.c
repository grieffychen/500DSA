/*


Round up to the next highest power of 2

Given a positive number n, find the next highest power of 2. If n itself is a power of 2, return n.

For example,
Input:  n = 20
Output: 32  
Input:  n = 16
Output: 16 
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
The idea is to unset the rightmost bit of n until only one bit is left, which will be the last set bit of the given number. 
To handle the case when n is the power of 2, initially decrement n by 1. 
Note that this operation will not impact output as we are only concerned about the last set bit of n.

*/

int find_next_power_of2_1(int val)
{
    val = val-1;
    while(val&(val-1)){
        val=val-1;
    }
    return (val<<1);
}

/*
The idea is to decrement n by 1 (to handle the case when n itself is the power of 2) and run a loop by initializing the result by 2. 
We double the result value at each iteration of the loop and divide n in half and continue the loop till n becomes 0.
*/

int find_next_power_of2_2(int val)
{
    val = val-1;
    int k = 1;
    while(val>>=1){
        //val=val>>1;
        k=k<<1;
    }
    return (k<<1);
}
 

int main(int argc, char** argv)
{
    //int n = 20;
    //int n = 16;
    int n = 127;
    int ans = find_next_power_of2_1(n);
    printf("n = %d , ans=%d\n",n,ans);
    ans = find_next_power_of2_2(n);
    printf("n = %d , ans=%d\n",n,ans);
    return 0;
}
