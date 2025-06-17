/*


Swap two bits at a given position in an integer

Given an integer, swap two bits at given positions in a binary representation of it.

For example,
Input:
  n = 31 (31 in binary is 00011111) p = 2, q = 6 (3rd and 7th bit from the right)  
  Output: 91  
  Explanation: 91 in binary is 01011011 

We can solve this problem by checking if the two bits at given positions are the same or not. 
If they are the same, nothing needs to be done; otherwise, 
if they are not the same (i.e., one is 0 and the other is 1), 
then we can XOR them with 1 << position. This logic will work because:
XOR with 1 will toggle the bits
0 ^ 1 = 1 
1 ^ 1 = 0   
XOR with 0 will have no impact 
0 ^ 0 = 0 
1 ^ 0 = 1 

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

int swap_bit(int val,int pos1,int pos2)
{
    if( ((val&(1<<pos1))>>pos1)^( (val&(1<<pos2))>>pos2) ){
        val = val^(1<<pos1);
        val = val^(1<<pos2);
    }

    return val;
}


int main(int argc, char** argv)
{
    int n = 31;
    int p = 2, q = 6;    // swap 3rd and 7th bit from the right

    printf("%d==> %d\n",n,swap_bit(n,p,q));
    return 0;
}
