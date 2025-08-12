/*


Split a linked list into two lists where each list contains alternating elements from it

Given a linked list of integers, split it into two lists containing alternating elements from the original list.

For example, if the original list is {1, 2, 3, 4, 5}, then one sublist should be {1, 3, 5} and the other should be {2, 4}. 
The elements in the output lists may be in any order. i.e., the sublists can be {5, 3, 1} and {4, 2} for input list {1, 2, 3, 4, 5}.



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

typedef struct node_tag{
    int val;
    struct node_tag* next;
}node_t,*pnode_t;

pnode_t create_node(int val)
{
    pnode_t n = (pnode_t) malloc(sizeof(struct node_tag));
    n->val = val;
    n->next = NULL;
    return n;
}

void push(pnode_t *head,int val)
{
    pnode_t n = create_node(val);
    n->next = *head;
    *head = n;
}

void printlist(pnode_t head)
{
    pnode_t h = head;
    while(h){
        printf("%d->",h->val);
        h=h->next;
    }
    printf("NULL\n");
}

void freelist(pnode_t *head)
{
    pnode_t h =*head;
    while(h){
        pnode_t tmp = h;
        h = h->next;
        free(tmp);
    }
    *head = NULL;
}

void move_node(pnode_t *pdest, pnode_t *psrc)
{
    if(*psrc == NULL)
        return;
    pnode_t newnode = *psrc;
    *psrc = (*psrc)->next;
    newnode->next = *pdest;
    *pdest = newnode;
}


void alternat_split(pnode_t srchead,pnode_t *ahead, pnode_t *bhead)
{
    pnode_t pa = NULL;
    pnode_t pb = NULL;
    pnode_t psrc = srchead;

    while(psrc){
        move_node(&pa,&psrc);
        if(psrc!=NULL){
            move_node(&pb,&psrc);
        }
    }
    *ahead = pa;
    *bhead = pb;
}


int main(int argc, char** argv)
{
    int keys[] = { 1, 2, 3, 4, 5, 6, 7 };
    int len = sizeof(keys)/sizeof(keys[0]);
    pnode_t phead = NULL;
    for(int i = 0;i<len;i++)
        push(&phead,keys[i]);


    printlist(phead);
    pnode_t psa = NULL;
    pnode_t psb = NULL;
    alternat_split(phead,&psa,&psb);
    printlist(psa);
    printlist(psb);
    freelist(&psa);
    freelist(&psb);
    //freelist(&phead);

    return 0;
}
