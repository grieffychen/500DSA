/*

Clone a Linked List

Write a function that takes a singly linked list and returns a complete copy of that list.

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


struct node{
    int data;
    struct node *next;
};

struct node *create_node(int data)
{
    struct node *n = (struct node*) malloc(sizeof(struct node));
    n->data = data;
    n->next = NULL;
    return n;
}

void printlist(struct node* head)
{
    struct node* cur = head;
    while(cur){
        printf("%d->",cur->data);
        cur=cur->next;
    }
    printf("NULL\n");
}

void insert(struct node **head , int data)
{
    struct node *n = create_node(data);
    if(*head == NULL){
        *head = n;
    }else{
        n->next = *head;
        *head = n;
    }
}

void copylist(struct node **thead, struct node* srchead)
{
    struct node* cur = srchead;
    struct node* tail = NULL;
    while(cur){
        //insert(thead,cur->data);
        struct node* n = create_node(cur->data);
        if(*thead == NULL){
            *thead = n;
            tail = n;

        }else{
            tail->next = n;
            tail = n;
        }
        cur=cur->next;
    }
}

void freelist(struct node **head)
{
    struct node *cur = *head;
    while(cur){
        struct node *tmp = cur;
        cur=cur->next;
        free(tmp);
    }
    *head = NULL;
}

int main(int argc, char** argv)
{
    struct node *oldhead = NULL;
    insert(&oldhead,1);
    insert(&oldhead,2);
    insert(&oldhead,3);
    insert(&oldhead,4);
    insert(&oldhead,5);

    printlist(oldhead);
    struct node *newhead = NULL;
    copylist(&newhead,oldhead);
    printlist(newhead);
    freelist(&oldhead);
    freelist(&newhead);
    return 0;
}
