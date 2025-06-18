/*



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
    return NULL;
}

int main(int argc, char** argv)
{
    int arr[] = { 4, 3, 6, 5, 2, 4 };
    int len = sizeof(arr)/sizeof(arr[0]);
    for(int i =0; i<len;i++)
        printf("%d ",arr[i]);
    printf("\n");

    int *ansmap = find_miss_duplicate_map(arr,len);

    return 0;
}
