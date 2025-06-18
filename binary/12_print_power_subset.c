/*



Generate the power set of a given set

Given a set S, generate all subsets of it, i.e., find the power set of set S. 
A power set of any set S is the set of all subsets of S, including the empty set and S itself.

For example, if S is the set {x, y, z}, then the subsets of S are:

    {} (also known as the empty set or the null set).
    {x}
    {y}
    {z}
    {x, y}
    {x, z}
    {y, z}
    {x, y, z}

Hence, the power set of S is {{}, {x}, {y}, {z}, {x, y}, {x, z}, {y, z}, {x, y, z}}.




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


void print_power_subset(int *nums, int len)
{
    int tottal = 1<<len;
    for(int i  = 0;i<tottal;i++){
        int m = i;
        int idx = 0;
        while(m&&(idx<len)){
            if(m&1)
                printf(" %d",nums[idx]);
            idx++;
            m>>=1;
        }
        printf("\n");
    }
}


int main(int argc, char** argv)
{
    int S[] = { 3, 2, 1 };
    int len = sizeof(S)/sizeof(S[0]);
    print_power_subset(S,len);

    return 0;
}
