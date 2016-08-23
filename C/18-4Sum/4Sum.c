
// Source : https://leetcode.com/problems/4sum/
// Author : Peter-s

/**********************************************************************************
*
* Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
*
* Note: The solution set must not contain duplicate quadruplets.
*
* For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
*
* A solution set is:
* [
*  [-1,  0, 0, 1],
*  [-2, -1, 1, 2],
*  [-2,  0, 0, 2]
* ]
* Subscribe to see which companies asked this question
*
**********************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int bubblesort(int *A, int n)
{
    int i=0,j=0;
    for(i=0;i<n;i++) {
        for(j=0;j<n-1;j++) {
            if(A[i] < A[j]) {
                A[i]=A[i]+A[j];             
                A[j]=A[i]-A[j];;
                A[i]=A[i]-A[j];
            }
        }
    }
    return 0;
}

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** fourSum(int* A, int n, int target, int* returnSize) {

    int i=0,j=0,k=0,l=0;
    bubblesort(A,n);

    int **result = NULL;
    int num=0;

    // Find Start Pos
    int sum = A[0] + A[1] + A[2] +A[3];
    while(sum < target && i< n-3) {
        i++;
        sum = A[i] + A[n-3] + A[n-2] + A[n-1];
    }
    if(i > 0)
        i--;

    sum = A[0] + A[1] + A[2] +A[3];
    int i_max = 0;
    while(sum <= target && i< n-3) {
        i_max++;
        sum = A[i_max] + A[i_max+1] + A[i_max+2] +A[i_max+3];
    }

    for(;i<i_max;i++) {
        if(i>0 && A[i] == A[i-1])
            continue;
        for(j=i+1;j<n;j++) {
            if(j>i+1 && A[j] == A[j-1])
                continue;
            for(k=j+1;k<n;k++) {
                for(l=k+1;l<n;l++) {
                    // Found one
                    if(A[i] + A[j] + A[k] + A[l] == target) {
                        // skip repeat one
                        if(num > 0 && A[i] == result[num-1][0] && A[j] == result[num-1][1] && A[k] == result[num-1][2])
                            continue;
                        int *tmp = malloc(4);
                        tmp[0]=A[i];
                        tmp[1]=A[j];
                        tmp[2]=A[k];
                        tmp[3]=A[l];
                        num++;
                        result = realloc(result, num*sizeof(int *));
                        result[num-1] = tmp; 
                        //printf("found one: %d %d %d %d num:%d\n", A[i], A[j], A[k], A[l], num);
                    }
                    if(A[i] + A[j] + A[k] + A[l] > target)
                        break;
                }
            }
        }
            
    }

    // construct result
    *returnSize = num;
    return result;
}

int main(int argc, char **argv)
{
    //int A[] = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    //int A[] = {-4,-3,-2,-1,0,0,1,2,3,4};
    int A[]= {1,-2,-5,-4,-3,3,3,5};
    int ret = 0;
    fourSum(A, sizeof(A)/sizeof(int), -11, &ret);
    return 0;
}