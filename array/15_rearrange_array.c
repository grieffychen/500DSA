/*


Rearrange an array with alternate high and low elements

Given an integer array, rearrange it such that every second element becomes greater than its left and right elements. 
Assume no duplicate elements are present in the array.

For example,
Input:  {1, 2, 3, 4, 5, 6, 7}
Output: {1, 3, 2, 5, 4, 7, 6}  

Input:  {9, 6, 8, 3, 7}
Output: {6, 9, 3, 8, 7}  

Input:  {6, 9, 2, 5, 1, 4}
Output: {6, 9, 2, 5, 1, 4} 

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


void swap(int *a,int *b)
{
    *a = (*a)^(*b);
    *b = (*a)^(*b);
    *a = (*a)^(*b);
}

void rearrange_array(int *nums,int len)
{
    for(int i =1;i<len;i+=2){
        if(nums[i-1]>nums[i]){
            swap(&nums[i-1],&nums[i]);
        }

        if((i<len-1)&&(nums[i+1]>nums[i])){
            swap(&nums[i+1],&nums[i]);
        }
    }
}


int main(int argc, char** argv)
{
    //int array[] = {1, 2, 3, 4, 5, 6, 7};
    //int array[] = {9, 6, 8, 3, 7};
    int array[] = {6, 9, 2, 5, 1, 4};
    int len = sizeof(array)/sizeof(array[0]);
    for(int i = 0;i<len;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    rearrange_array(array,len);

    for(int i = 0;i<len;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    return 0;
}
