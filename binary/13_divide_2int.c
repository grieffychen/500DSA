/*

Perform division of two numbers without using division operator

Write a program to perform a division of two numbers without using the division operator (‘/’).
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

int divide(int dividend, int divisor)
{
    if((dividend==INT_MIN) && (divisor == -1))
        return INT_MAX;
    if( (dividend==INT_MIN)&& (divisor == 1) )
        return INT_MIN;
    int sign = (dividend>=0)^(divisor>=0) ?-1:1;

    long long int dividendL = dividend >=0?dividend:-dividend;
    long long int divisorL = divisor>=0? divisor:-divisor;
    printf("sizeof of long long =%ld\n",sizeof(long long int));

    int quotient = 0;
    int sum = 0 ;

    for (int i = 31;i>=0;i--){
        if((sum+(divisorL<<i) <= dividendL)){
            sum+=(divisorL<<i);
            quotient +=(1<<i);
        }
    }
    //if(sign == -1)
    //    quotient = quotient*sign;
    if(sign*quotient> INT_MAX)
        return INT_MAX;

    return quotient*sign;
}

int main(int argc, char** argv)
{
    int dividend = 22;
    int divisor = -7;

    int ans = divide(dividend,divisor);
    printf("%d / %d=%d \n",dividend,divisor,ans);

    return 0;
}
