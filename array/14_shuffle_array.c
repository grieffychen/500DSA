/*


Shuffle an array using Fisher–Yates shuffle algorithm

Given an integer array, in-place shuffle it. 
The algorithm should produce an unbiased permutation, i.e., every permutation is equally likely.


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
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void shuffle(int *array, int len)
{
    for(int i =0;i<len;i++){
        int r = rand();
        int j = r%(i+1);

        //printf("%d ,%d %d\n",r,i,j);
        swap(&array[i],&array[j]);
    }
}



int main(int argc, char** argv)
{
    int arr[] = { 1, 2, 3, 4, 5, 6 };
    int len = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0;i<len;i++)
        printf("%d ",arr[i]);
    printf("\n");

    shuffle(arr,len);
    for(int i = 0;i<len;i++)
        printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
