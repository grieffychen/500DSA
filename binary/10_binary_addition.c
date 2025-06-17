/*


Add binary representation of two integers

Given two integers, add their binary representation.

For example,
Input:
  x = 12731 (which is 00000000000000000011000110111011 in binary) 
  y = 38023 (which is 00000000000000001001010010000111 in binary)  
              Output: 00000000000000001100011001000010    
  
  Input:   x = 1023 (which is 00000000000000000000001111111111 in binary) 
           y = 1023 (which is 00000000000000000000001111111111 in binary)  
                      Output: 00000000000000000000011111111110 


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

int binary_add(int x,int y)
{
    int carry = 0;
    int bitsum = 0;
    int ans = 0;
    int bitidx = 0;
    while(x||y||carry){
        int bitx = x&1;
        int bity = y&1;
        bitsum = bitx^bity^carry;
        if( (bitx&&bity&&carry) || (bitx&&bity&&(!carry)) || ((!bitx)&&bity&&carry) ||(bitx&&(!bity)&&carry))
            carry = 1;
        else
            carry = 0;
        ans = ans | (bitsum<<bitidx);
        bitidx++;
        x>>=1;
        y>>=1;
    }

    return ans;
}


int main(int argc, char** argv)
{
    int x = 12731;
    int y = 38023;
    printf("x:%d\n",x);
    printbits(x);
    printf("y:%d\n",y);
    printbits(y);
    int ans = binary_add(x,y);
    printf("ans:%d\n",ans);
    printbits(ans);    
    return 0;
}
