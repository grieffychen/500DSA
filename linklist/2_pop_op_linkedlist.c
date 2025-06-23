/*


Pop operation in a linked list – C, Java, and Python

Write a pop() function that is the inverse of push(). 
The pop() function takes a non-empty list, deletes the head node, and returns the head node’s data.

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

typedef struct node_t{
    int data;
    struct node_t *next;
}node,*pnode;

void printlist(pnode head)
{
    while(head){
        printf("%d->",head->data);
        head=head->next;
    }
    printf("NULL\n");
}

pnode create_node(int data)
{
    pnode n =(pnode)malloc(sizeof(struct node_t));
    n->data = data;
    n->next = NULL;
    return n;
}

void push(pnode *head,int data)
{
    pnode n = create_node(data);
    if(*head ==NULL){
        *head = n;
        return;
    }else{
        n->next = *head;
        *head = n;
        return;
    }
}

int pop(pnode *head)
{
    pnode cur = *head;
    int pval = cur->data;
    *head = cur->next;
    if(cur)
        free(cur);
    return pval;
}

void deletelist(pnode *head)
{
    pnode cur = *head;
    while(cur){
        pnode tmp = cur;
        cur=cur->next;
        free(tmp);
    }
    *head = NULL;
}

int main(int argc, char** argv)
{
    int keys[] = {1, 2, 3, 4, 5};
    int n = sizeof(keys)/sizeof(keys[0]);
    pnode phead = NULL;
    for(int i = 0;i<n;i++)
        push(&phead,keys[i]);
    printlist(phead);
    printf("pop=%d\n",pop(&phead));
    printf("pop=%d\n",pop(&phead));
    printlist(phead);
    deletelist(&phead);
    return 0;
}
