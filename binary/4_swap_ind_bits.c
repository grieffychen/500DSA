/*


Swap individual bits at a given position in an integer

Given an integer, swap consecutive b bits starting from the given positions in a binary representation of an integer. 
The bits to be swapped should not overlap with each other.

For example,
Input:
  n = 15 (15 in binary is 00001111) 
  p = 2, q = 5 (3rd and 6th bit from the right) 
  b = 2 (Total number of consecutive bits in each sequence)  
  Output: 99   (99 in binary is 01100011) 

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

int swap(int val , int pos1,int pos2,int seq)
{
    int x = (val>>pos1)^(val>>pos2);
    x = x&((1<<seq)-1);


    return ((x<<pos1)|(x<<pos2))^val;
    //return 0;
}

int main(int argc, char** argv)
{
    int n = 15;
    int p = 2, q = 5;   // 3rd and 6th bit from the right
    int b = 2;          // total number of consecutive bits in each sequence

    int ans = swap(n,p,q,b);
    printf("%d==>%d\n",n,ans);

    return 0;
}
