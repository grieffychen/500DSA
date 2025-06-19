/*


Find the missing number and duplicate elements in an array

Given an integer array of size n, with all its elements between 1 and n and one element occurring twice and one element missing. 
Find the missing number and the duplicate element in linear time and without using any extra memory.

For example,
Input:  arr[] = [4, 3, 6, 5, 2, 4]
 Output: The duplicate and missing elements are 4 and 1, respectively 

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

int *find_miss_duplicate_map(int *nums,int len)
{
    int *map =(int*) calloc(len+1,sizeof(int));
    int *ans = (int*) calloc(2,sizeof(int));
    for(int i = 0;i<len;i++)
        map[nums[i]]+=1;

    int idx = 0;
    for(int i =1;i<=len;i++){
        if(map[i]!=1)
            ans[idx++] = i;
    }

    if(map)
        free(map);

    return ans;
}

int *find_miss_duplicate_binary(int *nums,int len)
{
    int *ans = (int*) calloc(2,sizeof(int));
    int xorval = 0;
    for(int i = 1;i<=len;i++){
        xorval = xorval^nums[i-1]^i;
    }
    int bitflag = xorval^(-xorval);

    for(int i =1;i<=len;i++){
        if(nums[i-1]&bitflag){
            ans[0]^=nums[i-1];
        }
        if(i&bitflag)
            ans[0]^=i;
    }
    ans[1] = xorval^ans[0];

    return ans;
}


int main(int argc, char** argv)
{
    int arr[] = { 4, 3, 6, 5, 2, 4 };
    int len = sizeof(arr)/sizeof(arr[0]);
    for(int i =0; i<len;i++)
        printf("%d ",arr[i]);
    printf("\n");

    int *ansmap = find_miss_duplicate_map(arr,len);
    if(ansmap){
        printf("%d %d\n",ansmap[0],ansmap[1]);
        free(ansmap);
    }

    int *ansbin = find_miss_duplicate_binary(arr,len);
    if(ansbin){
        printf("%d %d\n",ansbin[0],ansbin[1]);
        free(ansbin);
    }
    return 0;
}
