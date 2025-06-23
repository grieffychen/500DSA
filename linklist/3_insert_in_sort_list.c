/*


Insert a node to its correct sorted position in a sorted linked list

Given a sorted list in increasing order and a single node, insert the node into the list’s correct sorted position. 
The function should take an existing node and rearranges pointers to insert it into the list.

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
        head=head->next;
    }
    printf("NULL\n");
}

pnode_t create_node(int data)
{
    pnode_t n = (pnode_t) malloc(sizeof(struct node_tag));
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

void insert_in_sorted_list(pnode_t *head,int data)
{
    pnode_t n  = create_node(data);
    if((*head == NULL) ||(n->data<(*head)->data)){
        n->next=*head;
        *head = n;
        return;
    }
    pnode_t cur = *head;

    while((cur->next!=NULL)&&(cur->next->data<n->data)){
        cur=cur->next;
    }
    n->next = cur->next;
    cur->next = n;
}

void insert_in_sorted_list2(pnode_t *head,int data)
{
    pnode_t n  = create_node(data);
    if((*head == NULL) ||(n->data<(*head)->data)){
        n->next=*head;
        *head = n;
        return;
    }
    pnode_t cur = *head;
    pnode_t pre = NULL;

    while(cur){
        if(n->data<cur->data)
            break;
        pre = cur;
        cur=cur->next;
    }
    pre->next = n;
    n->next = cur;

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
    int keys[] = {2, 4, 6, 8};
    int n = sizeof(keys)/sizeof(keys[0]);
    pnode_t head = NULL;
    // construct a linked list
    for (int i = n-1; i >= 0; i--) {
        push(&head, keys[i]);
    }
    printlist(head);
    insert_in_sorted_list(&head,5);
    insert_in_sorted_list(&head,9);
    insert_in_sorted_list(&head,1);
    printlist(head);
    insert_in_sorted_list2(&head,3);
    insert_in_sorted_list2(&head,10);
    insert_in_sorted_list2(&head,0);  
    printlist(head);  
    freelist(&head);
    return 0;
}
