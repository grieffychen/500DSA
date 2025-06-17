/*



Round up to the previous power of 2

Given a positive number n, find the previous power of 2. If n itself is a power of 2, return n.

For example,
Input:  n = 20
Output: 16  
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

unsigned int find_pre_power_of2_1(unsigned int val)
{
    while(val&(val-1)){
        val=val-1;
    }
    return val;
}

int main(int argc, char** argv)
{
    //int n = 20;
    //int n = 16;
    int n = 127;
    int ans = find_pre_power_of2_1(n);
    printf("n = %d , ans=%d\n",n,ans);

    return 0;
}
