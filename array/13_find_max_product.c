/*



Find the maximum product of two integers in an array

Given an integer array, find the maximum product of two integers in it.

For example, consider array {-10, -3, 5, 6, -2}. The maximum product is the (-10, -3) or (5, 6) pair.


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


void find_max_product_brute_force(int *nums,int len)
{
    int max = 0;
    int max_idx1 = 0;
    int max_idx2 = 0;
    for(int i =0;i<len-1;i++){
        for(int j =i+1;j<len;j++){
            int pro = nums[i]*nums[j];
            if(pro>max){
                max = pro;
                max_idx1 = i;
                max_idx2 = j;
            }
        }
    }
    printf("max =%d , (%d %d)\n",max,nums[max_idx1],nums[max_idx2]);
}

void fin_dmax_product(int *nums,int len)
{
    int max1 = nums[0];
    int max2 = INT_MIN;
    int min1 = nums[0];
    int min2 = INT_MAX;

    for(int i = 1;i<len;i++){
        
        if(nums[i]>max1){
            max2 = max1;
            max1 = nums[i];
        }else if(nums[i]>max2){
            max2 = nums[i];
        }

        if(nums[i]<min1){
            min2 = min1;
            min1 = nums[i];
        }else if (nums[i] < min2){
            min2 = nums[i];
        }
    }
    if(max1*max2>min1*min2){
        printf("%d (%d %d)\n",max1*max2,max1,max2);
    }else{
        printf("%d (%d %d)\n",min1*min2,min1,min2);
    }
} 


int main(int argc, char** argv)
{
    int arr[] = { -10, -3, 5, 6, -2 };
    int len = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0;i<len;i++)
        printf("%d ",arr[i]);
    printf("\n");
    find_max_product_brute_force(arr,len);
    fin_dmax_product(arr,len);

    return 0;
}
