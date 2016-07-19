// Source : https://leetcode.com/problems/two-sum/
// Author : Peter-s

/**********************************************************************************
*
* Given an array of integers, return indices of the two numbers such that they add up to a specific target.
* You may assume that each input would have exactly one solution.
*
* Example:
* Given nums = [2, 7, 11, 15], target = 9,
*
* Because nums[0] + nums[1] = 2 + 7 = 9,
* return [0, 1].
*
**********************************************************************************/

#include <stdio.h>

struct item {
    int value;
    int pos;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target)
{
    // condition check
    if (numsSize < 2) {
        return NULL;
    }

    int *result = (int *)malloc(2);

    // bubble sort
    struct item numitems[numsSize];
    int i = 0, j = 0;
    int sorted = 0;
    int value;
    for (i = 0; i < numsSize; i++) {
        //if(nums[i] > target)
        //    continue;
        if (sorted == 0) {
            numitems[sorted].value = nums[i];
            numitems[sorted].pos = i;
            sorted++;
            continue;
        }
        j = sorted;
        while (j >= 0) {
            if (j == 0 || numitems[j - 1].value < nums[i]) {
                numitems[j].value = nums[i];
                numitems[j].pos = i;
                sorted++;
                break;
            }

            numitems[j].value = numitems[j - 1].value;
            numitems[j].pos = numitems[j - 1].pos;
            j--;
        }
    }
    j = sorted - 1;
    while (j >= 0) {
        printf("item: [value:%d pos:%d] \n", numitems[j].value, numitems[j].pos);
        j--;
    }

    // check sum
    i = 0;
    j = sorted - 1;
    while (j >= 1) {
        while (i < j) {
            if (numitems[j].value + numitems[i].value == target) {
                // find result
                result[0] = numitems[i].pos;
                result[1] = numitems[j].pos;
                printf("Found [%d %d]\n", result[0], result[1]);
                return result;
            }
            if (numitems[j].value + numitems[i].value > target) {
                break;
            }

            if (numitems[j].value + numitems[i].value < target) {
                i++;
            }
        }
        j--;
        i = 0;
    }
    printf("Not Found\n");
    return NULL;

}

int main(int argc, char const *argv[])
{
    /* code */
    //int nums[] = {2, 7, 11, 15};
    int nums[] = { -3, 4, 3, 90};
    twoSum(nums, 4, 0);
    return 0;
}