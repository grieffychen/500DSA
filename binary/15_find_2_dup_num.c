/*


Find two duplicate elements in a limited range array (using XOR)

Given an integer array of size n+2 containing elements between 1 and n with two element repeating, 
find both duplicate elements without using any extra memory in linear time.

For example,
Input:  arr[] = [4, 3, 6, 5, 2, 4, 1, 1]
 Output: The duplicate elements are 1 and 4 
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

int *find_2_duplicate(int *nums,int len,int n)
{
    int *ans = (int*)malloc(sizeof(int)*2);
    int xorval = 0;
    xorval = nums[0]^nums[len-1];
    for(int i = 1;i<=n;i++)
        xorval=xorval^nums[i]^i;
    
    int bitflag = xorval&(-xorval);
    //printf("bitflag=%d\n",bitflag);
    for(int i = 0;i<len;i++){
        if(nums[i]&bitflag){
            ans[0]^=nums[i];
        }
    }
    for(int i = 1;i<=n;i++){
        if(i&bitflag)
            ans[0]^=i;
    }
    ans[1] = xorval^ans[0];
    return ans;
}


int main(int argc, char** argv)
{
    int arr[] = { 4, 3, 6, 5, 2, 4, 1, 1 };
    int num = 6;
    int len = sizeof(arr)/sizeof(arr[0]);

    int *ansarr = find_2_duplicate(arr,len,num);
    if(ansarr){
        printf("%d %d\n",*ansarr,*(ansarr+1));
        free(ansarr);
    }

    return 0;
}
