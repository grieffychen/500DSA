/*


Find equilibrium index of an array

Given an integer array, find the equilibrium index in it.

For an array A consisting n elements, index i is an equilibrium index if the sum of elements of subarray A[0…i-1] is equal to the sum of elements of subarray A[i+1…n-1]. i.e.

(A[0] + A[1] + … + A[i-1]) = (A[i+1] + A[i+2] + … + A[n-1]), where 0 < i < n-1

Similarly, 0 is an equilibrium index if A[1] + A[2] + … + A[n-1] sums to 0 and n-1 is an equilibrium index if A[0] + A[1] + … + A[n-2] sums to 0.

 
To illustrate, consider the array {0, -3, 5, -4, -2, 3, 1, 0}. 
The equilibrium index is found at index 0, 3, and 7.

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

void find_equlibrium_index(int *array,int len)
{
    int *leftdp = (int*)calloc(len,sizeof(int));
    for(int i = 1;i<len;i++){
        leftdp[i] = leftdp[i-1] + array[i-1];
    }

    int rsum = 0;
    for(int i = len-1;i>=0;i--){
        if(rsum == leftdp[i]){
            printf("index = %d\n",i);
        }
        rsum+=array[i];
    }

}

int main(int argc, char** argv)
{
    int arr[] = { 0, -3, 5, -4, -2, 3, 1, 0 };
    int len = sizeof(arr)/sizeof(arr[0]);
    for(int i =0;i<len;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    find_equlibrium_index(arr,len);

    return 0;
}
