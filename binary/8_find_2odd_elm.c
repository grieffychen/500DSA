/*


Find two odd occurring elements in an array without using any extra space

Given an integer array, duplicates appear in it an even number of times except for two elements, 
which appear an odd number of times. 
Find both odd appearing elements without using any extra memory.

For example,
Input:  arr[] = [4, 3, 6, 2, 4, 2, 3, 4, 3, 3]
 Output: The odd occurring elements are 4 and 6   
 6 appears once. 
 2 appears twice. 
 4 appears thrice. 
 3 appears 4 times. 



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


int *find_t_odd_elm(int * arr,int len)
{
    int *ansarr = (int*) malloc(sizeof(int)*2);
    int xorval = 0;
    for(int i =0;i<len;i++){
        xorval =xorval^arr[i];
    }
    printf("xorval=%d\n",xorval);
    int bitflag = xorval&(-(unsigned int)xorval);
    printf("bit flag =%d\n",bitflag);
    for(int i =0;i<len;i++){
        if(arr[i]&bitflag){
            ansarr[0] = ansarr[0]^arr[0];
        }
    }
    ansarr[1] = xorval^ansarr[0];
    return ansarr;
}

int main(int argc, char** argv)
{
    int  arr[] = { 4, 3, 6, 2, 4, 2, 3, 4, 3, 3 };
    int len = sizeof(arr)/sizeof(arr[0]);

    int *ansarr=find_t_odd_elm(arr,len);

    if(ansarr){
        printf("%d %d\n",ansarr[0],ansarr[1]);
        free(ansarr);
    }

    return 0;
}
