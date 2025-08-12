/*


Construct a linked list by merging alternate nodes of two given lists

Given two linked lists, merge their nodes to make one list, taking nodes alternately between the two lists. 
If either list runs out, all the nodes should be taken from the other list.

For example, merging lists {1, 2, 3} and {7, 13, 1} should yield {1, 7, 2, 13, 3, 1}.

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

pnode_t create_node(int val)
{
    pnode_t n = (pnode_t) malloc(sizeof(struct node_tag));
    n->data = val;
    n->next = NULL;
}

void push(pnode_t *head,int val)
{
    pnode_t n = create_node(val);
    n->next = *head;
    *head = n;
}

void printlist(pnode_t head)
{
    pnode_t cur = head;
    while(cur){
        printf("%d->",cur->data);
        cur=cur->next;
    }
    printf("NULL\n");
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

void alt_merge_list(pnode_t *tarhead, pnode_t src1,pnode_t src2)
{
    node_t dummy;
    pnode_t tail = &dummy;
    dummy.next = NULL;

    while(true){
        if(src1==NULL){
            tail->next = src2;
            break;
        }
        else if(src2 == NULL){
            tail->next = src1;
            break;
        }else{
            tail->next = src1;
            tail = tail->next;
            src1 = src1->next;
            tail->next = src2;
            tail = tail->next;
            src2=src2->next;
        }
    }
    *tarhead = dummy.next;
}


int main(int argc, char** argv)
{
    int key1[] = {1,3,5,7,9};
    int key2[] = {2,4,6,8};
    int l1 = sizeof(key1)/sizeof(key1[0]);
    int l2 = sizeof(key2)/sizeof(key2[0]);
    pnode_t pha = NULL;
    pnode_t phb = NULL;
    for(int i = l1-1;i>=0;i--)
        push(&pha,key1[i]);
    for(int i = l2-1;i>=0;i--)
        push(&phb,key2[i]);

    printlist(pha);
    printlist(phb);
    pnode_t mhlist = NULL;
    alt_merge_list(&mhlist,pha,phb);
    printlist(mhlist);
    //freelist(&pha);
    //freelist(&phb);
    freelist(&mhlist);
    return 0;
}
