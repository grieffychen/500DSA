/*

Find all odd occurring elements in an array having a limited range of elements

Given an array having elements between 0 and 31, find elements that occur an odd number of times without using the extra space.

For example,
Input: nums[] = [5, 8, 2, 5, 8, 2, 8, 5, 1, 8, 2]
 Output: The odd occurring elements are 5, 2, and 1  
 Explanation:   1 occurs once. 2 and 5 occurs thrice. 8 occurs four times. 

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

void find_odd_occurs(int *nums,int nfnums)
{
    int bitmap = 0;
    for(int i = 0;i<nfnums;i++){
        bitmap ^= (1<<nums[i]);
    }

    for(int i = 0;i<32;i++){
        if(bitmap & (1<<i)){
            printf(" %d",i);
        }
    }
    printf("\n");

}

int main(int argc, char** argv)
{
    int nums[] = { 5, 8, 2, 5, 8, 2, 8, 5, 1, 8, 2 };
    int len = sizeof(nums)/sizeof(nums[0]);
    for(int i = 0;i<len;i++)
        printf("%d ",nums[i]);
    printf("\n");

    find_odd_occurs(nums,len);

    return 0;
}
