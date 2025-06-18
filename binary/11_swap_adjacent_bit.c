/*


Swap adjacent bits of a number

Given an integer, swap adjacent bits of it. In other words, 
swap bits present at even positions with those present in odd positions.

For example,
Input:  761622921 (00101101011001010111000110001001)
 Output: 513454662 (00011110100110101011001001000110)  
 Explanation: (Every pair of adjacent bits swapped)   
 00 10 11 01 01 10 01 01 01 11 00 01 10 00 10 01 
 00 01 11 10 10 01 10 10 10 11 00 10 01 00 01 10 

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
    for(int i = 31;i>=0;i--){
        printf("%d",val&(1<<i)?1:0);
    }
    printf("\n");
}

int swap_adj_bit(int val)
{
    int maskh = 0xaaaaaaaa;
    int maskl = 0x55555555;
    int ans = ((maskh&val)>>1)|((maskl&val)<<1);
    return ans;
}



int main(int argc, char** argv)
{
    int n = 761622921;
    printf("%d:\n",n);
    printbits(n);
    int ans = swap_adj_bit(n);
    printf("%d\n",ans);
    printbits(ans);
    return 0;
}
