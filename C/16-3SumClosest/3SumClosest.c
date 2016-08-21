// Source : https://leetcode.com/problems/3sum-closest/
// Author : Peter-s

/**********************************************************************************
*
* Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
*
*    For example, given array S = {-1 2 1 -4}, and target = 1.
*
*    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
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

int threeSumClosest(int* A, int n, int target) {
    
    int i=0,j=0,k=0;
    bubblesort(A,n);


    int min = A[0]+A[1]+A[2];
    int max = A[n-1]+A[n-2]+A[n-3];
    if(min >= target)
        return min;
    if(max <= target)
        return max;

    // Find Start Pos
    int sum = A[0] + A[1] +A[n-1];
    while(sum < target && i< n-2) {
        i++;
        sum = A[i] + A[i+1] +A[n-1];
    }
    if(i > 0)
        i--;

    printf("max:%d min:%d \n", max,min);

    for(;i<n-2;i++) {
        for(j=i+1;j<n-1;j++) {
            for(k=j+1;k<n;k++) {
                sum=A[i] + A[j] + A[k];
                //printf("i:%d j:%d k:%d max:%d min:%d sum:%d\n", i, j, k, max,min,sum);
                if(sum == target) {
                    return target;
                }
                if(sum < target && sum > min)
                    min = sum;
                if(sum > target) {
                    if(sum < max)
                        max = sum;
                    break;
                }
            }
        }      
    }
    //printf("max:%d min:%d \n", max,min);
    if(max+min >  target*2)
        return min;
    return max;
}

#define TEST(p,q,r) printf("input%d output:%d \n", r, threeSumClosest(p,q,r));

int main(int argc, char **argv)
{
    #if 0
    int A[] = {43,75,-90,47,-49,72,17,-31,-68,-22,-21,-30,65,88,-75,23,97,-61,53,87,-3,33,20,51,-79,43,80,-9,34,-89,-7,93,43,55,-94,29,-32,-49,25,72,-6,35,53,63,6,-62,-96,-83,-73,66,-11,96,-90,-27,78,-51,79,35,-63,85,-82,-15,100,-82,1,-4,-41,-21,11,12,12,72,-82,-22,37,47,-18,61,60,55,22,-6,26,-60,-42,-92,68,45,-1,-26,5,-56,-1,73,92,-55,-20,-43,-56,-15,7,52,35,-90,63,41,-55,-58,46,-84,-92,17,-66,-23,96,-19,-44,77,67,-47,-48,99,51,-25,19,0,-13,-88,-10,-67,14,7,89,-69,-83,86,-70,-66,-38,-50,66,0,-67,-91,-65,83,42,70,-6,52,-21,-86,-87,-44,8,49,-76,86,-3,87,-32,81,-58,37,-55,19,-26,66,-89,-70,-69,37,0,19,-65,38,7,3,1,-96,96,-65,-52,66,5,-3,-87,-16,-96,57,-74,91,46,-79,0,-69,55,49,-96,80,83,73,56,22,58,-44,-40,-45,95,99,-97,-22,-33,-92,-51,62,20,70,90};
    #endif
    int A[] = {1,2,4,8,16,32,64,128};
    TEST(A, sizeof(A)/sizeof(int), 82);
    return 0;
}