
// Source : https://leetcode.com/problems/merge-two-sorted-lists/
// Author : Peter-s

/**********************************************************************************
*
* Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
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

int main(int argc, char **argv)
{
    return 0;
}