/*



Reverse bits of an integer

Given an integer, reverse its bits using binary operators.

For example, -100 in binary is 11111111111111111111111110011100. 
On reversing its bits, we get number 973078527 which is 00111001111111111111111111111111 in binary.


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


//  
//  brute force
int rev_bits1(int val)
{
    int bitlen = sizeof(int)*8-1;
    int revval = 0;

    while(val&&bitlen>=0){
    //while(val){        
        if(val&1){
            revval =revval|(1<<bitlen);
        }
        bitlen--;
        val=val>>1;
        printf("%d\n",val);
    }

    return revval;
}


int main(int argc, char** argv)
{
    int val = -100;
    int ans = rev_bits1(val);
    printf("%d ==>%d\n",val,ans);

    return 0;
}
