// Source : https://leetcode.com/problems/swap-nodes-in-pairs/
// Author : Peter-s

/**********************************************************************************
*
* Given a linked list, swap every two adjacent nodes and return its head.
*
* For example,
* Given 1->2->3->4, you should return the list as 2->1->4->3.
*
* Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*
**********************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseKGroup(struct ListNode* head, int k) {

    struct ListNode *swap[k];
    struct ListNode *result = NULL;
    struct ListNode *next = head;
    struct ListNode *mid = NULL;
    // Handle K Node Once
    int i=0;
    while(head) {
        memset(swap, 0, sizeof(swap));
        for(i=0;i<k;i++) {
            if(next == NULL) break;
            swap[i] = next;
            next = next->next;
            printf("Handle %d \n", swap[i]->val);
        }

        if(!swap[k-1]) break;
        if(!result) result = swap[k-1];
        if(mid) mid->next = swap[k-1]; 
        for(i=k-1; i>0; i--) {
            swap[i]->next = swap[i-1];
        }
        mid = swap[0];
        mid->next=NULL;
    }

    if(mid && swap[0]) mid->next = swap[0];

    if(!result) return head;
    return result; 
}

struct ListNode* swapPairs(struct ListNode* head) {
    return reverseKGroup(head, 2);
}

struct ListNode *createList(int A[], int n)
{
    struct ListNode *list = NULL;
    struct ListNode *node = malloc(sizeof(struct ListNode));
    node->val = A[0];
    list = node;
    int i;
    for(i=1;i<n;i++) {
        struct ListNode *n = malloc(sizeof(struct ListNode));
        n->val = A[i];
        n->next = NULL;
        node->next = n;
        node = n;
    }

    return list;
}

int main(int argc, char **argv)
{

    int A[] = {1,3,5,7,9};
    struct ListNode *la = createList(A, sizeof(A)/sizeof(int));
    struct ListNode *result = swapPairs(la);
    return 0;
}


