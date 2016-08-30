// Source : https://leetcode.com/problems/merge-k-sorted-lists/
// Author : Peter-s

/**********************************************************************************
*
* Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
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

struct ListNode *getNode(struct ListNode **lists, int listsSize)
{
    int n = -1;
    int i = 0;
    for(i=0; i<listsSize;i++){
        if(lists[i] == NULL)
            continue;
        if(n<0) {
            n=i;
            continue;
        }
        if(lists[n]->val > lists[i]->val)
            n = i;      
    }

    if(n >= 0) {

        struct ListNode *node = lists[n];
        lists[n] = node->next;
        return node;
    }

    return NULL;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if(!l1) return l2;
    if(!l2) return l1;

    struct ListNode *ptr=NULL;
    struct ListNode *result=NULL;

    while(l1 && l2) {
        if(l1->val > l2->val) {
            if(ptr)
                ptr->next = l2;
            ptr = l2;
            l2 = l2->next;
        } else {
            if(ptr)
                ptr->next = l1;
            ptr = l1;
            l1 = l1->next;
        }

        if(!result)
            result = ptr;
    }

    ptr->next = l1?l1:l2;
    return result;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    
#if 0 // Method1
    struct ListNode *result = getNode(lists, listsSize);
    if(!result) return result;

    struct ListNode *cur = result;
    struct ListNode *next = getNode(lists, listsSize);
    while(next) {
        cur->next = next;
        cur = next;
        next->next = NULL;
        next = getNode(lists, listsSize);
    }
#endif

#if 1 // Method2
    struct ListNode *result = lists[0];
    int i=1;
    for(i=1;i<listsSize;i++) {
        result = mergeTwoLists(result, lists[i]);
    }
#endif
    return result;
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
    int B[] = {2,4,6,8,10};

    struct ListNode *la = createList(A, sizeof(A)/sizeof(int));
    struct ListNode *lb = createList(B, sizeof(B)/sizeof(int));

    struct ListNode *k[2];
    k[0] = la;
    k[1] = lb;

    struct ListNode *result = mergeKLists(k,2);

    while(result) {
        printf("%d ", result->val);
        result = result->next;
    }
    printf("\n");

    return 0;
}
