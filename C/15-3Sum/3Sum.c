
// Source : https://leetcode.com/problems/3sum/
// Author : Peter-s

/**********************************************************************************
*
* Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
*
* Note: The solution set must not contain duplicate triplets.
*
* For example, given array S = [-1, 0, 1, 2, -1, -4],
*
* A solution set is:
* [
*  [-1, 0, 1],
*  [-1, -1, 2]
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
int** threeSum(int* A, int n, int* returnSize) {

    int i=0,j=0,k=0;
    bubblesort(A,n);

    int **result = NULL;
    int num=0;

    for(i=0;A[i]<=0;i++) {
        if(i>0 && A[i] == A[i-1])
            continue;
        for(j=i+1;j<n;j++) {
            if(A[i] + A[j] > 0)
                break;
            for(k=j+1;k<n;k++) {
                // Found one
                if(A[i] + A[j] + A[k] == 0) {
                    // skip repeat one
                    if(num > 0 && A[i] == result[num-1][0] && A[j] == result[num-1][1])
                        continue;
                    int *tmp = malloc(3);
                    tmp[0]=A[i];
                    tmp[1]=A[j];
                    tmp[2]=A[k];
                    num++;
                    result = realloc(result, num*sizeof(int *));
                    result[num-1] = tmp; 
                    //printf("found one: %d %d %d num:%d\n", A[i], A[j], A[k], num);
                }
                if(A[i] + A[j] + A[k] > 0)
                    break;
            }
        }
            
    }

    // construct result
    *returnSize = num;
    return result;
}

int main(int argc, char **argv)
{
    int A[] = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    int ret = 0;
    threeSum(A,15,&ret);
    return 0;
}