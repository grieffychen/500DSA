/*


Find a pair with the given sum in an array

Given an unsorted integer array, find a pair with the given sum in it.

For example,
Input:
  nums = [8, 7, 2, 5, 3, 1] target = 10  Output:   Pair found (8, 2) or Pair found (7, 3)    
Input:   
  nums = [5, 2, 6, 8, 1, 9] target = 12  Output: Pair not found 

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

int **findpair_brute_force(int *nums,int len,int target,int *retlen)
{
    int **ans = (int**) malloc(sizeof(int*)*(len/2+1));
    for(int i = 0;i<(len/2+1);i++)
        ans[i] = (int*) malloc(sizeof(int)*2);
    int cnt = 0;
    //printf("%d\n",len);
    for(int i =0;i<len-1;i++){
        for(int j = i+1;j<len;j++){
            //printf("%d %d\n",i,j);
            if(nums[i]+nums[j] == target){
                ans[cnt][0] = nums[i];
                ans[cnt][1] = nums[j];
                cnt++;
                //printf("cnt=%d\n",cnt);
            }
            //printf("%d %d\n",i,j);
        }
    }
    //printf("2\n");
    *retlen = cnt;
    return ans;
}

int **findpair_map(int *nums,int len,int target , int *retlen)
{
    int **ans = (int**) malloc(sizeof(int*)*(len/2+1));
    int cnt = 0;
    for(int i = 0;i<(len/2+1);i++)
        ans[i] = (int*) malloc(sizeof(int)*2);
    int *map = (int*) calloc(101,sizeof(int));
    for(int i = 0;i<len;i++)
        map[nums[i]]+=1;

    for(int i = 0;i<len;i++){
        if(map[target-nums[i]] >0){
            ans[cnt][0] = nums[i];
            ans[cnt][1] = target-nums[i];
            map[nums[i]]-=1;
            map[target-nums[i]]-=1;
            cnt++;
        }
    }
    if(map)
        free(map);
    
    return ans;
}


int main(int argc, char** argv)
{
    int nums[] = { 8, 7, 2, 5, 3, 1 };
    int len = sizeof(nums)/sizeof(nums[0]);
    int target = 10;
    int retlen = 0;

    int **arrans = findpair_brute_force(nums,len,target,&retlen);
    for(int i = 0;i<retlen;i++){
        printf("%d %d\n",arrans[i][0],arrans[i][1]);
    }
    //for(int i = 0;i<(len/2+1);i++)
    for(int i = 0;i<(len/2+1);i++)
        free(arrans[i]);
    free(arrans);


    int **arrans2 = findpair_brute_force(nums,len,target,&retlen);
    for(int i = 0;i<retlen;i++){
        printf("%d %d\n",arrans2[i][0],arrans2[i][1]);
    }
    //for(int i = 0;i<(len/2+1);i++)
    for(int i = 0;i<(len/2+1);i++)
        free(arrans2[i]);
    free(arrans2);


    return 0;
}
