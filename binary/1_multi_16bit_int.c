/*

Given two 16–bit positive values stored in 32–bit integer variables, 
find the product using the 8–bit multiply operator that takes two 8–bit numbers and returns a 16–bit value.

The idea is to divide the given 16–bit numbers (say m and n) into 8–bit numbers first (say mLow, mHigh and nLow, nHigh). 
Now the problem is reduced to something similar to the multiplication of a 2–digit number with another 2–digit number. For example, 
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


unsigned int multi_8bits(unsigned char m,unsigned char n)
{
    return m*n;
}

int mutli_16bits(int m,int n)
{
    int result = 0;
    unsigned char highm = (m&0xff00)>>8;
    unsigned char lowm = (m&0x00ff);
    unsigned char highn = (n&0xff00)>>8;
    unsigned char lown = (n&0x00ff);

    printf("%d %d %d %d\n",highm,lowm,highn,lown);

    result = (multi_8bits(highm,highn)<<16)+(multi_8bits(highm,lown)<<8)+(multi_8bits(lowm,highn)<<8)+multi_8bits(lowm,lown);    
    
    printf("%d %d %d %d\n",multi_8bits(highm,highn),multi_8bits(highm,lown),multi_8bits(lowm,highn),multi_8bits(lowm,lown));
    printf("%d %d %d %d\n",multi_8bits(highm,highn)<<16,multi_8bits(highm,lown)<<8,multi_8bits(lowm,highn)<<8,multi_8bits(lowm,lown));
    
    //printf("%d\n",result);
    return result;
}


int main(int argc, char** argv)
{
    int m = 23472, n = 2600;
    int ans = mutli_16bits(m,n);
    printf("%d x %d =%d\n",m,n,ans);
    return 0;
}
