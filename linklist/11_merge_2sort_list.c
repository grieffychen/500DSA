/*


Merge two sorted linked lists into one

Write a function that takes two lists, each of which is sorted in increasing order, 
and merges the two into a single list in increasing order, and returns it.

For example, consider lists a = {1, 3, 5, 7} and b = {2, 4, 6}. Merging them should yield the list {1, 2, 3, 4, 5, 6, 7}.
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

void push(pnode_t *phead,int val)
{
    pnode_t n = create_node(val);
    n->next = *phead;
    *phead = n;
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

void freelist(pnode_t *phead)
{
    pnode_t cur = *phead;
    while(cur){
        pnode_t tmp = cur;
        cur=cur->next;
        free(tmp);
    }
    *phead = NULL;
}

void sortMerge(pnode_t *tarlist, pnode_t list1, pnode_t list2)
{
    node_t dummy;
    dummy.next = NULL;
    pnode_t tail = &dummy;

    while(true){

        if(list1 == NULL){
            tail->next =list2;
            break;
        }else if(list2 == NULL){
            tail->next = list1;
            break;
        }else{
            if(list1->data <= list2->data){
                tail->next =list1;
                list1=list1->next;

            }else{
                tail->next = list2;
                list2=list2->next;
            }
            tail=tail->next;
        }
    }
    *tarlist = dummy.next;
}

int main(int argc, char** argv)
{
    int key1[] = {1,3,5,7,9};
    int key2[] = {2,4,6,8};
    int l1 = sizeof(key1)/sizeof(key1[0]);
    int l2 = sizeof(key2)/sizeof(key2[0]);
    pnode_t plist1 = NULL;
    pnode_t plist2 = NULL;
    for(int i =l1-1;i>=0;i--)
        push(&plist1,key1[i]);

    for(int i =l2-1;i>=0;i--)
        push(&plist2,key2[i]);

    printlist(plist1);
    printlist(plist2);

    pnode_t destlist = NULL;
    sortMerge(&destlist,plist1,plist2);
    printlist(destlist);

    freelist(&destlist);
    //freelist(&plist1);
    //freelist(&plist2);
    return 0;
}
