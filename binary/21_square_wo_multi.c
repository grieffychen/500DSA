/*



Find the square of a number without using the multiplication and division operator

Given an integer, find its square without using multiplication and division operator. 
Also, the use of the power function from any programming language library is not allowed.

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

/*
Method 1:

The idea is based on the fact that the square root of any number n can be calculated by adding odd numbers exactly n times. 
The relation can be expressed as:
12 = 1
22 = (1 + 3) = 4 
32 = (1 + 3 + 5 = 9) 
42 = (1 + 3 + 5 + 7) = 16 
*/

int findsquare_method1(int val)
{
    int odd = 1;
    int sq = 0;
    while(val){
        sq+=odd;
        odd+=2;
        val--;
    }
    return sq;
}

/*
Method 2: Repeatedly adding a given number to the result

The idea is to repeatedly add a given number n to the result n times. 
For example,
For n = 5, 52 = (5 + 5 + 5 + 5 + 5) = 25 
*/


int findsquare_method2(int val)
{
    int sq = 0;
    for(int i = 0;i<val;i++){
        sq+=val;
    }
    return sq;
}

/*
Method 3: Using Divide and Conquer with bitwise operators

If n is even, the square of n can be expressed as n2 = ((n/2) × 2)2 = (n/2)2 × 4.

If n is odd, the square of n can be expressed as n2 = ((n - 1) + 1)2 = (n - 1)2 + 1 + 2 × (n - 1) × 1 = ((n/2)2 × 4) + 1 + (n/2) × 4.

*/
int findsquare_method3(int val)
{
    if(val<2)
        return val;
    val =abs(val);

    int i = val>>1;
    if(val&1){
        return ((findsquare_method3(i)<<2)+(i<<2)+1);
        //return ((findsquare_method3(i) << 2) + (i << 2) + 1);

    }else{
        return findsquare_method3(i)<<2;
    }
}

int main(int argc, char** argv)
{
    int value = 8;
    printf("%d square method 1 =%d \n",value,findsquare_method1(value));
    printf("%d square method 2 =%d \n",value,findsquare_method2(value));
    printf("%d square method 3 =%d \n",value,findsquare_method3(value));


    return 0;
}
