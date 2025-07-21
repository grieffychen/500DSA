/*


Remove duplicates from a sorted linked list

Given a linked list sorted in increasing order, write a function that removes duplicate nodes from it by traversing the list only once.

For example, the list {1, 2, 2, 2, 3, 4, 4, 5} should be converted into the list {1, 2, 3, 4, 5}.

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

void remove_duplicate(pnode_t *head)
{
    pnode_t cur = *head;
    pnode_t pre = NULL;

    while(cur){
        if(!pre){
            pre = cur;
            cur=cur->next;
            continue;
        }

        if(cur->data == pre->data){
            pnode_t tmp = cur;
            pre->next = cur->next;
            cur=cur->next;
            free(tmp);
        }else{
            pre = cur;
            cur = cur->next;
        }
    }
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
    int keys[] = {1, 2, 2, 2, 3, 4, 4, 5};
    int n = sizeof(keys)/sizeof(keys[0]);
    pnode_t phead = NULL;
    for (int i = n-1;i>=0;i--){
        push(&phead,keys[i]);
    }
    printlist(phead);
    remove_duplicate(&phead);
    printlist(phead);
    freelist(&phead);
    return 0;
}
