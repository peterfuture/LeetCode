// Source : https://leetcode.com/problems/add-two-numbers/
// Author : Peter-s

/**********************************************************************************
*
* You are given two linked lists representing two non-negative numbers. 
* The digits are stored in reverse order and each of their nodes contain a single digit. 
* Add the two numbers and return it as a linked list.
* Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
* Output: 7 -> 0 -> 8
*
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
};

int64_t convertToInt(struct ListNode* l1)
{
    int64_t value = 0;
    int ratio = 1;
    while(l1 != NULL) {
        value += (int64_t)l1->val * ratio;
        l1 = l1->next;
        ratio *= 10;
    }
    return value;
}

struct ListNode *convertToList(int64_t value)
{
    struct ListNode *result = NULL;
    struct ListNode *cursor_node = NULL;
    struct ListNode *node = NULL;
    if(value < 10) {
        node = malloc(sizeof(struct ListNode));
        node->val = value;
        node->next = NULL;
        return node;
    }

    int count = 0;
    while(value > 0)
    {
        node = malloc(sizeof(struct ListNode));
        node->val = value % 10;
        node->next = NULL;
        value /= 10;
        count++;
        if(result == NULL) {
            result = cursor_node = node;
            continue;
        }
        cursor_node->next = node;
        cursor_node = node;
    }

    return result;
}

#ifdef VERSION1
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    return convertToList(convertToInt(l1) + convertToInt(l2));
}
#else
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode* cursor1 = l1;
    struct ListNode* cursor2 = l2;

    int overflow = 0;
    int tmp = 0;
    int use_op = 1;

    while(cursor1 || cursor2)
    {
        if(cursor1 && cursor2){
            tmp = cursor1->val + cursor2->val + overflow;
            overflow = (tmp >= 10)?1:0;
            cursor1->val = cursor2->val = tmp%10;
            // handle both next null case
            if(cursor1->next == NULL && cursor2->next == NULL && overflow == 1) {
                cursor1->next = malloc(sizeof(struct ListNode));
                cursor1->next->val = 1;
                cursor1->next->next = NULL;
                overflow = 0;
                break;
            }

            cursor1 = cursor1->next;
            cursor2 = cursor2->next;
            continue;
        }

        if(cursor1 && cursor2 == NULL) {
            use_op = 1;
            tmp = cursor1->val + overflow;
            overflow = (tmp >= 10)?1:0;
            cursor1->val = tmp%10;
            if(overflow == 0)
                break;
            if(cursor1->next == NULL) {
                // add last node
                cursor1->next = malloc(sizeof(struct ListNode));
                cursor1->next->val = 1;
                cursor1->next->next = NULL;
                overflow = 0;
                break;
            }
            cursor1 = cursor1->next;
            continue;
        }

        if(cursor1 == NULL && cursor2) {
            use_op = 2;
            tmp = cursor2->val + overflow;
            overflow = (tmp >= 10)?1:0;
            cursor2->val = tmp%10;
            if(overflow == 0)
                break;
            if(cursor2->next == NULL) {
                // add last node
                cursor2->next = malloc(sizeof(struct ListNode));
                cursor2->next->val = 1;
                cursor2->next->next = NULL;
                overflow = 0;
                break;
            }
            cursor2 = cursor2->next;
            continue;
        }
    }

    if(use_op == 1) 
        return l1;
    else
        return l2;
}

#endif

int main(int argc, char const *argv[])
{
    int64_t op1 = 99;
    int64_t op2 = 9;
    struct ListNode *l1 = convertToList(op1);
    struct ListNode *l2 = convertToList(op2);
    struct ListNode *result = addTwoNumbers(l1, l2);
    while(result){
        printf("%d", result->val);
        result = result->next;
    }
    printf("\n");
    return 0;
}