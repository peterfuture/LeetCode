
// Source : https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Author : Peter-s

/**********************************************************************************
*
* Given a linked list, remove the nth node from the end of list and return its head.
*
* For example,
*
*   Given linked list: 1->2->3->4->5, and n = 2.
*
*   After removing the second node from the end, the linked list becomes 1->2->3->5.
* Note:
* Given n will always be valid.
* Try to do this in one pass.
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


struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *n_pre = head;
    struct ListNode *cur = head;

    int count = 1;
    while(cur->next) {
        cur = cur->next;
        count++;
    }
    cur = head;
    // remove first
    if(count < n)
        return head;
    if(count == n)
        return head->next;

    // skip to N node
    while(n-- > 0 && cur != NULL) cur = cur->next;
    if(!cur) return head;
    while(cur->next) {
        n_pre = n_pre->next;
        cur = cur->next;
    }
    // remove N
    struct ListNode *nth = n_pre->next;
    n_pre->next = nth->next;
    return head;
}

int main(int argc, char **argv)
{
    struct ListNode A = {1, NULL};
    struct ListNode B = {2, NULL};
    struct ListNode C = {3, NULL};
    A.next = &B;
    B.next = &C;

    removeNthFromEnd(&A, 1);

    return 0;
}