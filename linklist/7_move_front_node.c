/*


Split nodes of a linked list into the front and back halves

Given a linked list, split it into two sublists – one for the front half and one for the back half. 
If the total number of elements in the list is odd, the extra element should go in the front list.

For example, list {2, 3, 5, 7, 11} should yield the two lists {2, 3, 5} and {7, 11}.


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
    int data;
    struct node_tag* next;
}node_t,*pnode_t;

void printlist(pnode_t head)
{
    while(head){
        printf("%d->",head->data);
        head = head->next;
    }
    printf("NULL\n");
}

pnode_t create_node(int data)
{
    pnode_t n =(pnode_t)malloc(sizeof(struct node_tag));
    n->data = data;
    n->next = NULL;
    return n;
}

void push(pnode_t *head,int data)
{
    pnode_t n = create_node(data);
    n->next = *head;
    *head = n;
}

void move_node(pnode_t *first,pnode_t *second)
{
    //pnode_t first_head = *first;
    //pnode_t sec_head = *second;
    if(*second == NULL)
        return ;
    pnode_t sec_node = *second;
    (*second) = (*second)->next;
    sec_node->next = *first;
    *first = sec_node;
}


void freelist(pnode_t *head)
{
    pnode_t cur = *head;
    while(cur){
        pnode_t tmp = cur;
        cur=cur->next;
        free(tmp);
    }
    *head = NULL;
}


int main(int argc, char** argv)
{
    int keys[] = { 1, 2, 3 };
    int n = sizeof(keys)/sizeof(keys[0]);
 
    // construct the first linked list
    pnode_t a = NULL;
    for (int i = n-1; i >= 0; i--) {
        push(&a, keys[i]);
    }
 
    // construct the second linked list
    pnode_t b = NULL;
    for (int i = 0; i < n; i++) {
        push(&b, 2*keys[i]);
    }   
    printlist(a);
    printlist(b);
    move_node(&a,&b);
    printlist(a);
    printlist(b);
    freelist(&a);
    freelist(&b);
    return 0;
}
