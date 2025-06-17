/*


Find the odd occurring element in an array in a single traversal

Given an integer array, duplicates are present in it in a way that all duplicates appear an even number of times except one which appears an odd number of times. 
Find that odd appearing element in linear time and without using any extra memory.

For example,
Input:  arr[] = [4, 3, 6, 2, 6, 4, 2, 3, 4, 3, 3]
 Output: The odd occurring element is 4 


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


int find_odd_occur(int *arr, int len)
{
    int ret = 0;
    for(int i =0;i<len;i++){
        ret = ret^arr[i];
    }
    return ret;
}


int main(int argc, char** argv)
{
    int arr[] = { 4, 3, 6, 2, 6, 4, 2, 3, 4, 3, 3 };
    int len = sizeof(arr)/sizeof(arr[0]);

    int ans = find_odd_occur(arr,len);
    printf("%d\n",ans);

    return 0;
}
